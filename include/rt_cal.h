/*
 ***************************************************************************
 * Ralink Tech Inc.
 * 4F, No. 2 Technology 5th Rd.
 * Science-based Industrial Park
 * Hsin-chu, Taiwan, R.O.C.
 *
 * (c) Copyright 2002-2009, Ralink Technology, Inc.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 ***************************************************************************

	Module Name:
	cmm_rf_cal.c

	Abstract:
	RF calibration and profile related functions

	Revision History:
	Who         When          What
	--------    ----------    ----------------------------------------------
	Arvin Tai     2012/05/02
*/

#define DPD_CAL_PASS_THRES		5
#define DPD_CAL_MAX_RETRY		5

INT32 CalcRCalibrationCode(
	IN PRTMP_ADAPTER pAd,
	IN INT32 D1,
	IN INT32 D2);

INT Set_TestRxIQCalibration_Proc(
	IN RTMP_ADAPTER	*pAd,
	IN PSTRING arg);

VOID R_Calibration(
	IN PRTMP_ADAPTER pAd);

VOID RtmpKickOutHwNullFrame(
	IN PRTMP_ADAPTER pAd,
	IN BOOLEAN bPrepareContent,
	IN BOOLEAN bTransmit);

VOID DPD_IQ_Swap_AM_PM_Inversion(
	IN PRTMP_ADAPTER pAd,
	IN UCHAR AntIdx);

VOID DPD_AM_AM_LUT_Scaling(
	IN PRTMP_ADAPTER pAd,
	IN UCHAR AntIdx);

UCHAR DPD_Calibration(
	IN PRTMP_ADAPTER pAd,
	IN UCHAR AntIdx);

VOID DoDPDCalibration(
	IN PRTMP_ADAPTER pAd);

INT Set_DPDCalPassThres_Proc(
	IN RTMP_ADAPTER	*pAd,
	IN PSTRING arg);

INT Set_TestDPDCalibration_Proc(
	IN RTMP_ADAPTER	*pAd,
	IN PSTRING arg);

INT Set_TestDPDCalibrationTX0_Proc(
	IN RTMP_ADAPTER *pAd,
	IN PSTRING arg);

INT Set_TestDPDCalibrationTX1_Proc(
	IN RTMP_ADAPTER *pAd,
	IN PSTRING arg);

VOID LOFT_IQ_Calibration(
	IN RTMP_ADAPTER *pAd);

BOOLEAN BW_Filter_Calibration(
	IN PRTMP_ADAPTER pAd,
	IN BOOLEAN bTxCal);

VOID RxDCOC_Calibration(
	IN PRTMP_ADAPTER pAd);

VOID RXIQ_Calibration(
	IN PRTMP_ADAPTER pAd);

VOID RF_SELF_TXDC_CAL(
	IN PRTMP_ADAPTER pAd);

