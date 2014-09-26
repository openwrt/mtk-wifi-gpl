/*
 ***************************************************************************
 * Ralink Tech Inc.
 * 4F, No. 2 Technology 5th Rd.
 * Science-based Industrial Park
 * Hsin-chu, Taiwan, R.O.C.
 *
 * (c) Copyright 2002-2004, Ralink Technology, Inc.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 ***************************************************************************

	Module Name:

	Abstract:

	Revision History:
	Who 		When			What
	--------	----------		----------------------------------------------
*/

#include <rt_config.h>


INT dev_adjust_radio(RTMP_ADAPTER *pAd)
{
	struct hw_setting new_cfg, *hw_cfg = &pAd->hw_cfg;


	NdisZeroMemory(&new_cfg, sizeof(struct hw_setting));

	
	/* For all wdev, find the maximum inter-set */

	
	if (hw_cfg->bbp_bw != new_cfg.bbp_bw)
	{
		bbp_set_bw(pAd, new_cfg.bbp_bw);
		hw_cfg->bbp_bw = new_cfg.bbp_bw;
	}

	if (hw_cfg->cent_ch != new_cfg.cent_ch)
	{
		UINT8 ext_ch = EXTCHA_NONE;
		
		bbp_set_ctrlch(pAd, ext_ch);
		rtmp_mac_set_ctrlch(pAd, ext_ch);	
	}

	return TRUE;
}

