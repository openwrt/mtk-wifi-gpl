/****************************************************************************
 * Ralink Tech Inc.
 * 4F, No. 2 Technology 5th Rd.
 * Science-based Industrial Park
 * Hsin-chu, Taiwan, R.O.C.
 * (c) Copyright 2002, Ralink Technology, Inc.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 ****************************************************************************

    Abstract:
        IEEE P802.11w

 */
#ifndef __PMF_H
#define __PMF_H
#ifdef DOT11W_PMF_SUPPORT

VOID PMF_PeerAction(
	IN PRTMP_ADAPTER pAd, 
	IN MLME_QUEUE_ELEM *Elem);

VOID PMF_MlmeSAQueryReq(
        IN PRTMP_ADAPTER pAd, 
        IN MAC_TABLE_ENTRY *pEntry);
    
VOID PMF_PeerSAQueryReqAction(
	IN PRTMP_ADAPTER pAd, 
	IN MLME_QUEUE_ELEM *Elem);

VOID PMF_PeerSAQueryRspAction(
	IN PRTMP_ADAPTER pAd, 
	IN MLME_QUEUE_ELEM *Elem);
	
VOID PMF_DerivePTK(
	IN PRTMP_ADAPTER pAd, 
	IN UCHAR *PMK,
	IN UCHAR *ANonce,
	IN UCHAR *AA,
	IN UCHAR *SNonce,
	IN UCHAR *SA,
	OUT UCHAR *output,
	IN UINT len);
	
VOID PMF_DeriveIGTK(
	IN PRTMP_ADAPTER pAd,
        OUT UCHAR *output);

VOID PMF_InsertIGTKKDE(
	IN PRTMP_ADAPTER pAd,
	IN INT apidx,
	IN PUCHAR pFrameBuf,
	OUT PULONG pFrameLen);

BOOLEAN PMF_ExtractIGTKKDE(
	IN PRTMP_ADAPTER pAd,
	IN PUCHAR pBuf,
	IN INT buf_len);

VOID PMF_MakeRsnIeGMgmtCipher(	
	IN PRTMP_ADAPTER pAd,	
	IN UCHAR ElementID,
	IN UCHAR apidx,
	OUT PUCHAR pRsnIe,
	OUT UCHAR *rsn_len);

NTSTATUS PMF_RsnCapableValidation(
        IN PRTMP_ADAPTER pAd,
        IN PUINT8 pRsnie,
        IN UINT rsnie_len,
        IN BOOLEAN self_MFPC,
	IN BOOLEAN self_MFPR,
        IN PMAC_TABLE_ENTRY	pEntry);

BOOLEAN	PMF_PerformTxFrameAction(
	IN PRTMP_ADAPTER pAd,
	OUT PNDIS_PACKET pPacket);
	
BOOLEAN	PMF_PerformRxFrameAction(
	IN PRTMP_ADAPTER pAd,
	IN RX_BLK *pRxBlk);

void rtmp_read_pmf_parameters_from_file(
	IN PRTMP_ADAPTER pAd,
	IN PSTRING tmpbuf,
	IN PSTRING pBuffer);
	
INT Set_PMFMFPC_Proc (
	IN PRTMP_ADAPTER pAd, 
	IN PCHAR arg);

INT Set_PMFMFPR_Proc (
	IN PRTMP_ADAPTER pAd, 
	IN PCHAR arg);
 
INT Set_PMFSHA256_Proc (
	IN PRTMP_ADAPTER pAd, 
	IN PCHAR arg);
 
#endif /* DOT11W_PMF_SUPPORT */

#endif /* __PMF_H */

