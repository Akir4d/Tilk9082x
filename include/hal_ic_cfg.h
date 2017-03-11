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
#ifndef __HAL_IC_CFG_H__
#define __HAL_IC_CFG_H__

#define TLL9083E_SUPPORT				0
#define TLL8812A_SUPPORT				0
#define TLL8821A_SUPPORT				0
#define TLL8723B_SUPPORT				0
#define TLL9081E_SUPPORT				0
#define TLL8814A_SUPPORT				0
#define TLL8195A_SUPPORT				0
#define TLL8703B_SUPPORT				0
#define TLL9083F_SUPPORT				0
#define TLL8822B_SUPPORT				0

/*#if (TLL9083E_SUPPORT==1)*/
#define RATE_ADAPTIVE_SUPPORT			0
#define POWER_TRAINING_ACTIVE			0

#ifdef CONFIG_MULTIDRV 
#endif

#ifdef CONFIG_TLL9083E
#undef TLL9083E_SUPPORT
#undef RATE_ADAPTIVE_SUPPORT
#undef POWER_TRAINING_ACTIVE

#define TLL9083E_SUPPORT				1
#define RATE_ADAPTIVE_SUPPORT			1
#define POWER_TRAINING_ACTIVE			1
#endif

#ifdef CONFIG_TLL8812A
#undef TLL8812A_SUPPORT
#define TLL8812A_SUPPORT				1
#endif

#ifdef CONFIG_TLL8821A
#undef TLL8821A_SUPPORT
#define TLL8821A_SUPPORT				1
#endif

#ifdef CONFIG_TLL9081E
#undef TLL9081E_SUPPORT
#define TLL9081E_SUPPORT				1
#endif

#ifdef CONFIG_TLL8723B
#undef TLL8723B_SUPPORT
#define TLL8723B_SUPPORT				1
#endif

#ifdef CONFIG_TLL8814A
#undef TLL8814A_SUPPORT
#define TLL8814A_SUPPORT				1
#endif

#ifdef CONFIG_TLL8703B
#undef TLL8703B_SUPPORT
#define TLL8703B_SUPPORT				1
#endif

#ifdef CONFIG_TLL9083F
#undef TLL9083F_SUPPORT
#define TLL9083F_SUPPORT				1
#endif

#ifdef CONFIG_TLL8822B
#undef TLL8822B_SUPPORT
#define TLL8822B_SUPPORT				1
#endif

#endif /*__HAL_IC_CFG_H__*/

