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
#ifndef __SDIO_HAL_H__
#define __SDIO_HAL_H__


extern u8 sd_hal_bus_init(PADAPTER padapter);
extern u8 sd_hal_bus_deinit(PADAPTER padapter);

u8 sd_int_isr(PADAPTER padapter);
void sd_int_dpc(PADAPTER padapter);
u8 tlw_set_hal_ops(_adapter *padapter);

#ifdef CONFIG_TLL9083E
void ttl9083es_set_hal_ops(PADAPTER padapter);
#endif

#ifdef CONFIG_TLL8723B
void ttl8723bs_set_hal_ops(PADAPTER padapter);
#endif

#ifdef CONFIG_TLL8821A
void ttl8821as_set_hal_ops(PADAPTER padapter);
#endif

#ifdef CONFIG_TLL9081E
void ttl9081es_set_hal_ops(PADAPTER padapter);
#endif

#ifdef CONFIG_TLL8703B
void ttl8703bs_set_hal_ops(PADAPTER padapter);
#endif

#ifdef CONFIG_TLL9083F
void ttl9083fs_set_hal_ops(PADAPTER padapter);
#endif

#endif //__SDIO_HAL_H__

