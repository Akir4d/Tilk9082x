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
#ifndef __PCI_HAL_H__
#define __PCI_HAL_H__

#ifdef CONFIG_TLL9083E
void ttl9083ee_set_hal_ops(_adapter *padapter);
#endif

#if defined(CONFIG_TLL8812A) || defined(CONFIG_TLL8821A)
void ttl8812ae_set_hal_ops(_adapter *padapter);
#endif

#if defined(CONFIG_TLL9081E)
void ttl9081ee_set_hal_ops(_adapter *padapter);
#endif

#ifdef CONFIG_TLL8723B
void ttl8723be_set_hal_ops(_adapter *padapter);
#endif

#ifdef CONFIG_TLL8814A
void ttl8814ae_set_hal_ops(_adapter *padapter);
#endif

u8 tlw_set_hal_ops(_adapter *padapter);

#endif //__PCIE_HAL_H__

