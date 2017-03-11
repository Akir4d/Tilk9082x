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
#ifndef __USB_OPS_H_
#define __USB_OPS_H_


#define REALTEK_USB_VENQT_READ		0xC0
#define REALTEK_USB_VENQT_WRITE	0x40
#define REALTEK_USB_VENQT_CMD_REQ	0x05
#define REALTEK_USB_VENQT_CMD_IDX	0x00
#define REALTEK_USB_IN_INT_EP_IDX	1

enum{
	VENDOR_WRITE = 0x00,
	VENDOR_READ = 0x01,
};
#define ALIGNMENT_UNIT				16
#define MAX_VENDOR_REQ_CMD_SIZE	254		//9083cu SIE Support
#define MAX_USB_IO_CTL_SIZE		(MAX_VENDOR_REQ_CMD_SIZE +ALIGNMENT_UNIT)

#ifdef PLATFORM_LINUX
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,12)) 
#define tlw_usb_control_msg(dev, pipe, request, requesttype, value, index, data, size, timeout_ms) \
	usb_control_msg((dev), (pipe), (request), (requesttype), (value), (index), (data), (size), (timeout_ms)) 
#define tlw_usb_bulk_msg(usb_dev, pipe, data, len, actual_length, timeout_ms) \
	usb_bulk_msg((usb_dev), (pipe), (data), (len), (actual_length), (timeout_ms))
#else
#define tlw_usb_control_msg(dev, pipe, request, requesttype, value, index, data, size,timeout_ms) \
	usb_control_msg((dev), (pipe), (request), (requesttype), (value), (index), (data), (size), \
		((timeout_ms) == 0) ||((timeout_ms)*HZ/1000>0)?((timeout_ms)*HZ/1000):1) 
#define tlw_usb_bulk_msg(usb_dev, pipe, data, len, actual_length, timeout_ms) \
	usb_bulk_msg((usb_dev), (pipe), (data), (len), (actual_length), \
		((timeout_ms) == 0) ||((timeout_ms)*HZ/1000>0)?((timeout_ms)*HZ/1000):1) 
#endif
#include <usb_ops_linux.h>
#endif //PLATFORM_LINUX

#ifdef CONFIG_TLL9083E
void ttl9083eu_set_hw_type(struct dvobj_priv *pdvobj);
void ttl9083eu_set_intf_ops(struct _io_ops *pops);
#ifdef CONFIG_SUPPORT_USB_INT
void interrupt_handler_9083eu(_adapter *padapter, u16 pkt_len, u8 *pbuf);
#endif
#endif

#if defined(CONFIG_TLL8812A) || defined(CONFIG_TLL8821A)
void ttl8812au_set_hw_type(struct dvobj_priv *pdvobj);
void ttl8812au_set_intf_ops(struct _io_ops *pops);
#ifdef CONFIG_SUPPORT_USB_INT
void interrupt_handler_8812au(_adapter *padapter, u16 pkt_len, u8 *pbuf);
#endif
#endif

#ifdef CONFIG_TLL8814A
void ttl8814au_set_hw_type(struct dvobj_priv *pdvobj);
void ttl8814au_set_intf_ops(struct _io_ops	*pops);
#ifdef CONFIG_SUPPORT_USB_INT
void interrupt_handler_8814au(_adapter *padapter, u16 pkt_len, u8 *pbuf);
#endif
#endif /* CONFIG_TLL8814 */

#ifdef CONFIG_TLL9081E
void ttl9081eu_set_hw_type(struct dvobj_priv *pdvobj);
void ttl9081eu_set_intf_ops(struct _io_ops *pops);
#ifdef CONFIG_SUPPORT_USB_INT
void interrupt_handler_9081eu(_adapter *padapter, u16 pkt_len, u8 *pbuf);
#endif

#endif

#ifdef CONFIG_TLL9083F
void ttl9083fu_set_hw_type(struct dvobj_priv *pdvobj);
void ttl9083fu_set_intf_ops(struct _io_ops *pops);
void ttl9083fu_recv_tasklet(void *priv);
void ttl9083fu_xmit_tasklet(void *priv);
#ifdef CONFIG_SUPPORT_USB_INT
void interrupt_handler_9083fu(_adapter *padapter, u16 pkt_len, u8 *pbuf);
#endif
#endif

#ifdef CONFIG_TLL8723B
void ttl8723bu_set_hw_type(struct dvobj_priv *pdvobj);
void ttl8723bu_set_intf_ops(struct _io_ops *pops);
void ttl8723bu_recv_tasklet(void *priv);
void ttl8723bu_xmit_tasklet(void *priv);
#ifdef CONFIG_SUPPORT_USB_INT
void interrupt_handler_8723bu(_adapter *padapter, u16 pkt_len, u8 *pbuf);
#endif
#endif


enum TLW_USB_SPEED {
	TLW_USB_SPEED_UNKNOWN	= 0,
	TLW_USB_SPEED_1_1	= 1,
	TLW_USB_SPEED_2		= 2,
	TLW_USB_SPEED_3		= 3,
};

#define IS_FULL_SPEED_USB(Adapter)	(adapter_to_dvobj(Adapter)->usb_speed == TLW_USB_SPEED_1_1)
#define IS_HIGH_SPEED_USB(Adapter)	(adapter_to_dvobj(Adapter)->usb_speed == TLW_USB_SPEED_2)
#define IS_SUPER_SPEED_USB(Adapter)	(adapter_to_dvobj(Adapter)->usb_speed == TLW_USB_SPEED_3)

#define USB_SUPER_SPEED_BULK_SIZE	1024	// usb 3.0
#define USB_HIGH_SPEED_BULK_SIZE	512		// usb 2.0
#define USB_FULL_SPEED_BULK_SIZE	64		// usb 1.1

static inline u8 tlw_usb_bulk_size_boundary(_adapter * padapter,int buf_len)
{
	u8 rst = _TRUE;

	if (IS_SUPER_SPEED_USB(padapter))
		rst = (0 == (buf_len) % USB_SUPER_SPEED_BULK_SIZE)?_TRUE:_FALSE;
	if (IS_HIGH_SPEED_USB(padapter))
		rst = (0 == (buf_len) % USB_HIGH_SPEED_BULK_SIZE)?_TRUE:_FALSE;	
	else	
		rst = (0 == (buf_len) % USB_FULL_SPEED_BULK_SIZE)?_TRUE:_FALSE;		
	return rst;
}


#endif //__USB_OPS_H_

