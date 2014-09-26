/****************************************************************************
 * Ralink Tech Inc.
 * Taiwan, R.O.C.
 *
 * (c) Copyright 2010, Ralink Technology, Inc.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 ***************************************************************************/

/****************************************************************************

	Abstract:

	All Related Structure & Definition for UBICOM platform.

	Only used in UTIL module.

***************************************************************************/

#ifndef __VR_UBICOM_H__
#define __VR_UBICOM_H__

#ifdef PLATFORM_UBM_IPX8

#include <asm/cachectl.h>

#undef RTMP_UTIL_DCACHE_FLUSH
#define RTMP_UTIL_DCACHE_FLUSH(__AddrStart, __Size)						\
	flush_dcache_range((ULONG)(__AddrStart),							\
						(ULONG)(((UCHAR *)(__AddrStart)) + __Size - 1))

#endif /* PLATFORM_UBM_IPX8 */

#endif /* __VR_UBICOM_H__ */

/* End of vrut_ubm.h */

