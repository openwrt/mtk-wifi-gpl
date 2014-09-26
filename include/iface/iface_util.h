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

    Module Name:
	rtmp_util.h
 
    Abstract:
	Common for PCI/USB/RBUS.
 
    Revision History:
    Who          When          What
    ---------    ----------    ----------------------------------------------
*/

#ifndef __RTMP_UTIL_H__
#define __RTMP_UTIL_H__

#define LEN_CCMP_HDR				8
#define LEN_CCMP_MIC				8
/* maximum of PCI, USB, or RBUS, int PCI, it is 0 but in USB, it is 11 */
#define RTMP_PKT_TAIL_PADDING 	11 /* 3(max 4 byte padding) + 4 (last packet padding) + 4 (MaxBulkOutsize align padding) */

#ifdef PCI_MSI_SUPPORT
#define RTMP_MSI_ENABLE(_pAd) \
	{     POS_COOKIE _pObj = (POS_COOKIE)(_pAd->OS_Cookie); \
		(_pAd)->HaveMsi = pci_enable_msi(_pObj->pci_dev) == 0 ? TRUE : FALSE; \
	}

#define RTMP_MSI_DISABLE(_pci_dev, _pHaveMsi)	\
	{											\
		if (*(_pHaveMsi) == TRUE)				\
			pci_disable_msi(_pci_dev);			\
		*(_pHaveMsi) = FALSE;					\
	}

#else
#define RTMP_MSI_ENABLE(_pAd)					do{}while(0)
#define RTMP_MSI_DISABLE(_pci_dev, _pHaveMsi)	do{}while(0)
#endif /* PCI_MSI_SUPPORT */

#define RTMP_PCI_DMA_TODEVICE		0xFF00
#define RTMP_PCI_DMA_FROMDEVICE		0xFF01




#define UNLINK_TIMEOUT_MS		3

#define USBD_TRANSFER_DIRECTION_OUT		0
#define USBD_TRANSFER_DIRECTION_IN		0
#define USBD_SHORT_TRANSFER_OK			0
#define PURB			purbb_t

#define OS_RTMP_MlmeUp					RtmpOsMlmeUp

#endif /* __RTMP_UTIL_H__ */
