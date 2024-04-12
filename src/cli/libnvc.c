#include <sys/types.h>

#include <assert.h>
#include <dlfcn.h>
#include <err.h>
#include <stdbool.h>
#include <stddef.h>

#include "cli/libnvc.h"

#include "utils.h"

struct libnvc libnvc = {0};

static int load_libnvc_v1(void);

int
load_libnvc(void)
{
        return load_libnvc_v1();
}

static int
load_libnvc_v1(void)
{
        #define load_libnvc_func(func) \
            libnvc.func = nvc_##func

        load_libnvc_func(config_free);
        load_libnvc_func(config_new);
        load_libnvc_func(container_config_free);
        load_libnvc_func(container_config_new);
        load_libnvc_func(container_free);
        load_libnvc_func(container_new);
        load_libnvc_func(context_free);
        load_libnvc_func(context_new);
        load_libnvc_func(device_info_free);
        load_libnvc_func(device_info_new);
        load_libnvc_func(device_mount);
        load_libnvc_func(driver_info_free);
        load_libnvc_func(driver_info_new);
        load_libnvc_func(driver_mount);
        load_libnvc_func(error);
        load_libnvc_func(init);
        load_libnvc_func(ldcache_update);
        load_libnvc_func(shutdown);
        load_libnvc_func(version);
        load_libnvc_func(nvcaps_style);

        return (0);
}
