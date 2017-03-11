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
#ifndef __SDIO_OPS_H__
#define __SDIO_OPS_H__


#ifdef PLATFORM_LINUX
#include <sdio_ops_linux.h>
#endif

#ifdef PLATFORM_WINDOWS

#ifdef PLATFORM_OS_XP
#include <sdio_ops_xp.h>
struct async_context
{
	PMDL pmdl;
	PSDBUS_REQUEST_PACKET sdrp;
	unsigned char* r_buf;
	unsigned char* padapter;
};
#endif

#ifdef PLATFORM_OS_CE
#include <sdio_ops_ce.h>
#endif

#endif // PLATFORM_WINDOWS


extern void sdio_set_intf_ops(_adapter *padapter,struct _io_ops *pops);
	
//extern void sdio_func1cmd52_read(struct intf_hdl *pintfhdl, u32 addr, u32 cnt, u8 *rmem);
//extern void sdio_func1cmd52_write(struct intf_hdl *pintfhdl, u32 addr, u32 cnt, u8 *wmem);
extern u8 SdioLocalCmd52Read1Byte(PADAPTER padapter, u32 addr);
extern void SdioLocalCmd52Write1Byte(PADAPTER padapter, u32 addr, u8 v);
extern s32 _sdio_local_read(PADAPTER padapter, u32 addr, u32 cnt, u8 *pbuf);
extern s32 sdio_local_read(PADAPTER padapter, u32 addr, u32 cnt, u8 *pbuf);
extern s32 _sdio_local_write(PADAPTER padapter, u32 addr, u32 cnt, u8 *pbuf);
extern s32 sdio_local_write(PADAPTER padapter, u32 addr, u32 cnt, u8 *pbuf);

u32 _sdio_read32(PADAPTER padapter, u32 addr);
s32 _sdio_write32(PADAPTER padapter, u32 addr, u32 val);

extern void sd_int_hdl(PADAPTER padapter);
extern u8 CheckIPSStatus(PADAPTER padapter);

#ifdef CONFIG_TLL9083E
extern void InitInterrupt9083ESdio(PADAPTER padapter);
extern void EnableInterrupt9083ESdio(PADAPTER padapter);
extern void DisableInterrupt9083ESdio(PADAPTER padapter);
extern void UpdateInterruptMask9083ESdio(PADAPTER padapter, u32 AddMSR, u32 RemoveMSR);
extern u8 HalQueryTxBufferStatus9082ESdio(PADAPTER padapter);
extern u8 HalQueryTxOQTBufferStatus9082ESdio(PADAPTER padapter);
extern void ClearInterrupt9083ESdio(PADAPTER padapter);
#endif // CONFIG_TLL9083E

#ifdef CONFIG_TLL8821A
extern void InitInterrupt8821AS(PADAPTER padapter);
extern void EnableInterrupt8821AS(PADAPTER padapter);
extern void DisableInterrupt8821AS(PADAPTER padapter);
extern u8 HalQueryTxBufferStatus8821AS(PADAPTER padapter);
extern u8 HalQueryTxOQTBufferStatus8821ASdio(PADAPTER padapter);
#endif // CONFIG_TLL9083E

#if defined(CONFIG_WOWLAN) || defined(CONFIG_AP_WOWLAN)
extern u8 RecvOnePkt(PADAPTER padapter, u32 size);
#endif // CONFIG_WOWLAN
#ifdef CONFIG_TLL8723B
extern void InitInterrupt8723BSdio(PADAPTER padapter);
extern void InitSysInterrupt8723BSdio(PADAPTER padapter);
extern void EnableInterrupt8723BSdio(PADAPTER padapter);
extern void DisableInterrupt8723BSdio(PADAPTER padapter);
extern u8 HalQueryTxBufferStatus8723BSdio(PADAPTER padapter);
extern u8 HalQueryTxOQTBufferStatus8723BSdio(PADAPTER padapter);
#if defined(CONFIG_WOWLAN) || defined(CONFIG_AP_WOWLAN)
extern void DisableInterruptButCpwm28723BSdio(PADAPTER padapter);
extern void ClearInterrupt8723BSdio(PADAPTER padapter);
#endif //CONFIG_WOWLAN
#endif


#ifdef CONFIG_TLL9081E
extern void InitInterrupt9081ESdio(PADAPTER padapter);
extern void EnableInterrupt9081ESdio(PADAPTER padapter);
extern void DisableInterrupt9081ESdio(PADAPTER padapter);
extern void UpdateInterruptMask9081ESdio(PADAPTER padapter, u32 AddMSR, u32 RemoveMSR);
extern u8 HalQueryTxBufferStatus9081ESdio(PADAPTER padapter);
extern u8 HalQueryTxOQTBufferStatus9081ESdio(PADAPTER padapter);
extern void ClearInterrupt9081ESdio(PADAPTER padapter);
#endif // CONFIG_TLL9081E

#ifdef CONFIG_TLL8703B
extern void InitInterrupt8703BSdio(PADAPTER padapter);
extern void InitSysInterrupt8703BSdio(PADAPTER padapter);
extern void EnableInterrupt8703BSdio(PADAPTER padapter);
extern void DisableInterrupt8703BSdio(PADAPTER padapter);
extern u8 HalQueryTxBufferStatus8703BSdio(PADAPTER padapter);
extern u8 HalQueryTxOQTBufferStatus8703BSdio(PADAPTER padapter);
#if defined(CONFIG_WOWLAN) || defined(CONFIG_AP_WOWLAN)
extern void DisableInterruptButCpwm28703BSdio(PADAPTER padapter);
extern void ClearInterrupt8703BSdio(PADAPTER padapter);
#endif //CONFIG_WOWLAN
#endif

#ifdef CONFIG_TLL9083F
extern void InitInterrupt9083FSdio(PADAPTER padapter);
extern void InitSysInterrupt9083FSdio(PADAPTER padapter);
extern void EnableInterrupt9083FSdio(PADAPTER padapter);
extern void DisableInterrupt9083FSdio(PADAPTER padapter);
extern u8 HalQueryTxBufferStatus9083FSdio(PADAPTER padapter);
extern u8 HalQueryTxOQTBufferStatus9083FSdio(PADAPTER padapter);
#if defined(CONFIG_WOWLAN) || defined(CONFIG_AP_WOWLAN)
extern void DisableInterruptButCpwm29083FSdio(PADAPTER padapter);
extern void ClearInterrupt9083FSdio(PADAPTER padapter);
#endif /* defined(CONFIG_WOWLAN) || defined(CONFIG_AP_WOWLAN) */
#endif

#endif // !__SDIO_OPS_H__

