/*
 ***************************************************************************
 * Ralink Tech Inc.
 * 4F, No. 2 Technology 5th Rd.
 * Science-based Industrial Park
 * Hsin-chu, Taiwan, R.O.C.
 *
 * (c) Copyright 2002, Ralink Technology, Inc.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 ***************************************************************************

    Module Name:
    cmm_radar.c

    Abstract:
    CS/DFS common functions.

    Revision History:
    Who       When            What
    --------  ----------      ----------------------------------------------
*/
#include "rt_config.h"

/*----- 802.11H -----*/

/* Periodic Radar detection, switch channel will occur in RTMPHandleTBTTInterrupt()*/
/* Before switch channel, driver needs doing channel switch announcement.*/
VOID RadarDetectPeriodic(
	IN PRTMP_ADAPTER	pAd)
{
	INT i, ChIdx = 0, bAnyUnavailableChannel = FALSE;

	/* 
		1. APStart(), CalBufTime = 0;
		2. if bAnyUnavailableChannel, CalBufTime = DEFAULT_CAL_BUF_TIME;
		3. if Calibrated, CalBufTime = DEFAULT_CAL_BUF_TIME_MAX;
	*/
	for (i=0; i<pAd->ChannelListNum; i++)
	{
		if (pAd->ChannelList[i].RemainingTimeForUse != 0)
		{
			bAnyUnavailableChannel = TRUE;
		}

		if (pAd->CommonCfg.Channel == pAd->ChannelList[i].Channel)
		{
			ChIdx = i;
		}
	}


	if (pAd->Dot11_H.RDMode == RD_SILENCE_MODE)
	{
		/* In Silent  Mode, RDCount is use to check with the CAC Time */
	if (pAd->Dot11_H.RDCount++ > pAd->Dot11_H.ChMovingTime &&
		pAd->ChannelList[ChIdx].RemainingTimeForUse == 0)
	{
			DBGPRINT(RT_DEBUG_TRACE,
					("Not found radar signal, start send beacon and radar detection in service monitor\n\n"));
		pAd->Dot11_H.RDMode = RD_NORMAL_MODE;
		AsicEnableBssSync(pAd);
#ifdef MT76x2
			if (IS_MT76x2(pAd)) {
				mt76x2_calibration(pAd, pAd->hw_cfg.cent_ch);
				mt76x2_tssi_calibration(pAd, pAd->hw_cfg.cent_ch);
			}
#endif /* MT76x2 */
			pAd->Dot11_H.RDCount = 0;
		}
	}
}

/*
	========================================================================

	Routine Description:
		Radar channel check routine

	Arguments:
		pAd 	Pointer to our adapter

	Return Value:
		TRUE	need to do radar detect
		FALSE	need not to do radar detect

	========================================================================
*/
BOOLEAN RadarChannelCheck(
	IN PRTMP_ADAPTER	pAd,
	IN UCHAR			Ch)
{
	INT 	i;
	BOOLEAN result = FALSE;

	for (i=0; i<pAd->ChannelListNum; i++)
	{
		if (Ch == pAd->ChannelList[i].Channel)
		{
			result = pAd->ChannelList[i].DfsReq;
			break;
		}
	}

	return result;
}


/*
	========================================================================

	Routine Description:
		Determine the current radar state

	Arguments:
		pAd 	Pointer to our adapter

	Return Value:

	========================================================================
*/
VOID RadarStateCheck(
	IN PRTMP_ADAPTER	pAd)
{
	pAd->Dot11_H.CalBufTime = 0;

	if ((pAd->CommonCfg.Channel > 14) &&
		(pAd->CommonCfg.bIEEE80211H == 1) &&
		RadarChannelCheck(pAd, pAd->CommonCfg.Channel))
	{
		pAd->Dot11_H.RDMode = RD_SILENCE_MODE;
		pAd->Dot11_H.RDCount = 0;
		pAd->Dot11_H.InServiceMonitorCount = 0;
	}
	else
		pAd->Dot11_H.RDMode = RD_NORMAL_MODE;

}


ULONG JapRadarType(
	IN PRTMP_ADAPTER pAd)
{
	ULONG		i;
	const UCHAR	Channel[15]={52, 56, 60, 64, 100, 104, 108, 112, 116, 120, 124, 128, 132, 136, 140};

	if (pAd->CommonCfg.RDDurRegion != JAP)
	{
		return pAd->CommonCfg.RDDurRegion;
	}

	for (i=0; i<15; i++)
	{
		if (pAd->CommonCfg.Channel == Channel[i])
		{
			break;
		}
	}

	if (i < 4)
		return JAP_W53;
	else if (i < 15)
		return JAP_W56;
	else
		return JAP; /* W52*/

}


UCHAR get_channel_by_reference(
	IN PRTMP_ADAPTER pAd,
	IN UINT8 mode)
{
	UCHAR ch = 0;
	INT ch_idx;

	switch (mode)
	{
		case 1: 
		{
			USHORT min_time = 0xFFFF;
			/* select channel with least RemainingTimeForUse */
			for ( ch_idx = 0; ch_idx <  pAd->ChannelListNum; ch_idx++)
			{
				if (pAd->ChannelList[ch_idx].RemainingTimeForUse < min_time)
				{
#ifdef DOT11_N_SUPPORT
					/* If the channel not in 40MHz/80MHz group, ignore it. */
					if (pAd->CommonCfg.RegTransmitSetting.field.BW == BW_40 &&
						!(pAd->ChannelList[ch_idx].Flags & CHANNEL_40M_CAP))
						continue;
#ifdef DOT11_VHT_AC
					if (pAd->CommonCfg.vht_bw == VHT_BW_80 &&
						!(pAd->ChannelList[ch_idx].Flags & CHANNEL_80M_CAP))
						continue;
#endif /* DOT11_VHT_AC */
#endif /* DOT11_N_SUPPORT */

					min_time = pAd->ChannelList[ch_idx].RemainingTimeForUse;
					ch = pAd->ChannelList[ch_idx].Channel;
				}
			}
			break;
		}

		default:
		{
			ch = FirstChannel(pAd);
			break;
		}
	}	

    DBGPRINT(RT_DEBUG_TRACE,("%s(): mode = %u, ch = %u\n",
							 __FUNCTION__, mode, ch));
	return ch;
}
		

#ifdef CONFIG_AP_SUPPORT
/*
	========================================================================

	Routine Description:
		Channel switching count down process upon radar detection

	Arguments:
		pAd 	Pointer to our adapter

	========================================================================
*/
VOID ChannelSwitchingCountDownProc(
	IN PRTMP_ADAPTER	pAd)
{
	DBGPRINT(RT_DEBUG_TRACE, ("%s():Channel Switching...(%d/%d)\n",
				__FUNCTION__, pAd->Dot11_H.CSCount, pAd->Dot11_H.CSPeriod));
	
	pAd->Dot11_H.CSCount++;
	if (pAd->Dot11_H.CSCount >= pAd->Dot11_H.CSPeriod)
	{
		APStop(pAd);
		APStartUp(pAd);
	}
}
#endif /* CONFIG_AP_SUPPORT */

/* 
    ==========================================================================
    Description:
        Set channel switch Period
    Return:
        TRUE if all parameters are OK, FALSE otherwise
    ==========================================================================
*/
INT	Set_CSPeriod_Proc(
	IN	PRTMP_ADAPTER	pAd, 
	IN	PSTRING			arg)
{
	pAd->Dot11_H.CSPeriod = (USHORT) simple_strtol(arg, 0, 10);

	DBGPRINT(RT_DEBUG_TRACE, ("Set_CSPeriod_Proc::(CSPeriod=%d)\n", pAd->Dot11_H.CSPeriod));

	return TRUE;
}

/* 
    ==========================================================================
    Description:
		change channel moving time for DFS testing.

	Arguments:
	    pAdapter                    Pointer to our adapter
	    wrq                         Pointer to the ioctl argument

    Return Value:
        None

    Note:
        Usage: 
               1.) iwpriv ra0 set ChMovTime=[value]
    ==========================================================================
*/
INT Set_ChMovingTime_Proc(
	IN PRTMP_ADAPTER pAd, 
	IN PSTRING arg)
{
	USHORT Value;

	Value = (USHORT) simple_strtol(arg, 0, 10);

	pAd->Dot11_H.ChMovingTime = Value;

	DBGPRINT(RT_DEBUG_TRACE, ("%s: %d\n", __FUNCTION__,
		pAd->Dot11_H.ChMovingTime));

	return TRUE;
}


/* 
    ==========================================================================
    Description:
		Reset channel block status.
	Arguments:
	    pAd				Pointer to our adapter
	    arg				Not used

    Return Value:
        None

    Note:
        Usage: 
               1.) iwpriv ra0 set ChMovTime=[value]
    ==========================================================================
*/
INT Set_BlockChReset_Proc(
	IN PRTMP_ADAPTER pAd, 
	IN PSTRING arg)
{
	INT i;

	DBGPRINT(RT_DEBUG_TRACE, ("%s: Reset channel block status.\n", __FUNCTION__));	
	
	for (i=0; i<pAd->ChannelListNum; i++)
		pAd->ChannelList[i].RemainingTimeForUse = 0;

	return TRUE;
}



