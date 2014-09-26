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


#ifdef MULTI_INF_SUPPORT

#include "rtmp_comm.h"
#include "rt_os_util.h"
#include "rt_os_net.h"
#include <linux/pci.h>


/*
	Driver module load/unload function
*/
static int __init wifi_drv_init_module(void)
{
	int status = 0;

#ifdef RTMP_PCI_SUPPORT
	status = rt_pci_init_module();
	if (status)
		printk("Register PCI device driver failed(%d)!\n", status);
#endif /* RTMP_PCI_SUPPORT */



	return status;
}


static void __exit wifi_drv_cleanup_module(void)
{
	int status = 0;

#ifdef RTMP_PCI_SUPPORT
	rt_pci_cleanup_module();
	printk("Unregister PCI device driver\n");
#endif /* RTMP_PCI_SUPPORT */


}


module_init(wifi_drv_init_module);
module_exit(wifi_drv_cleanup_module);

#endif /* MULTI_INF_SUPPORT */

