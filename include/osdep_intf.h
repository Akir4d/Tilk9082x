/******************************************************************************
 *
 * Copyright(c) 2007 - 2011 Realtek Corporation. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of version 2 of the GNU General Public License as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110, USA
 *
 *
 ******************************************************************************/

#ifndef __OSDEP_INTF_H_
#define __OSDEP_INTF_H_


struct intf_priv {

	u8 *intf_dev;
	u32	max_iosz; 	//USB2.0: 128, USB1.1: 64, SDIO:64
	u32	max_xmitsz; //USB2.0: unlimited, SDIO:512
	u32	max_recvsz; //USB2.0: unlimited, SDIO:512

	volatile u8 *io_rwmem;
	volatile u8 *allocated_io_rwmem;
	u32	io_wsz; //unit: 4bytes
	u32	io_rsz;//unit: 4bytes
	u8 intf_status;

	void (*_bus_io)(u8 *priv);

/*
Under Sync. IRP (SDIO/USB)
A protection mechanism is necessary for the io_rwmem(read/write protocol)

Under Async. IRP (SDIO/USB)
The protection mechanism is through the pending queue.
*/

	_mutex ioctl_mutex;


#ifdef PLATFORM_LINUX
	#ifdef CONFIG_USB_HCI
	// when in USB, IO is through interrupt in/out endpoints
	struct usb_device 	*udev;
	PURB	piorw_urb;
	u8 io_irp_cnt;
	u8 bio_irp_pending;
	_sema io_retevt;
	_timer	io_timer;
	u8 bio_irp_timeout;
	u8 bio_timer_cancel;
	#endif
#endif

#ifdef PLATFORM_OS_XP
	#ifdef CONFIG_SDIO_HCI
		// below is for io_rwmem...
		PMDL pmdl;
		PSDBUS_REQUEST_PACKET  sdrp;
		PSDBUS_REQUEST_PACKET  recv_sdrp;
		PSDBUS_REQUEST_PACKET  xmit_sdrp;

			PIRP		piorw_irp;

	#endif
	#ifdef CONFIG_USB_HCI
		PURB	piorw_urb;
		PIRP		piorw_irp;
		u8 io_irp_cnt;
		u8 bio_irp_pending;
		_sema io_retevt;
	#endif
#endif

};


#ifdef CONFIG_R871X_TEST
int tlw_start_pseudo_adhoc(_adapter *padapter);
int tlw_stop_pseudo_adhoc(_adapter *padapter);
#endif

struct dvobj_priv *devobj_init(void);
void devobj_deinit(struct dvobj_priv *pdvobj);

u8 tlw_init_drv_sw(_adapter *padapter);
u8 tlw_free_drv_sw(_adapter *padapter);
u8 tlw_reset_drv_sw(_adapter *padapter);
void tlw_dev_unload(PADAPTER padapter);

u32 tlw_start_drv_threads(_adapter *padapter);
void tlw_stop_drv_threads (_adapter *padapter);
#if defined(CONFIG_WOWLAN) || defined(CONFIG_AP_WOWLAN)
void tlw_cancel_dynamic_chk_timer(_adapter *padapter);
#endif
void tlw_cancel_all_timer(_adapter *padapter);

uint loadparam(_adapter *adapter);

#ifdef PLATFORM_LINUX
int tlw_ioctl(struct net_device *dev, struct ifreq *rq, int cmd);

int tlw_init_netdev_name(struct net_device *pnetdev, const char *ifname);
struct net_device *tlw_init_netdev(_adapter *padapter);

void tlw_os_ndev_free(_adapter *adapter);
int tlw_os_ndev_init(_adapter *adapter, char *name);
void tlw_os_ndev_deinit(_adapter *adapter);
void tlw_os_ndevs_unregister(struct dvobj_priv *dvobj);
int tlw_os_ndevs_init(struct dvobj_priv *dvobj);
void tlw_os_ndevs_deinit(struct dvobj_priv *dvobj);

#if (LINUX_VERSION_CODE>=KERNEL_VERSION(2,6,35))
u16 tlw_recv_select_queue(struct sk_buff *skb);
#endif //LINUX_VERSION_CODE>=KERNEL_VERSION(2,6,35)

int tlw_ndev_notifier_register(void);
void tlw_ndev_notifier_unregister(void);

#include "../os_dep/linux/tlw_proc.h"

#ifdef CONFIG_IOCTL_CFG80211
#include "../os_dep/linux/ioctl_cfg80211.h"
#endif //CONFIG_IOCTL_CFG80211

#endif //PLATFORM_LINUX


#ifdef PLATFORM_FREEBSD
extern int tlw_ioctl(struct ifnet * ifp, u_long cmd, caddr_t data);
#endif

void tlw_ips_dev_unload(_adapter *padapter);

#ifdef CONFIG_IPS
int tlw_ips_pwr_up(_adapter *padapter);
void tlw_ips_pwr_down(_adapter *padapter);
#endif

#ifdef CONFIG_CONCURRENT_MODE
struct _io_ops;
_adapter *tlw_drv_if2_init(_adapter *primary_padapter, void (*set_intf_ops)(_adapter *primary_padapter,struct _io_ops *pops));
void tlw_drv_if2_free(_adapter *if2);
void tlw_drv_if2_stop(_adapter *if2);
#ifdef CONFIG_MULTI_VIR_IFACES
struct dvobj_priv;
_adapter *tlw_drv_add_vir_if(_adapter *primary_padapter, void (*set_intf_ops)(_adapter *primary_padapter,struct _io_ops *pops));
void tlw_drv_stop_vir_ifaces(struct dvobj_priv *dvobj);
void tlw_drv_free_vir_ifaces(struct dvobj_priv *dvobj);
#endif //CONFIG_MULTI_VIR_IFACES
#endif

void tlw_ndev_destructor(_nic_hdl ndev);

#ifdef CONFIG_ARP_KEEP_ALIVE
int	tlw_gw_addr_query(_adapter *padapter);
#endif

int tlw_suspend_common(_adapter *padapter);
int tlw_resume_common(_adapter *padapter);

#endif	//_OSDEP_INTF_H_

