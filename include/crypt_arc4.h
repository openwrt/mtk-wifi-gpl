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
    Module Name:
    RC4

    Abstract:
    
    Revision History:
    Who         When            What
    --------    ----------      ------------------------------------------
    Eddy        2009/05/13      ARC4
***************************************************************************/

#ifndef __CRYPT_ARC4_H__
#define __CRYPT_ARC4_H__

#include "rt_config.h"

/* ARC4 definition & structure */
#define ARC4_KEY_BLOCK_SIZE 256

typedef struct {
	UINT BlockIndex1;
	UINT BlockIndex2;
	UINT8 KeyBlock[256];
} ARC4_CTX_STRUC, *PARC4_CTX_STRUC;

/* ARC4 operations */
VOID ARC4_INIT(
	IN ARC4_CTX_STRUC * pARC4_CTX,
	IN PUCHAR pKey,
	IN UINT KeyLength);

VOID ARC4_Compute(
	IN ARC4_CTX_STRUC * pARC4_CTX,
	IN UINT8 InputBlock[],
	IN UINT InputBlockSize,
	OUT UINT8 OutputBlock[]);

VOID ARC4_Discard_KeyLength(
	IN ARC4_CTX_STRUC * pARC4_CTX,
	IN UINT Length);

#endif /* __CRYPT_ARC4_H__ */
