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

#include "Hal9083EPwrSeq.h"
#include <rtl9083e_hal.h>

/* 
    drivers should parse below arrays and do the corresponding actions
*/
//3 Power on  Array
WLAN_PWR_CFG rtl9083E_power_on_flow[RTL9083E_TRANS_CARDEMU_TO_ACT_STEPS+RTL9083E_TRANS_END_STEPS]=
{
	RTL9083E_TRANS_CARDEMU_TO_ACT
	RTL9083E_TRANS_END
};

//3Radio off Array
WLAN_PWR_CFG rtl9083E_radio_off_flow[RTL9083E_TRANS_ACT_TO_CARDEMU_STEPS+RTL9083E_TRANS_END_STEPS]=
{
	RTL9083E_TRANS_ACT_TO_CARDEMU
	RTL9083E_TRANS_END
};

//3Card Disable Array
WLAN_PWR_CFG rtl9083E_card_disable_flow[RTL9083E_TRANS_ACT_TO_CARDEMU_STEPS+RTL9083E_TRANS_CARDEMU_TO_PDN_STEPS+RTL9083E_TRANS_END_STEPS]=
{
	RTL9083E_TRANS_ACT_TO_CARDEMU
	RTL9083E_TRANS_CARDEMU_TO_CARDDIS
	RTL9083E_TRANS_END
};

//3 Card Enable Array
WLAN_PWR_CFG rtl9083E_card_enable_flow[RTL9083E_TRANS_ACT_TO_CARDEMU_STEPS+RTL9083E_TRANS_CARDEMU_TO_PDN_STEPS+RTL9083E_TRANS_END_STEPS]=
{
	RTL9083E_TRANS_CARDDIS_TO_CARDEMU
	RTL9083E_TRANS_CARDEMU_TO_ACT
	RTL9083E_TRANS_END
};

//3Suspend Array
WLAN_PWR_CFG rtl9083E_suspend_flow[RTL9083E_TRANS_ACT_TO_CARDEMU_STEPS+RTL9083E_TRANS_CARDEMU_TO_SUS_STEPS+RTL9083E_TRANS_END_STEPS]=
{
	RTL9083E_TRANS_ACT_TO_CARDEMU
	RTL9083E_TRANS_CARDEMU_TO_SUS
	RTL9083E_TRANS_END
};

//3 Resume Array
WLAN_PWR_CFG rtl9083E_resume_flow[RTL9083E_TRANS_ACT_TO_CARDEMU_STEPS+RTL9083E_TRANS_CARDEMU_TO_SUS_STEPS+RTL9083E_TRANS_END_STEPS]=
{
	RTL9083E_TRANS_SUS_TO_CARDEMU
	RTL9083E_TRANS_CARDEMU_TO_ACT
	RTL9083E_TRANS_END
};


//3HWPDN Array
WLAN_PWR_CFG rtl9083E_hwpdn_flow[RTL9083E_TRANS_ACT_TO_CARDEMU_STEPS+RTL9083E_TRANS_CARDEMU_TO_PDN_STEPS+RTL9083E_TRANS_END_STEPS]=
{
	RTL9083E_TRANS_ACT_TO_CARDEMU
	RTL9083E_TRANS_CARDEMU_TO_PDN	
	RTL9083E_TRANS_END
};

//3 Enter LPS 
WLAN_PWR_CFG rtl9083E_enter_lps_flow[RTL9083E_TRANS_ACT_TO_LPS_STEPS+RTL9083E_TRANS_END_STEPS]=
{
	//FW behavior
	RTL9083E_TRANS_ACT_TO_LPS	
	RTL9083E_TRANS_END
};

//3 Leave LPS 
WLAN_PWR_CFG rtl9083E_leave_lps_flow[RTL9083E_TRANS_LPS_TO_ACT_STEPS+RTL9083E_TRANS_END_STEPS]=
{
	//FW behavior
	RTL9083E_TRANS_LPS_TO_ACT
	RTL9083E_TRANS_END
};

