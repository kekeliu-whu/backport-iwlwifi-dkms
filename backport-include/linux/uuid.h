#ifndef __BACKPORT_LINUX_UUID_H_
#define __BACKPORT_LINUX_UUID_H_
#include <linux/version.h>
#include_next <linux/uuid.h>

#ifndef UUID_STRING_LEN
/*
 * The length of a UUID string ("aaaaaaaa-bbbb-cccc-dddd-eeeeeeeeeeee")
 * not including trailing NUL.
 */
#define	UUID_STRING_LEN		36
#endif

#if LINUX_VERSION_IS_LESS(4,13,0) && \
	RHEL_RELEASE_CODE < RHEL_RELEASE_VERSION(7,6)
#define guid_t uuid_le
#define uuid_t uuid_be

static inline void guid_gen(guid_t *u)
{
	return uuid_le_gen(u);
}
static inline void uuid_gen(uuid_t *u)
{
	return uuid_be_gen(u);
}

static inline void guid_copy(guid_t *dst, const guid_t *src)
{
	memcpy(dst, src, sizeof(guid_t));
}
#define GUID_INIT(a, b, c, d0, d1, d2, d3, d4, d5, d6, d7)	\
	UUID_LE(a, b, c, d0, d1, d2, d3, d4, d5, d6, d7)

#endif

#endif /* __BACKPORT_LINUX_UUID_H_ */
