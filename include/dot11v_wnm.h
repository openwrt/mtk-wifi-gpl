/*
 ***************************************************************************
 * Ralink Tech Inc.
 * 5F., No.36 Taiyuan St., Jhubei City,
 * Hsin-chu, Taiwan, R.O.C.
 *
 * (c) Copyright 2011, Ralink Technology, Inc.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 ***************************************************************************

	Module Name:
	dot11v_wnm.h
	
	Revision History:
	Who 			When			What
	--------		----------		----------------------------------------------
	
*/

#ifndef __DOT11V_WNM_H__
#define __DOT11V_WNM_H__

enum WNM_ACTION_FIELD {
	EVENT_REQUEST,
	EVENT_REPORT,
	DIAGNOSTIC_REQ,
	DIAGNOSTIC_REPORT,
	LOCATION_CONF_REQ,
	LOCATION_CONF_RSP,
	BSS_TRANSITION_QUERY,
	BSS_TRANSITION_REQ,
	BSS_TRANSITION_RSP,
	FMS_REQ,
	FMS_RSP,
	COLLOCATED_INTERFERENCE_REQ,
	COLLOCATED_INTERFERENCE_REPORT,
	TFS_REQ,
	TFS_RSP,
	TFS_NOTIFY,
	WNM_SLEEP_MODE_REQ,
	WNM_SLEEP_MODE_RSP,
	TIM_BROADCAST_REQ,
	TIM_BROADCAST_RSP,
	QOS_TRAFFIC_CAPABILITY_UPDATE,
	CHANNEL_USAGE_REQ,
	CHANNEL_USAGE_RSP,
	DMS_REQ,
	DMS_RSP,
	TIMING_MEASUREMENT_REQ,
	WNM_NOTIFICATION_REQ,
	WNM_NOTIFICATION_RSP,
}; 

typedef struct GNU_PACKED _WNM_FRAME
{
	HEADER_802_11 Hdr;
	UCHAR Category;
	union {
		struct {
			UCHAR Action;
			UCHAR DialogToken;
			UCHAR Variable[0];
		} GNU_PACKED BTM_QUERY;

		struct {
			UCHAR Action;
			UCHAR DialogToken;
			UCHAR Variable[0];
		} GNU_PACKED BTM_REQ;

		struct {
			UCHAR Action;
			UCHAR DialogToken;
			UCHAR Variable[0];
		} GNU_PACKED BTM_RSP;
	}u;
} WNM_FRAME, *PWNM_FRAME;

void PeerWNMAction(IN PRTMP_ADAPTER pAd,
				   IN MLME_QUEUE_ELEM *Elem);

#endif /* __DOT11V_WNM_H__ */
