#ifndef HEADER_NVCGO_CTYPES_H
#define HEADER_NVCGO_CTYPES_H

#include <sys/types.h>

#include <stdbool.h>
#include <stdint.h>

struct device_rule {
        bool allow;
        const char *type;
        const char *access;
        dev_t major;
        dev_t minor;
};

#endif /* HEADER_NVCGO_CTYPES_H */
