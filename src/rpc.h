#ifndef HEADER_RPC_H
#define HEADER_RPC_H

#include <sys/types.h>

#include <rpc/rpc.h>

#ifndef WITH_TIRPC
/* Glibc is missing this prototype */
SVCXPRT *svcunixfd_create(int, u_int, u_int);
#endif /* WITH_TIRPC */

#include <stdbool.h>

#pragma GCC diagnostic push
#include "nvc_rpc.h"
#pragma GCC diagnostic pop

#include "error.h"
#include "dxcore.h"

#define SOCK_CLT 0
#define SOCK_SVC 1

struct rpc_prog {
        const char *name;
        unsigned long id;
        unsigned long version;
        void (*dispatch)(struct svc_req *, SVCXPRT *);
};

struct rpc {
        bool initialized;
        int fd[2];
        pid_t pid;
        SVCXPRT *svc;
        CLIENT *clt;
        struct rpc_prog prog;
};

int rpc_init(struct error *, struct rpc *, struct rpc_prog *);
int rpc_shutdown(struct error *, struct rpc *, bool force);

#define call_rpc(err, ctx, res, func, ...) __extension__ ({                                            \
        enum clnt_stat r_;                                                                             \
        struct sigaction osa_, sa_ = {.sa_handler = SIG_IGN};                                          \
                                                                                                       \
        static_assert(sizeof(ptr_t) >= sizeof(intptr_t), "incompatible types");                        \
        sigaction(SIGPIPE, &sa_, &osa_);                                                               \
        if ((r_ = func((ptr_t)ctx, ##__VA_ARGS__, res, (ctx)->clt)) != RPC_SUCCESS)                    \
                error_set_rpc(err, r_, "%s rpc error", (ctx)->prog.name);                               \
        else if ((res)->errcode != 0)                                                                  \
                error_from_xdr(err, res);                                                              \
        sigaction(SIGPIPE, &osa_, NULL);                                                               \
        (r_ == RPC_SUCCESS && (res)->errcode == 0) ? 0 : -1;                                           \
})

#endif /* HEADER_RPC_H */
