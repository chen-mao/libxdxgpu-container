package cgroup

import (
	"bufio"
	"fmt"
	"os"
	"path/filepath"
	"strings"

	"github.com/cilium/ebpf"
	"github.com/cilium/ebpf/asm"
	"golang.org/x/sys/unix"
)

const (
	BpfProgramLicense = "Apache"
)

// GetDeviceCGroupMountPath returns the mount path (and its prefix) for the device cgroup controller associated with pid
func (c *cgroupv2) GetDeviceCGroupMountPath(procRootPath string, pid int) (string, string, error) {
	// Open the pid's mountinfo file in /proc.
	path := fmt.Sprintf(filepath.Join(procRootPath, "proc", "%v", "mountinfo"), pid)
	file, err := os.Open(path)
	if err != nil {
		return "", "", err
	}
	defer file.Close()

	// Create a scanner to loop through the file's contents.
	scanner := bufio.NewScanner(file)
	scanner.Split(bufio.ScanLines)

	// Loop through the file looking for a subsystem of '' (i.e. unified) entry.
	for scanner.Scan() {
		// Split each entry by '[space]'
		parts := strings.Split(scanner.Text(), " ")
		if len(parts) < 5 {
			return "", "", fmt.Errorf("malformed mountinfo entry: %v", scanner.Text())
		}
		// Look for an entry with cgroup2 as the mount type.
		if parts[len(parts)-3] != "cgroup2" {
			continue
		}
		// Make sure the mount prefix is not a relative path.
		if strings.HasPrefix(parts[3], "/..") {
			return "", "", fmt.Errorf("relative path in mount prefix: %v", parts[3])
		}
		// Return the 3rd element as the prefix of the mount point for
		// the devices cgroup and the 4th element as the mount point of
		// the devices cgroup itself.
		return parts[3], parts[4], nil
	}

	return "", "", fmt.Errorf("no cgroup2 filesystem in mountinfo file")
}

// GetDeviceCGroupRootPath returns the root path for the device cgroup controller associated with pid
func (c *cgroupv2) GetDeviceCGroupRootPath(procRootPath string, prefix string, pid int) (string, error) {
	// Open the pid's cgroup file in /proc.
	path := fmt.Sprintf(filepath.Join(procRootPath, "proc", "%v", "cgroup"), pid)
	file, err := os.Open(path)
	if err != nil {
		return "", err
	}
	defer file.Close()

	// Create a scanner to loop through the file's contents.
	scanner := bufio.NewScanner(file)
	scanner.Split(bufio.ScanLines)

	// Loop through the file looking for either a '' (i.e. unified) entry.
	for scanner.Scan() {
		// Split each entry by ':'
		parts := strings.SplitN(scanner.Text(), ":", 3)
		if len(parts) != 3 {
			return "", fmt.Errorf("malformed cgroup entry: %v", scanner.Text())
		}
		// Look for the (empty) subsystem in the 1st element.
		if parts[1] != "" {
			continue
		}
		// Return the cgroup root from the 2nd element
		// (with the prefix possibly stripped off).
		if prefix == "/" {
			return parts[2], nil
		}
		return strings.TrimPrefix(parts[2], prefix), nil
	}

	return "", fmt.Errorf("no cgroupv2 entries in file")
}

// AddDeviceRules adds a set of device rules for the device cgroup at cgroupPath
func (c *cgroupv2) AddDeviceRules(cgroupPath string, rules []DeviceRule) error {
	// Open the cgroup path.
	dirFD, err := unix.Open(cgroupPath, unix.O_DIRECTORY|unix.O_RDONLY, 0600)
	if err != nil {
		return fmt.Errorf("unable to open the cgroup path: %v", err)
	}
	defer unix.Close(dirFD)

	// Find any existing eBPF device filter programs attached to this cgroup.
	oldProgs, err := FindAttachedCgroupDeviceFilters(dirFD)
	if err != nil {
		return fmt.Errorf("unable to find any existing device filters attached to the cgroup: %v", err)
	}

	// Generate a new set of eBPF programs by prepending instructions for the
	// new devices to the instructions of each existing program.
	// If no existing programs found, create a new program with just our device filter.
	var newProgs []*ebpf.Program
	if len(oldProgs) == 0 {
		oldInsts := asm.Instructions{asm.Return()}

		newProg, err := generateNewProgram(rules, oldInsts)
		if err != nil {
			return fmt.Errorf("unable to generate new device filter program with no existing programs: %v", err)
		}

		newProgs = append(newProgs, newProg)
	}
	for _, oldProg := range oldProgs {
		oldInfo, err := oldProg.Info()
		if err != nil {
			return fmt.Errorf("unable to get Info() of the original device filters program: %v", err)
		}

		oldInsts, err := oldInfo.Instructions()
		if err != nil {
			return fmt.Errorf("unable to get the instructions of the original device filters program: %v", err)
		}

		newProg, err := generateNewProgram(rules, oldInsts)
		if err != nil {
			return fmt.Errorf("unable to generate new device filter program from existing programs: %v", err)
		}

		newProgs = append(newProgs, newProg)
	}

	// Increase `ulimit -l` limit to avoid BPF_PROG_LOAD error below.
	// This limit is not inherited into the container.
	memlockLimit := &unix.Rlimit{
		Cur: unix.RLIM_INFINITY,
		Max: unix.RLIM_INFINITY,
	}
	_ = unix.Setrlimit(unix.RLIMIT_MEMLOCK, memlockLimit)

	// Replace the set of existing eBPF programs with the new ones.
	// We don't have to worry about atomically replacing each program (i.e. by
	// using BPF_F_REPLACE) because we know that the code here is always run
	// strictly *before* a container begins executing.
	for _, oldProg := range oldProgs {
		err = DetachCgroupDeviceFilter(oldProg, dirFD)
		if err != nil {
			return fmt.Errorf("unable to detach original device filters program: %v", err)
		}
	}
	for _, newProg := range newProgs {
		err = AttachCgroupDeviceFilter(newProg, dirFD)
		if err != nil {
			return fmt.Errorf("unable to attach new device filters program: %v", err)
		}
	}

	return nil
}

func generateNewProgram(rules []DeviceRule, oldInsts asm.Instructions) (*ebpf.Program, error) {
	// Prepend instructions for the new devices to the original set of instructions.
	newInsts, err := PrependDeviceFilter(rules, oldInsts)
	if err != nil {
		return nil, fmt.Errorf("unable to prepend new device filters to the original device filters program: %v", err)
	}

	// Generate new eBPF program for the merged device filter instructions.
	spec := &ebpf.ProgramSpec{
		Type:         ebpf.CGroupDevice,
		Instructions: newInsts,
		License:      BpfProgramLicense,
	}
	newProg, err := ebpf.NewProgram(spec)
	if err != nil {
		return nil, fmt.Errorf("unable to create new device filters program: %v", err)
	}

	return newProg, nil
}
