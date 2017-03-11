/******************************************************************************
 *
 * Copyright(c) 2013 Realtek Corporation. All rights reserved.
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
#ifndef __TLW_ODM_H__
#define __TLW_ODM_H__

#include <drv_types.h>
#include "../hal/phydm/phydm_types.h"
/*
* This file provides utilities/wrappers for tlw driver to use ODM
*/

void tlw_odm_dbg_comp_msg(void *sel,_adapter *adapter);
void tlw_odm_dbg_comp_set(_adapter *adapter, u64 comps);
void tlw_odm_dbg_level_msg(void *sel,_adapter *adapter);
void tlw_odm_dbg_level_set(_adapter *adapter, u32 level);

void tlw_odm_ability_msg(void *sel, _adapter *adapter);
void tlw_odm_ability_set(_adapter *adapter, u32 ability);

void tlw_odm_adaptivity_config_msg(void *sel, _adapter *adapter);

bool tlw_odm_adaptivity_needed(_adapter *adapter);
void tlw_odm_adaptivity_parm_msg(void *sel,_adapter *adapter);
void tlw_odm_adaptivity_parm_set(_adapter *adapter, s8 TH_L2H_ini, s8 TH_EDCCA_HL_diff, s8 TH_L2H_ini_mode2, s8 TH_EDCCA_HL_diff_mode2, u8 EDCCA_enable);
void tlw_odm_get_perpkt_rssi(void *sel, _adapter *adapter);
void tlw_odm_acquirespinlock(_adapter *adapter,	RT_SPINLOCK_TYPE type);
void tlw_odm_releasespinlock(_adapter *adapter,	RT_SPINLOCK_TYPE type);

#ifdef CONFIG_DFS_MASTER
VOID tlw_odm_radar_detect_reset(_adapter *adapter);
VOID tlw_odm_radar_detect_disable(_adapter *adapter);
VOID tlw_odm_radar_detect_enable(_adapter *adapter);
BOOLEAN tlw_odm_radar_detect(_adapter *adapter);
#endif /* CONFIG_DFS_MASTER */
#endif // __TLW_ODM_H__

