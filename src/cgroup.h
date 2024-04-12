#ifndef HEADER_CGROUP_H
#define HEADER_CGROUP_H

#include <sys/types.h>

#include "error.h"
#include "nvc_internal.h"

int  get_device_cgroup_version(struct error *, const struct nvc_container *);
char *find_device_cgroup_path(struct error *, const struct nvc_container *);
int  setup_device_cgroup(struct error *, const struct nvc_container *, dev_t);

#endif /* HEADER_CGROUP_H */
