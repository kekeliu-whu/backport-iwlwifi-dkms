#ifndef __BACKPORT_UAPI_LINUX_GENETLINK_H
#define __BACKPORT_UAPI_LINUX_GENETLINK_H
#include_next <uapi/linux/genetlink.h>

#ifndef GENL_UNS_ADMIN_PERM
#define GENL_UNS_ADMIN_PERM GENL_ADMIN_PERM
#endif

#endif /* __BACKPORT_UAPI_LINUX_GENETLINK_H */
