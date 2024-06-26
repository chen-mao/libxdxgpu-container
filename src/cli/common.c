#include <sys/sysmacros.h>

#include <inttypes.h>
#include <string.h>

#include "cli.h"
#include "nvml.h"

bool 
matches_pci_format(const char *gpu, char *buf, size_t bufsize) {
        int domainid, busid, deviceid;

        // the path we get may not have leading zeros
        int out = sscanf(gpu, "%x:%02x:%02x.0", &domainid, &busid, &deviceid);
        if (out != 3) {
                return false;
        }
        
        // update to expected format with leading zeros
        snprintf(buf, bufsize, "%08x:%02x:%02x.0", domainid, busid, deviceid);
        return true;
}

static bool
already_present(
    const void *ptr,
    const void *ptrs,
    size_t size)
{
        // Check if a pointer is already an element in a generic pointer array.
        // This function is written generically so it can be reused across an
        // array of pointers to any type.
        for (size_t i = 0; i < size; ++i)
                if (((void**)ptrs)[i] == ptr)
                        return (true);
        return (false);
}

static int
add_gpu_device(
    struct error *err,
    const struct nvc_device *gpu,
    struct devices *devices)
{
        if (!already_present(gpu, devices->gpus, devices->ngpus)) {
                // Make sure we don't go beyond the maximum
                // size of our GPU device array.
                // log_infof("devices->ngpus: %d, devices->max_gpus: %d", devices->ngpus, devices->max_gpus);
                if (devices->ngpus + 1 > devices->max_gpus) {
                        error_setx(err, "exceeds maximum GPU device count");
                        return (-1);
                }
                devices->gpus[devices->ngpus++] = gpu;
        }
        return (0);
}

static int
select_all_gpu_devices(
    struct error *err,
    const struct nvc_device_info *available,
    struct devices *selected)
{
        // Initialize local variables.
        struct error ierr = {0};
        const struct nvc_device *gpu = NULL;

        // Walk through all GPUs and populate 'devices' as appropriate.
        for (size_t i = 0; i < available->ngpus; ++i) {
                gpu = &available->gpus[i];
                if (add_gpu_device(&ierr, gpu, selected) < 0)
                        goto fail;
        }

        return (0);

 fail:
        error_setx(err, "error adding all GPU devices: %s", ierr.msg);
        error_reset(&ierr);
        return (-1);
}

static int
select_all_devices(
    struct error *err,
    const struct nvc_device_info *available,
    struct devices *selected)
{
        if(select_all_gpu_devices(err, available, selected) < 0)
                return (-1);
        // if(select_all_mig_devices(err, available, selected) < 0)
        //         return (-1);
        return (0);
}

static int
select_gpu_device(
    struct error *err,
    char *dev,
    const struct nvc_device_info *available,
    struct nvc_device **gpu,
    struct devices *selected)
{
        // Initialize local variables.
        struct error ierr = {0};
        char *ptr;
        uintmax_t n;

        // Initialize return values.
        *gpu = NULL;

        // Check if dev matches a full GPU UUID.
        for (size_t i = 0; i < available->ngpus; i++) {
                // The matching uuid needs to be stripped of 0x.
                char *gpus_uuid_tmp = dev + 2;  
                printf("available->gpus[i].uuid: %s\n", available->gpus[i].uuid);
                printf("required_gpus__tmp: %s", gpus_uuid_tmp);
                if (strlen(available->gpus[i].uuid) != strlen(gpus_uuid_tmp)) {
                        continue;
                }
                if (! strcasecmp(available->gpus[i].uuid, gpus_uuid_tmp)) {
                        *gpu = &available->gpus[i];
                        goto found;
                }

        }
        // Check if dev matches a PCI bus ID.
        char buf[NVML_DEVICE_PCI_BUS_ID_BUFFER_SIZE + 1];
        if (matches_pci_format(dev, buf, sizeof(buf))) {
                for (size_t i = 0; i < available->ngpus; ++i) {
                        if (!strncasecmp(available->gpus[i].busid, buf, strlen(buf))) {
                                *gpu = &available->gpus[i];
                                goto found;
                        }
                }
        }

        // Check if dev matches a device index.
        n = strtoumax(dev, &ptr, 10);
        if (*ptr == '\0' && n < UINTMAX_MAX && (size_t)n < available->ngpus) {
                *gpu = &available->gpus[n];
                goto found;
        }

        // If no device was found, just return (without an error).
        return (0);

 found:
        if (add_gpu_device(&ierr, *gpu, selected) < 0) {
                error_setx(err, "error adding GPU device: %s", ierr.msg);
                error_reset(&ierr);
                return (-1);
        }
        return (0);
}

int
select_devices(
    struct error *err,
    char *devs,
    const struct nvc_device_info *gpus,
    struct devices *selected)
{
        // Initialize local variables.
        char sep[2] = ",";
        struct error ierr = {0};
        char *dev = NULL;
        struct nvc_device *gpu = NULL;
        // struct nvc_mig_device *mig = NULL;

        log_infof("Function: select_devices, devs: %s", devs);
        // Walk trough the comma separated device string and populate
        // 'selected' devices from it.
        while ((dev = strsep(&devs, sep)) != NULL) {
                // Allow extra commas between device strings.
                if (*dev == '\0')
                        continue;

                // Special case the "all" string to select all devices.
                if (str_case_equal(dev, "all")) {
                        if (select_all_devices(&ierr, gpus, selected) < 0)
                                goto fail;
                        selected->all = true;
                        break;
                }

                // Attempt to select a GPU device from the device string. If it is
                // already present in the array of GPU devices, don't add it again.
                // Always continue to the next 'dev' if one is found.
                if (select_gpu_device(&ierr, dev, gpus, &gpu, selected) < 0)
                        goto fail;
                if (gpu != NULL)
                        continue;


                // If 'dev' has not been captured by the time we get here, it
                // is an error.
                error_setx(&ierr, "unknown device");
                goto fail;
        }

        return (0);

 fail:
        error_setx(err, "%s: %s", dev, ierr.msg);
        error_reset(&ierr);
        return (-1);
}

int
new_devices(struct error *err, const struct nvc_device_info *dev, struct devices *d)
{
        // Allocate space for all of the elements in a 'devices' struct and
        // initialize the memory of the struct itself to 0.
        memset(d, 0, sizeof(*d));
        d->max_gpus = dev->ngpus;
        // d->max_migs = count_mig_devices(dev->gpus, dev->ngpus);
        if ((d->gpus = xcalloc(err, d->max_gpus, sizeof(*d->gpus))) == NULL ||
            (d->migs = xcalloc(err, d->max_migs, sizeof(*d->migs))) == NULL) {
                return (-1);
        }
        return (0);
}

void
free_devices(struct devices *d)
{
        // Free all space allocated for the elements in a 'devices' struct
        // and reinitialize the memory of the struct itself to 0.
        free(d->gpus);
        free(d->migs);
        memset(d, 0, sizeof(*d));
}
