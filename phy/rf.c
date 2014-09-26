/*
 ***************************************************************************
 * MediaTek Inc. 
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 ***************************************************************************

	Module Name:
	rf.c
*/

#include "rt_config.h"

VOID InitRFRegisters(
	IN RTMP_ADAPTER *pAd)
{
	DBGPRINT(RT_DEBUG_TRACE, ("%s(): Init RF Registers\n", __FUNCTION__));
	if (pAd->chipOps.AsicRfInit)
		pAd->chipOps.AsicRfInit(pAd);
}

