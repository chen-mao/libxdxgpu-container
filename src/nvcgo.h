#ifndef HEADER_NVCGO_H
#define HEADER_NVCGO_H

#include <nvcgo/nvcgo.h>

#include "error.h"
#include "rpc.h"

struct libnvcgo {
        __typeof__(GetDeviceCGroupVersion)   *GetDeviceCGroupVersion;
        __typeof__(GetDeviceCGroupMountPath) *GetDeviceCGroupMountPath;
        __typeof__(GetDeviceCGroupRootPath)  *GetDeviceCGroupRootPath;
        __typeof__(AddDeviceRules)           *AddDeviceRules;
};

struct nvcgo {
        struct rpc rpc;
        struct libnvcgo api;
};

int nvcgo_init(struct error *);
int nvcgo_shutdown(struct error *);
struct nvcgo *nvcgo_get_context(void);

#endif /* HEADER_NVCGO_H */
