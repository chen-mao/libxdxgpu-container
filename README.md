# libxdxct-container

This repository provides a library and a simple CLI utility to automatically configure GNU/Linux containers leveraging XDXCT hardware.\
The implementation relies on kernel primitives and is designed to be agnostic of the container runtime.

## Installing the library
### From packages

Install the packages:
```bash
libxdxct-container1
libxdxct-container-tools
```

### From sources
With Docker:
```bash
# Generate docker images for a supported <os><version>
make {ubuntu18.04, ubuntu16.04, debian10, debian9, centos7, amazonlinux2, opensuse-leap15.1}

# Or generate docker images for all supported distributions in the dist/ directory
make docker
````

The resulting images have the name `xdxct/libxdxct-container/<os>:<version>`

Without Docker:
```bash
make install

# Alternatively in order to customize the installation paths
DESTDIR=/path/to/root make install prefix=/usr
```

## Using the library
### Container runtime example
Refer to the [xdxct-container-runtime].

### Command line example

```bash
# Setup a new set of namespaces
cd $(mktemp -d) && mkdir rootfs
sudo unshare --mount --pid --fork

# Setup a rootfs based on Ubuntu 16.04 inside the new namespaces
curl http://cdimage.ubuntu.com/ubuntu-base/releases/16.04/release/ubuntu-base-16.04.6-base-amd64.tar.gz | tar -C rootfs -xz
useradd -R $(realpath rootfs) -U -u 1000 -s /bin/bash xdxct
mount --bind rootfs rootfs
mount --make-private rootfs
cd rootfs

# Mount standard filesystems
mount -t proc none proc
mount -t sysfs none sys
mount -t tmpfs none tmp
mount -t tmpfs none run

# Isolate the first GPU device along with basic utilities
libxdxct-container --load-kmods configure --ldconfig=@/sbin/ldconfig.real --no-cgroups --utility --device 0 $(pwd)

# Change into the new rootfs
pivot_root . mnt
umount -l mnt
exec chroot --userspec 1000:1000 . env -i bash

# Run xdxsmi from within the container
xdxsmi
```
