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
    inf_ppa.c
 
    Abstract:
    Only for Infineon PPA Direct path feature.

	
 
    Revision History:
    Who         When          What
    --------    ----------    ----------------------------------------------
    carella	06-01-2010    Created

 */

#ifdef INF_PPA_SUPPORT

#include "rt_config.h"
#include <linux/skbuff.h>
#include <linux/netdevice.h>

extern INT rt28xx_send_packets(struct sk_buff *skb_p, struct net_device *net_dev);

int ifx_ra_start_xmit(struct net_device *rx_dev, struct net_device *tx_dev, struct sk_buff *skb, int len)
{
	if(tx_dev != NULL)
	{
		SET_OS_PKT_NETDEV(skb, tx_dev);
		rt28xx_send_packets(skb, tx_dev);
	}
	else if(rx_dev != NULL)
	{
		skb->protocol = eth_type_trans(skb, skb->dev);
		netif_rx(skb);
	}
	else
	{
		dev_kfree_skb_any(skb);
	}
	return 0;
}
#endif /* INF_PPA_SUPPORT */
