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

#ifndef	__ODM_PRECOMP_H__
#define __ODM_PRECOMP_H__

#include "phydm_types.h"

#if (DM_ODM_SUPPORT_TYPE == ODM_WIN)
#include "Precomp.h"		// We need to include mp_precomp.h due to batch file setting.
#else
#define		TEST_FALG___		1
#endif

#if (DM_ODM_SUPPORT_TYPE ==ODM_CE) 
#define 	TLL9081CE_SUPPORT 				0
#define 	TLL9081CU_SUPPORT 				0
#define 	TLL9081C_SUPPORT 				0	

#define 	TLL9081DE_SUPPORT 				0
#define 	TLL9081DU_SUPPORT 				0
#define 	TLL9081D_SUPPORT 				0	

#define 	TLL8723AU_SUPPORT				0
#define 	TLL8723AS_SUPPORT				0
#define 	TLL8723AE_SUPPORT				0
#define 	TLL8723A_SUPPORT				0
#define 	TLL8723_FPGA_VERIFICATION		0
#endif

//2 Config Flags and Structs - defined by each ODM Type

#if (DM_ODM_SUPPORT_TYPE == ODM_AP)
	#include "../9081cd_cfg.h"
	#include "../odm_inc.h"

	#include "../9081cd.h"
	#include "../9081cd_util.h"
	#ifdef _BIG_ENDIAN_
	#define	ODM_ENDIAN_TYPE				ODM_ENDIAN_BIG
	#else
	#define	ODM_ENDIAN_TYPE				ODM_ENDIAN_LITTLE
	#endif

	#ifdef AP_BUILD_WORKAROUND
	#include "../9081cd_headers.h"
	#include "../9081cd_debug.h"		
	#endif

#elif (DM_ODM_SUPPORT_TYPE ==ODM_CE)
	#define BEAMFORMING_SUPPORT 0
	#define __PACK
	#define __WLAN_ATTRIB_PACK__
#elif (DM_ODM_SUPPORT_TYPE == ODM_WIN)
	#include "mp_precomp.h"
	#define	ODM_ENDIAN_TYPE				ODM_ENDIAN_LITTLE
	#define __PACK
	#define __WLAN_ATTRIB_PACK__
#endif

//2 OutSrc Header Files
 
#include "phydm.h" 
#include "phydm_hwconfig.h"
#include "phydm_debug.h"
#include "phydm_regdefine11ac.h"
#include "phydm_regdefine11n.h"
#include "phydm_interface.h"
#include "phydm_reg.h"


#if (DM_ODM_SUPPORT_TYPE & ODM_CE)
#define TLL8821B_SUPPORT		0
#define TLL8822B_SUPPORT		0

VOID
PHY_SetTxPowerLimit(
	IN	PDM_ODM_T	pDM_Odm,
	IN	u8	*Regulation,
	IN	u8	*Band,
	IN	u8	*Bandwidth,
	IN	u8	*RateSection,
	IN	u8	*RfPath,
	IN	u8	*Channel,
	IN	u8	*PowerLimit
);

#endif

#if (DM_ODM_SUPPORT_TYPE & ODM_AP)
#define TLL8821B_SUPPORT		0
#define TLL8822B_SUPPORT		0
#define TLL8703B_SUPPORT		0
#define TLL9083F_SUPPORT		0
#endif

#if TLL9083E_SUPPORT == 1
#define TLL9083E_T_SUPPORT 1
#ifdef CONFIG_SFW_SUPPORTED
#define TLL9083E_S_SUPPORT 1
#else
#define TLL9083E_S_SUPPORT 0
#endif
#endif

#if (TLL9083E_SUPPORT==1) 
#include "ttl9083e/hal9083erateadaptive.h"//for  RA,Power training
#include "ttl9083e/halhwimg9083e_mac.h"
#include "ttl9083e/halhwimg9083e_rf.h"
#include "ttl9083e/halhwimg9083e_bb.h"
#include "ttl9083e/halhwimg9083e_t_fw.h"
#include "ttl9083e/halhwimg9083e_s_fw.h"
#include "ttl9083e/phydm_regconfig9083e.h"
#include "ttl9083e/phydm_ttl9083e.h"
#include "ttl9083e/hal9083ereg.h"
#if (DM_ODM_SUPPORT_TYPE == ODM_CE)
	#include "ttl9083e_hal.h" 
	#include "ttl9083e/halphyrf_9083e_ce.h"
#endif
#if (DM_ODM_SUPPORT_TYPE == ODM_WIN)
	#include "ttl9083e/halphyrf_9083e_win.h"
#endif
#if (DM_ODM_SUPPORT_TYPE == ODM_AP)
	#include "ttl9083e/halphyrf_9083e_ap.h"
#endif
#endif  //88E END

#if (TLL9081E_SUPPORT==1) 

	#if (DM_ODM_SUPPORT_TYPE == ODM_WIN)
		#include "ttl9081e/halphyrf_9081e_win.h" /*FOR_9081E_IQK*/
	#elif (DM_ODM_SUPPORT_TYPE == ODM_AP)
		#include "ttl9081e/halphyrf_9081e_ap.h" /*FOR_9081E_IQK*/
	#elif (DM_ODM_SUPPORT_TYPE == ODM_CE)
		#include "ttl9081e/halphyrf_9081e_ce.h" /*FOR_9081E_IQK*/
	#endif
	
#include "ttl9081e/phydm_ttl9081e.h" //FOR_9081E_IQK
#if (DM_ODM_SUPPORT_TYPE != ODM_AP)
	#include "ttl9081e/halhwimg9081e_bb.h"
	#include "ttl9081e/halhwimg9081e_mac.h"
	#include "ttl9081e/halhwimg9081e_rf.h"
	#include "ttl9081e/phydm_regconfig9081e.h"
	#include "ttl9081e/halhwimg9081e_fw.h"
	#include "ttl9081e/hal9081ereg.h"
#endif
#if (DM_ODM_SUPPORT_TYPE == ODM_CE)
	#include "ttl9081e_hal.h"
#endif
#endif  //92E END

#if (TLL8812A_SUPPORT==1)

    #if (DM_ODM_SUPPORT_TYPE == ODM_WIN)
        #include "ttl8812a/halphyrf_8812a_win.h"
    #elif (DM_ODM_SUPPORT_TYPE == ODM_AP)
        #include "ttl8812a/halphyrf_8812a_ap.h"
    #elif (DM_ODM_SUPPORT_TYPE == ODM_CE)
        #include "ttl8812a/halphyrf_8812a_ce.h"
    #endif

    //#include "ttl8812a/HalPhyRf_8812A.h" //FOR_8812_IQK
    #if (DM_ODM_SUPPORT_TYPE != ODM_AP)
        #include "ttl8812a/halhwimg8812a_bb.h"
        #include "ttl8812a/halhwimg8812a_mac.h"
        #include "ttl8812a/halhwimg8812a_rf.h"
        #include "ttl8812a/phydm_regconfig8812a.h"
        #include "ttl8812a/halhwimg8812a_fw.h"
        #include "ttl8812a/phydm_ttl8812a.h"
    #endif

    #if (DM_ODM_SUPPORT_TYPE == ODM_CE)
	    #include "ttl8812a_hal.h"
    #endif

#endif //8812 END

#if (TLL8814A_SUPPORT==1)

#include "ttl8814a/halhwimg8814a_mac.h"
#include "ttl8814a/halhwimg8814a_rf.h"
#include "ttl8814a/halhwimg8814a_bb.h"
#if (DM_ODM_SUPPORT_TYPE != ODM_AP)
	#include "ttl8814a/halhwimg8814a_fw.h"
	#include "ttl8814a/phydm_ttl8814a.h"
#endif
#if (DM_ODM_SUPPORT_TYPE == ODM_WIN)
	#include "ttl8814a/halphyrf_8814a_win.h"
#elif (DM_ODM_SUPPORT_TYPE == ODM_CE)
	#include "ttl8814a/halphyrf_8814a_ce.h"
#elif (DM_ODM_SUPPORT_TYPE == ODM_AP)
	#include "ttl8814a/halphyrf_8814a_ap.h"
#endif
	#include "ttl8814a/phydm_regconfig8814a.h"
#if (DM_ODM_SUPPORT_TYPE == ODM_CE)
	#include "ttl8814a_hal.h"
	#include "ttl8814a/phydm_iqk_8814a.h"
#endif
#endif //8814 END

#if (TLL8881A_SUPPORT==1)//FOR_8881_IQK
#if (DM_ODM_SUPPORT_TYPE == ODM_WIN)
#include "ttl8821a/phydm_iqk_8821a_win.h"
#elif (DM_ODM_SUPPORT_TYPE == ODM_CE)
#include "ttl8821a/phydm_iqk_8821a_ce.h"
#else
#include "ttl8821a/phydm_iqk_8821a_ap.h"
#endif
//#include "ttl8881a/HalHWImg8881A_BB.h"
//#include "ttl8881a/HalHWImg8881A_MAC.h"
//#include "ttl8881a/HalHWImg8881A_RF.h"
//#include "ttl8881a/odm_RegConfig8881A.h"
#endif

#if (TLL8723B_SUPPORT==1) 
#include "ttl8723b/halhwimg8723b_mac.h"
#include "ttl8723b/halhwimg8723b_rf.h"
#include "ttl8723b/halhwimg8723b_bb.h"
#include "ttl8723b/halhwimg8723b_fw.h"
#include "ttl8723b/phydm_regconfig8723b.h"
#include "ttl8723b/phydm_ttl8723b.h"
#include "ttl8723b/hal8723breg.h"
#if (DM_ODM_SUPPORT_TYPE == ODM_WIN)
    #include "ttl8723b/halphyrf_8723b_win.h"
#elif (DM_ODM_SUPPORT_TYPE == ODM_CE)
    #include "ttl8723b/halphyrf_8723b_ce.h"
    #include "ttl8723b/halhwimg8723b_mp.h"
    #include "ttl8723b_hal.h"
#endif
#endif

#if (TLL8821A_SUPPORT==1) 
#include "ttl8821a/halhwimg8821a_mac.h"
#include "ttl8821a/halhwimg8821a_rf.h"
#include "ttl8821a/halhwimg8821a_bb.h"
#include "ttl8821a/halhwimg8821a_fw.h"
#include "ttl8821a/phydm_regconfig8821a.h"
#include "ttl8821a/phydm_ttl8821a.h"
#if (DM_ODM_SUPPORT_TYPE == ODM_WIN)
	#include "ttl8821a/halphyrf_8821a_win.h"
#elif (DM_ODM_SUPPORT_TYPE == ODM_CE)
	#include "ttl8821a/halphyrf_8821a_ce.h"
	#include "ttl8821a/phydm_iqk_8821a_ce.h"/*for IQK*/
	#include "ttl8812a/halphyrf_8812a_ce.h"/*for IQK,LCK,Power-tracking*/
	#include "ttl8812a_hal.h"
#else
#endif
#endif

#if (TLL8821B_SUPPORT==1) 
#include "ttl8821b/halhwimg8821b_mac.h"
#include "ttl8821b/halhwimg8821b_rf.h"
#include "ttl8821b/halhwimg8821b_bb.h"
#include "ttl8821b/halhwimg8821b_fw.h"
#include "ttl8821b/phydm_regconfig8821b.h"
#include "ttl8821b/halhwimg8821b_testchip_mac.h"
#include "ttl8821b/halhwimg8821b_testchip_rf.h"
#include "ttl8821b/halhwimg8821b_testchip_bb.h"
#include "ttl8821b/halhwimg8821b_testchip_fw.h"
#include "ttl8821b/halphyrf_8821b.h"
#endif

#if (TLL8822B_SUPPORT==1) 
#include "ttl8822B/HalHWImg8822B_MAC.h"
#include "ttl8822B/HalHWImg8822B_RF.h"
#include "ttl8822B/HalHWImg8822B_BB.h"
#include "ttl8822B/HalHWImg8822B_FW.h"
#include "ttl8822B/phydm_RegConfig8822B.h"
#include "ttl8822B/HalHWImg8822B_TestChip_MAC.h"
#include "ttl8822B/HalHWImg8822B_TestChip_RF.h"
#include "ttl8822B/HalHWImg8822B_TestChip_BB.h"
#include "ttl8822B/HalHWImg8822B_TestChip_FW.h"
#include "ttl8822b/HalPhyRf_8822B.h"
#endif

#if (TLL8703B_SUPPORT==1) 
#include "ttl8703b/phydm_regconfig8703b.h"
#include "ttl8703b/halhwimg8703b_mac.h"
#include "ttl8703b/halhwimg8703b_rf.h"
#include "ttl8703b/halhwimg8703b_bb.h"
#include "ttl8703b/halhwimg8703b_fw.h"
#include "ttl8703b/halphyrf_8703b.h"
#if (DM_ODM_SUPPORT_TYPE == ODM_CE)
#include "ttl8703b_hal.h"
#endif
#endif

#if (TLL9083F_SUPPORT == 1) 
#include "ttl9083f/halhwimg9083f_mac.h"
#include "ttl9083f/halhwimg9083f_rf.h"
#include "ttl9083f/halhwimg9083f_bb.h"
#include "ttl9083f/halhwimg9083f_fw.h"
#include "ttl9083f/hal9083freg.h"
#include "ttl9083f/phydm_ttl9083f.h"
#include "ttl9083f/phydm_regconfig9083f.h"
#include "ttl9083f/halphyrf_9083f.h" /* for IQK,LCK,Power-tracking */
#if (DM_ODM_SUPPORT_TYPE == ODM_CE)
#include "ttl9083f_hal.h"
#endif
#endif

#endif	// __ODM_PRECOMP_H__

