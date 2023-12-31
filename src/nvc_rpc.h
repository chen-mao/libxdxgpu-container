/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#ifndef _NVC_RPC_H_RPCGEN
#define _NVC_RPC_H_RPCGEN

#include <rpc/rpc.h>

#include <pthread.h>

#ifdef __cplusplus
extern "C" {
#endif

#pragma GCC diagnostic ignored "-Wmissing-prototypes"
#pragma GCC diagnostic ignored "-Wsign-conversion"
#pragma GCC diagnostic ignored "-Wunused-variable"

typedef int64_t ptr_t;

struct driver_init_res {
	int errcode;
	union {
		char *errmsg;
	} driver_init_res_u;
};
typedef struct driver_init_res driver_init_res;

struct driver_shutdown_res {
	int errcode;
	union {
		char *errmsg;
	} driver_shutdown_res_u;
};
typedef struct driver_shutdown_res driver_shutdown_res;

struct driver_get_rm_version_res {
	int errcode;
	union {
		char *vers;
		char *errmsg;
	} driver_get_rm_version_res_u;
};
typedef struct driver_get_rm_version_res driver_get_rm_version_res;

struct driver_cuda_version {
	u_int major;
	u_int minor;
};
typedef struct driver_cuda_version driver_cuda_version;

struct driver_get_cuda_version_res {
	int errcode;
	union {
		driver_cuda_version vers;
		char *errmsg;
	} driver_get_cuda_version_res_u;
};
typedef struct driver_get_cuda_version_res driver_get_cuda_version_res;

struct driver_device_arch {
	u_int major;
	u_int minor;
};
typedef struct driver_device_arch driver_device_arch;

struct driver_get_device_arch_res {
	int errcode;
	union {
		driver_device_arch arch;
		char *errmsg;
	} driver_get_device_arch_res_u;
};
typedef struct driver_get_device_arch_res driver_get_device_arch_res;

struct driver_get_device_count_res {
	int errcode;
	union {
		u_int count;
		char *errmsg;
	} driver_get_device_count_res_u;
};
typedef struct driver_get_device_count_res driver_get_device_count_res;

struct driver_get_device_res {
	int errcode;
	union {
		ptr_t dev;
		char *errmsg;
	} driver_get_device_res_u;
};
typedef struct driver_get_device_res driver_get_device_res;

struct driver_get_device_minor_res {
	int errcode;
	union {
		u_int minor;
		char *errmsg;
	} driver_get_device_minor_res_u;
};
typedef struct driver_get_device_minor_res driver_get_device_minor_res;

struct driver_get_device_busid_res {
	int errcode;
	union {
		char *busid;
		char *errmsg;
	} driver_get_device_busid_res_u;
};
typedef struct driver_get_device_busid_res driver_get_device_busid_res;

struct driver_get_device_uuid_res {
	int errcode;
	union {
		char *uuid;
		char *errmsg;
	} driver_get_device_uuid_res_u;
};
typedef struct driver_get_device_uuid_res driver_get_device_uuid_res;

struct driver_get_device_model_res {
	int errcode;
	union {
		char *model;
		char *errmsg;
	} driver_get_device_model_res_u;
};
typedef struct driver_get_device_model_res driver_get_device_model_res;

struct driver_get_device_brand_res {
	int errcode;
	union {
		char *brand;
		char *errmsg;
	} driver_get_device_brand_res_u;
};
typedef struct driver_get_device_brand_res driver_get_device_brand_res;

struct driver_device_mig_mode {
	int error;
	u_int current;
	u_int pending;
};
typedef struct driver_device_mig_mode driver_device_mig_mode;

struct driver_get_device_mig_mode_res {
	int errcode;
	union {
		driver_device_mig_mode mode;
		char *errmsg;
	} driver_get_device_mig_mode_res_u;
};
typedef struct driver_get_device_mig_mode_res driver_get_device_mig_mode_res;

struct driver_get_device_max_mig_device_count_res {
	int errcode;
	union {
		u_int count;
		char *errmsg;
	} driver_get_device_max_mig_device_count_res_u;
};
typedef struct driver_get_device_max_mig_device_count_res driver_get_device_max_mig_device_count_res;

struct driver_get_device_mig_device_res {
	int errcode;
	union {
		ptr_t dev;
		char *errmsg;
	} driver_get_device_mig_device_res_u;
};
typedef struct driver_get_device_mig_device_res driver_get_device_mig_device_res;

struct driver_get_device_gpu_instance_id_res {
	int errcode;
	union {
		u_int id;
		char *errmsg;
	} driver_get_device_gpu_instance_id_res_u;
};
typedef struct driver_get_device_gpu_instance_id_res driver_get_device_gpu_instance_id_res;

struct driver_get_device_compute_instance_id_res {
	int errcode;
	union {
		u_int id;
		char *errmsg;
	} driver_get_device_compute_instance_id_res_u;
};
typedef struct driver_get_device_compute_instance_id_res driver_get_device_compute_instance_id_res;

struct nvcgo_init_res {
	int errcode;
	union {
		char *errmsg;
	} nvcgo_init_res_u;
};
typedef struct nvcgo_init_res nvcgo_init_res;

struct nvcgo_shutdown_res {
	int errcode;
	union {
		char *errmsg;
	} nvcgo_shutdown_res_u;
};
typedef struct nvcgo_shutdown_res nvcgo_shutdown_res;

struct nvcgo_get_device_cgroup_version_res {
	int errcode;
	union {
		u_int vers;
		char *errmsg;
	} nvcgo_get_device_cgroup_version_res_u;
};
typedef struct nvcgo_get_device_cgroup_version_res nvcgo_get_device_cgroup_version_res;

struct nvcgo_find_device_cgroup_path_res {
	int errcode;
	union {
		char *cgroup_path;
		char *errmsg;
	} nvcgo_find_device_cgroup_path_res_u;
};
typedef struct nvcgo_find_device_cgroup_path_res nvcgo_find_device_cgroup_path_res;

struct nvcgo_setup_device_cgroup_res {
	int errcode;
	union {
		char *errmsg;
	} nvcgo_setup_device_cgroup_res_u;
};
typedef struct nvcgo_setup_device_cgroup_res nvcgo_setup_device_cgroup_res;

struct driver_get_device_1_argument {
	ptr_t arg1;
	u_int arg2;
};
typedef struct driver_get_device_1_argument driver_get_device_1_argument;

struct driver_get_device_minor_1_argument {
	ptr_t arg1;
	ptr_t arg2;
};
typedef struct driver_get_device_minor_1_argument driver_get_device_minor_1_argument;

struct driver_get_device_busid_1_argument {
	ptr_t arg1;
	ptr_t arg2;
};
typedef struct driver_get_device_busid_1_argument driver_get_device_busid_1_argument;

struct driver_get_device_uuid_1_argument {
	ptr_t arg1;
	ptr_t arg2;
};
typedef struct driver_get_device_uuid_1_argument driver_get_device_uuid_1_argument;

struct driver_get_device_arch_1_argument {
	ptr_t arg1;
	ptr_t arg2;
};
typedef struct driver_get_device_arch_1_argument driver_get_device_arch_1_argument;

struct driver_get_device_model_1_argument {
	ptr_t arg1;
	ptr_t arg2;
};
typedef struct driver_get_device_model_1_argument driver_get_device_model_1_argument;

struct driver_get_device_brand_1_argument {
	ptr_t arg1;
	ptr_t arg2;
};
typedef struct driver_get_device_brand_1_argument driver_get_device_brand_1_argument;

struct driver_get_device_mig_mode_1_argument {
	ptr_t arg1;
	ptr_t arg2;
};
typedef struct driver_get_device_mig_mode_1_argument driver_get_device_mig_mode_1_argument;

struct driver_get_device_max_mig_device_count_1_argument {
	ptr_t arg1;
	ptr_t arg2;
};
typedef struct driver_get_device_max_mig_device_count_1_argument driver_get_device_max_mig_device_count_1_argument;

struct driver_get_device_mig_device_1_argument {
	ptr_t arg1;
	ptr_t arg2;
	u_int arg3;
};
typedef struct driver_get_device_mig_device_1_argument driver_get_device_mig_device_1_argument;

struct driver_get_device_gpu_instance_id_1_argument {
	ptr_t arg1;
	ptr_t arg2;
};
typedef struct driver_get_device_gpu_instance_id_1_argument driver_get_device_gpu_instance_id_1_argument;

struct driver_get_device_compute_instance_id_1_argument {
	ptr_t arg1;
	ptr_t arg2;
};
typedef struct driver_get_device_compute_instance_id_1_argument driver_get_device_compute_instance_id_1_argument;

#define DRIVER_PROGRAM 1
#define DRIVER_VERSION 1

#if defined(__STDC__) || defined(__cplusplus)
#define DRIVER_INIT 1
extern  enum clnt_stat driver_init_1(ptr_t , driver_init_res *, CLIENT *);
extern  bool_t driver_init_1_svc(ptr_t , driver_init_res *, struct svc_req *);
#define DRIVER_SHUTDOWN 2
extern  enum clnt_stat driver_shutdown_1(ptr_t , driver_shutdown_res *, CLIENT *);
extern  bool_t driver_shutdown_1_svc(ptr_t , driver_shutdown_res *, struct svc_req *);
#define DRIVER_GET_RM_VERSION 3
extern  enum clnt_stat driver_get_rm_version_1(ptr_t , driver_get_rm_version_res *, CLIENT *);
extern  bool_t driver_get_rm_version_1_svc(ptr_t , driver_get_rm_version_res *, struct svc_req *);
#define DRIVER_GET_CUDA_VERSION 4
extern  enum clnt_stat driver_get_cuda_version_1(ptr_t , driver_get_cuda_version_res *, CLIENT *);
extern  bool_t driver_get_cuda_version_1_svc(ptr_t , driver_get_cuda_version_res *, struct svc_req *);
#define DRIVER_GET_DEVICE_COUNT 5
extern  enum clnt_stat driver_get_device_count_1(ptr_t , driver_get_device_count_res *, CLIENT *);
extern  bool_t driver_get_device_count_1_svc(ptr_t , driver_get_device_count_res *, struct svc_req *);
#define DRIVER_GET_DEVICE 6
extern  enum clnt_stat driver_get_device_1(ptr_t , u_int , driver_get_device_res *, CLIENT *);
extern  bool_t driver_get_device_1_svc(ptr_t , u_int , driver_get_device_res *, struct svc_req *);
#define DRIVER_GET_DEVICE_MINOR 7
extern  enum clnt_stat driver_get_device_minor_1(ptr_t , ptr_t , driver_get_device_minor_res *, CLIENT *);
extern  bool_t driver_get_device_minor_1_svc(ptr_t , ptr_t , driver_get_device_minor_res *, struct svc_req *);
#define DRIVER_GET_DEVICE_BUSID 8
extern  enum clnt_stat driver_get_device_busid_1(ptr_t , ptr_t , driver_get_device_busid_res *, CLIENT *);
extern  bool_t driver_get_device_busid_1_svc(ptr_t , ptr_t , driver_get_device_busid_res *, struct svc_req *);
#define DRIVER_GET_DEVICE_UUID 9
extern  enum clnt_stat driver_get_device_uuid_1(ptr_t , ptr_t , driver_get_device_uuid_res *, CLIENT *);
extern  bool_t driver_get_device_uuid_1_svc(ptr_t , ptr_t , driver_get_device_uuid_res *, struct svc_req *);
#define DRIVER_GET_DEVICE_ARCH 10
extern  enum clnt_stat driver_get_device_arch_1(ptr_t , ptr_t , driver_get_device_arch_res *, CLIENT *);
extern  bool_t driver_get_device_arch_1_svc(ptr_t , ptr_t , driver_get_device_arch_res *, struct svc_req *);
#define DRIVER_GET_DEVICE_MODEL 11
extern  enum clnt_stat driver_get_device_model_1(ptr_t , ptr_t , driver_get_device_model_res *, CLIENT *);
extern  bool_t driver_get_device_model_1_svc(ptr_t , ptr_t , driver_get_device_model_res *, struct svc_req *);
#define DRIVER_GET_DEVICE_BRAND 12
extern  enum clnt_stat driver_get_device_brand_1(ptr_t , ptr_t , driver_get_device_brand_res *, CLIENT *);
extern  bool_t driver_get_device_brand_1_svc(ptr_t , ptr_t , driver_get_device_brand_res *, struct svc_req *);
#define DRIVER_GET_DEVICE_MIG_MODE 13
extern  enum clnt_stat driver_get_device_mig_mode_1(ptr_t , ptr_t , driver_get_device_mig_mode_res *, CLIENT *);
extern  bool_t driver_get_device_mig_mode_1_svc(ptr_t , ptr_t , driver_get_device_mig_mode_res *, struct svc_req *);
#define DRIVER_GET_DEVICE_MAX_MIG_DEVICE_COUNT 14
extern  enum clnt_stat driver_get_device_max_mig_device_count_1(ptr_t , ptr_t , driver_get_device_max_mig_device_count_res *, CLIENT *);
extern  bool_t driver_get_device_max_mig_device_count_1_svc(ptr_t , ptr_t , driver_get_device_max_mig_device_count_res *, struct svc_req *);
#define DRIVER_GET_DEVICE_MIG_DEVICE 15
extern  enum clnt_stat driver_get_device_mig_device_1(ptr_t , ptr_t , u_int , driver_get_device_mig_device_res *, CLIENT *);
extern  bool_t driver_get_device_mig_device_1_svc(ptr_t , ptr_t , u_int , driver_get_device_mig_device_res *, struct svc_req *);
#define DRIVER_GET_DEVICE_GPU_INSTANCE_ID 16
extern  enum clnt_stat driver_get_device_gpu_instance_id_1(ptr_t , ptr_t , driver_get_device_gpu_instance_id_res *, CLIENT *);
extern  bool_t driver_get_device_gpu_instance_id_1_svc(ptr_t , ptr_t , driver_get_device_gpu_instance_id_res *, struct svc_req *);
#define DRIVER_GET_DEVICE_COMPUTE_INSTANCE_ID 17
extern  enum clnt_stat driver_get_device_compute_instance_id_1(ptr_t , ptr_t , driver_get_device_compute_instance_id_res *, CLIENT *);
extern  bool_t driver_get_device_compute_instance_id_1_svc(ptr_t , ptr_t , driver_get_device_compute_instance_id_res *, struct svc_req *);
extern int driver_program_1_freeresult (SVCXPRT *, xdrproc_t, caddr_t);

#else /* K&R C */
#define DRIVER_INIT 1
extern  enum clnt_stat driver_init_1();
extern  bool_t driver_init_1_svc();
#define DRIVER_SHUTDOWN 2
extern  enum clnt_stat driver_shutdown_1();
extern  bool_t driver_shutdown_1_svc();
#define DRIVER_GET_RM_VERSION 3
extern  enum clnt_stat driver_get_rm_version_1();
extern  bool_t driver_get_rm_version_1_svc();
#define DRIVER_GET_CUDA_VERSION 4
extern  enum clnt_stat driver_get_cuda_version_1();
extern  bool_t driver_get_cuda_version_1_svc();
#define DRIVER_GET_DEVICE_COUNT 5
extern  enum clnt_stat driver_get_device_count_1();
extern  bool_t driver_get_device_count_1_svc();
#define DRIVER_GET_DEVICE 6
extern  enum clnt_stat driver_get_device_1();
extern  bool_t driver_get_device_1_svc();
#define DRIVER_GET_DEVICE_MINOR 7
extern  enum clnt_stat driver_get_device_minor_1();
extern  bool_t driver_get_device_minor_1_svc();
#define DRIVER_GET_DEVICE_BUSID 8
extern  enum clnt_stat driver_get_device_busid_1();
extern  bool_t driver_get_device_busid_1_svc();
#define DRIVER_GET_DEVICE_UUID 9
extern  enum clnt_stat driver_get_device_uuid_1();
extern  bool_t driver_get_device_uuid_1_svc();
#define DRIVER_GET_DEVICE_ARCH 10
extern  enum clnt_stat driver_get_device_arch_1();
extern  bool_t driver_get_device_arch_1_svc();
#define DRIVER_GET_DEVICE_MODEL 11
extern  enum clnt_stat driver_get_device_model_1();
extern  bool_t driver_get_device_model_1_svc();
#define DRIVER_GET_DEVICE_BRAND 12
extern  enum clnt_stat driver_get_device_brand_1();
extern  bool_t driver_get_device_brand_1_svc();
#define DRIVER_GET_DEVICE_MIG_MODE 13
extern  enum clnt_stat driver_get_device_mig_mode_1();
extern  bool_t driver_get_device_mig_mode_1_svc();
#define DRIVER_GET_DEVICE_MAX_MIG_DEVICE_COUNT 14
extern  enum clnt_stat driver_get_device_max_mig_device_count_1();
extern  bool_t driver_get_device_max_mig_device_count_1_svc();
#define DRIVER_GET_DEVICE_MIG_DEVICE 15
extern  enum clnt_stat driver_get_device_mig_device_1();
extern  bool_t driver_get_device_mig_device_1_svc();
#define DRIVER_GET_DEVICE_GPU_INSTANCE_ID 16
extern  enum clnt_stat driver_get_device_gpu_instance_id_1();
extern  bool_t driver_get_device_gpu_instance_id_1_svc();
#define DRIVER_GET_DEVICE_COMPUTE_INSTANCE_ID 17
extern  enum clnt_stat driver_get_device_compute_instance_id_1();
extern  bool_t driver_get_device_compute_instance_id_1_svc();
extern int driver_program_1_freeresult ();
#endif /* K&R C */

struct nvcgo_get_device_cgroup_version_1_argument {
	ptr_t arg1;
	char *arg2;
	int arg3;
};
typedef struct nvcgo_get_device_cgroup_version_1_argument nvcgo_get_device_cgroup_version_1_argument;

struct nvcgo_find_device_cgroup_path_1_argument {
	ptr_t arg1;
	int arg2;
	char *arg3;
	int arg4;
	int arg5;
};
typedef struct nvcgo_find_device_cgroup_path_1_argument nvcgo_find_device_cgroup_path_1_argument;

struct nvcgo_setup_device_cgroup_1_argument {
	ptr_t arg1;
	int arg2;
	char *arg3;
	u_long arg4;
};
typedef struct nvcgo_setup_device_cgroup_1_argument nvcgo_setup_device_cgroup_1_argument;

#define NVCGO_PROGRAM 2
#define NVCGO_VERSION 1

#if defined(__STDC__) || defined(__cplusplus)
#define NVCGO_INIT 1
extern  enum clnt_stat nvcgo_init_1(ptr_t , nvcgo_init_res *, CLIENT *);
extern  bool_t nvcgo_init_1_svc(ptr_t , nvcgo_init_res *, struct svc_req *);
#define NVCGO_SHUTDOWN 2
extern  enum clnt_stat nvcgo_shutdown_1(ptr_t , nvcgo_shutdown_res *, CLIENT *);
extern  bool_t nvcgo_shutdown_1_svc(ptr_t , nvcgo_shutdown_res *, struct svc_req *);
#define NVCGO_GET_DEVICE_CGROUP_VERSION 3
extern  enum clnt_stat nvcgo_get_device_cgroup_version_1(ptr_t , char *, int , nvcgo_get_device_cgroup_version_res *, CLIENT *);
extern  bool_t nvcgo_get_device_cgroup_version_1_svc(ptr_t , char *, int , nvcgo_get_device_cgroup_version_res *, struct svc_req *);
#define NVCGO_FIND_DEVICE_CGROUP_PATH 4
extern  enum clnt_stat nvcgo_find_device_cgroup_path_1(ptr_t , int , char *, int , int , nvcgo_find_device_cgroup_path_res *, CLIENT *);
extern  bool_t nvcgo_find_device_cgroup_path_1_svc(ptr_t , int , char *, int , int , nvcgo_find_device_cgroup_path_res *, struct svc_req *);
#define NVCGO_SETUP_DEVICE_CGROUP 5
extern  enum clnt_stat nvcgo_setup_device_cgroup_1(ptr_t , int , char *, u_long , nvcgo_setup_device_cgroup_res *, CLIENT *);
extern  bool_t nvcgo_setup_device_cgroup_1_svc(ptr_t , int , char *, u_long , nvcgo_setup_device_cgroup_res *, struct svc_req *);
extern int nvcgo_program_1_freeresult (SVCXPRT *, xdrproc_t, caddr_t);

#else /* K&R C */
#define NVCGO_INIT 1
extern  enum clnt_stat nvcgo_init_1();
extern  bool_t nvcgo_init_1_svc();
#define NVCGO_SHUTDOWN 2
extern  enum clnt_stat nvcgo_shutdown_1();
extern  bool_t nvcgo_shutdown_1_svc();
#define NVCGO_GET_DEVICE_CGROUP_VERSION 3
extern  enum clnt_stat nvcgo_get_device_cgroup_version_1();
extern  bool_t nvcgo_get_device_cgroup_version_1_svc();
#define NVCGO_FIND_DEVICE_CGROUP_PATH 4
extern  enum clnt_stat nvcgo_find_device_cgroup_path_1();
extern  bool_t nvcgo_find_device_cgroup_path_1_svc();
#define NVCGO_SETUP_DEVICE_CGROUP 5
extern  enum clnt_stat nvcgo_setup_device_cgroup_1();
extern  bool_t nvcgo_setup_device_cgroup_1_svc();
extern int nvcgo_program_1_freeresult ();
#endif /* K&R C */

/* the xdr functions */

#if defined(__STDC__) || defined(__cplusplus)
extern  bool_t xdr_ptr_t (XDR *, ptr_t*);
extern  bool_t xdr_driver_init_res (XDR *, driver_init_res*);
extern  bool_t xdr_driver_shutdown_res (XDR *, driver_shutdown_res*);
extern  bool_t xdr_driver_get_rm_version_res (XDR *, driver_get_rm_version_res*);
extern  bool_t xdr_driver_cuda_version (XDR *, driver_cuda_version*);
extern  bool_t xdr_driver_get_cuda_version_res (XDR *, driver_get_cuda_version_res*);
extern  bool_t xdr_driver_device_arch (XDR *, driver_device_arch*);
extern  bool_t xdr_driver_get_device_arch_res (XDR *, driver_get_device_arch_res*);
extern  bool_t xdr_driver_get_device_count_res (XDR *, driver_get_device_count_res*);
extern  bool_t xdr_driver_get_device_res (XDR *, driver_get_device_res*);
extern  bool_t xdr_driver_get_device_minor_res (XDR *, driver_get_device_minor_res*);
extern  bool_t xdr_driver_get_device_busid_res (XDR *, driver_get_device_busid_res*);
extern  bool_t xdr_driver_get_device_uuid_res (XDR *, driver_get_device_uuid_res*);
extern  bool_t xdr_driver_get_device_model_res (XDR *, driver_get_device_model_res*);
extern  bool_t xdr_driver_get_device_brand_res (XDR *, driver_get_device_brand_res*);
extern  bool_t xdr_driver_device_mig_mode (XDR *, driver_device_mig_mode*);
extern  bool_t xdr_driver_get_device_mig_mode_res (XDR *, driver_get_device_mig_mode_res*);
extern  bool_t xdr_driver_get_device_max_mig_device_count_res (XDR *, driver_get_device_max_mig_device_count_res*);
extern  bool_t xdr_driver_get_device_mig_device_res (XDR *, driver_get_device_mig_device_res*);
extern  bool_t xdr_driver_get_device_gpu_instance_id_res (XDR *, driver_get_device_gpu_instance_id_res*);
extern  bool_t xdr_driver_get_device_compute_instance_id_res (XDR *, driver_get_device_compute_instance_id_res*);
extern  bool_t xdr_nvcgo_init_res (XDR *, nvcgo_init_res*);
extern  bool_t xdr_nvcgo_shutdown_res (XDR *, nvcgo_shutdown_res*);
extern  bool_t xdr_nvcgo_get_device_cgroup_version_res (XDR *, nvcgo_get_device_cgroup_version_res*);
extern  bool_t xdr_nvcgo_find_device_cgroup_path_res (XDR *, nvcgo_find_device_cgroup_path_res*);
extern  bool_t xdr_nvcgo_setup_device_cgroup_res (XDR *, nvcgo_setup_device_cgroup_res*);
extern  bool_t xdr_driver_get_device_1_argument (XDR *, driver_get_device_1_argument*);
extern  bool_t xdr_driver_get_device_minor_1_argument (XDR *, driver_get_device_minor_1_argument*);
extern  bool_t xdr_driver_get_device_busid_1_argument (XDR *, driver_get_device_busid_1_argument*);
extern  bool_t xdr_driver_get_device_uuid_1_argument (XDR *, driver_get_device_uuid_1_argument*);
extern  bool_t xdr_driver_get_device_arch_1_argument (XDR *, driver_get_device_arch_1_argument*);
extern  bool_t xdr_driver_get_device_model_1_argument (XDR *, driver_get_device_model_1_argument*);
extern  bool_t xdr_driver_get_device_brand_1_argument (XDR *, driver_get_device_brand_1_argument*);
extern  bool_t xdr_driver_get_device_mig_mode_1_argument (XDR *, driver_get_device_mig_mode_1_argument*);
extern  bool_t xdr_driver_get_device_max_mig_device_count_1_argument (XDR *, driver_get_device_max_mig_device_count_1_argument*);
extern  bool_t xdr_driver_get_device_mig_device_1_argument (XDR *, driver_get_device_mig_device_1_argument*);
extern  bool_t xdr_driver_get_device_gpu_instance_id_1_argument (XDR *, driver_get_device_gpu_instance_id_1_argument*);
extern  bool_t xdr_driver_get_device_compute_instance_id_1_argument (XDR *, driver_get_device_compute_instance_id_1_argument*);
extern  bool_t xdr_nvcgo_get_device_cgroup_version_1_argument (XDR *, nvcgo_get_device_cgroup_version_1_argument*);
extern  bool_t xdr_nvcgo_find_device_cgroup_path_1_argument (XDR *, nvcgo_find_device_cgroup_path_1_argument*);
extern  bool_t xdr_nvcgo_setup_device_cgroup_1_argument (XDR *, nvcgo_setup_device_cgroup_1_argument*);

#else /* K&R C */
extern bool_t xdr_ptr_t ();
extern bool_t xdr_driver_init_res ();
extern bool_t xdr_driver_shutdown_res ();
extern bool_t xdr_driver_get_rm_version_res ();
extern bool_t xdr_driver_cuda_version ();
extern bool_t xdr_driver_get_cuda_version_res ();
extern bool_t xdr_driver_device_arch ();
extern bool_t xdr_driver_get_device_arch_res ();
extern bool_t xdr_driver_get_device_count_res ();
extern bool_t xdr_driver_get_device_res ();
extern bool_t xdr_driver_get_device_minor_res ();
extern bool_t xdr_driver_get_device_busid_res ();
extern bool_t xdr_driver_get_device_uuid_res ();
extern bool_t xdr_driver_get_device_model_res ();
extern bool_t xdr_driver_get_device_brand_res ();
extern bool_t xdr_driver_device_mig_mode ();
extern bool_t xdr_driver_get_device_mig_mode_res ();
extern bool_t xdr_driver_get_device_max_mig_device_count_res ();
extern bool_t xdr_driver_get_device_mig_device_res ();
extern bool_t xdr_driver_get_device_gpu_instance_id_res ();
extern bool_t xdr_driver_get_device_compute_instance_id_res ();
extern bool_t xdr_nvcgo_init_res ();
extern bool_t xdr_nvcgo_shutdown_res ();
extern bool_t xdr_nvcgo_get_device_cgroup_version_res ();
extern bool_t xdr_nvcgo_find_device_cgroup_path_res ();
extern bool_t xdr_nvcgo_setup_device_cgroup_res ();
extern bool_t xdr_driver_get_device_1_argument ();
extern bool_t xdr_driver_get_device_minor_1_argument ();
extern bool_t xdr_driver_get_device_busid_1_argument ();
extern bool_t xdr_driver_get_device_uuid_1_argument ();
extern bool_t xdr_driver_get_device_arch_1_argument ();
extern bool_t xdr_driver_get_device_model_1_argument ();
extern bool_t xdr_driver_get_device_brand_1_argument ();
extern bool_t xdr_driver_get_device_mig_mode_1_argument ();
extern bool_t xdr_driver_get_device_max_mig_device_count_1_argument ();
extern bool_t xdr_driver_get_device_mig_device_1_argument ();
extern bool_t xdr_driver_get_device_gpu_instance_id_1_argument ();
extern bool_t xdr_driver_get_device_compute_instance_id_1_argument ();
extern bool_t xdr_nvcgo_get_device_cgroup_version_1_argument ();
extern bool_t xdr_nvcgo_find_device_cgroup_path_1_argument ();
extern bool_t xdr_nvcgo_setup_device_cgroup_1_argument ();

#endif /* K&R C */

#ifdef __cplusplus
}
#endif

#endif /* !_NVC_RPC_H_RPCGEN */
