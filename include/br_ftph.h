/****************************************************************************
 * Ralink Tech Inc.
 * Taiwan, R.O.C.
 *
 * (c) Copyright 2002, Ralink Technology, Inc.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 ***************************************************************************/

/****************************************************************************

	Abstract:

	All Bridge Fast Path Related Structure & Definition.

***************************************************************************/

#ifndef __BR_FTPH_H__
#define __BR_FTPH_H__

/* Public function prototype */
/*
========================================================================
Routine Description:
	Init bridge fast path module.

Arguments:
	None

Return Value:
	None

Note:
	Used in module init.
========================================================================
*/
VOID BG_FTPH_Init(VOID);

/*
========================================================================
Routine Description:
	Remove bridge fast path module.

Arguments:
	None

Return Value:
	None

Note:
	Used in module remove.
========================================================================
*/
VOID BG_FTPH_Remove(VOID);

/*
========================================================================
Routine Description:
	Forward the received packet.

Arguments:
	pPacket			- the received packet

Return Value:
	None

Note:
========================================================================
*/
UINT32 BG_FTPH_PacketFromApHandle(
	IN		PNDIS_PACKET	pPacket);

#endif /* __BR_FTPH_H__ */

/* End of br_ftph.h */

