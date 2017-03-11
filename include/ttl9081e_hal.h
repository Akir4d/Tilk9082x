/******************************************************************************
 *
 * Copyright(c) 2007 - 2013 Realtek Corporation. All rights reserved.
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
#ifndef __TLL9081E_HAL_H__
#define __TLL9081E_HAL_H__

//#include "hal_com.h"

#include "hal_data.h"

//include HAL Related header after HAL Related compiling flags 
#include "ttl9081e_spec.h"
#include "ttl9081e_rf.h"
#include "ttl9081e_dm.h"
#include "ttl9081e_recv.h"
#include "ttl9081e_xmit.h"
#include "ttl9081e_cmd.h"
#include "ttl9081e_led.h"
#include "Hal9081EPwrSeq.h"
#include "Hal9081EPhyReg.h"
#include "Hal9081EPhyCfg.h"


#ifdef DBG_CONFIG_ERROR_DETECT
#include "ttl9081e_sreset.h"
#endif


//---------------------------------------------------------------------
//		TLL9081E From header
//---------------------------------------------------------------------
	#define TLL9081E_FW_IMG					"ttl9081e/FW_NIC.bin"
	#define TLL9081E_FW_WW_IMG				"ttl9081e/FW_WoWLAN.bin"
	#define TLL9081E_PHY_REG					"ttl9081e/PHY_REG.txt" 
	#define TLL9081E_PHY_RADIO_A				"ttl9081e/RadioA.txt"
	#define TLL9081E_PHY_RADIO_B				"ttl9081e/RadioB.txt"
	#define TLL9081E_TXPWR_TRACK				"ttl9081e/TxPowerTrack.txt"
	#define TLL9081E_AGC_TAB					"ttl9081e/AGC_TAB.txt"
	#define TLL9081E_PHY_MACREG 				"ttl9081e/MAC_REG.txt"
	#define TLL9081E_PHY_REG_PG				"ttl9081e/PHY_REG_PG.txt"
	#define TLL9081E_PHY_REG_MP 				"ttl9081e/PHY_REG_MP.txt" 
	#define TLL9081E_TXPWR_LMT					"ttl9081e/TXPWR_LMT.txt"
	#define TLL9081E_WIFI_ANT_ISOLATION		"ttl9081e/wifi_ant_isolation.txt"

//---------------------------------------------------------------------
//		TLL9081E Power Configuration CMDs for PCIe interface
//---------------------------------------------------------------------
#define Rtl9081E_NIC_PWR_ON_FLOW				ttl9081E_power_on_flow
#define Rtl9081E_NIC_RF_OFF_FLOW				ttl9081E_radio_off_flow
#define Rtl9081E_NIC_DISABLE_FLOW				ttl9081E_card_disable_flow
#define Rtl9081E_NIC_ENABLE_FLOW				ttl9081E_card_enable_flow
#define Rtl9081E_NIC_SUSPEND_FLOW				ttl9081E_suspend_flow
#define Rtl9081E_NIC_RESUME_FLOW				ttl9081E_resume_flow
#define Rtl9081E_NIC_PDN_FLOW					ttl9081E_hwpdn_flow
#define Rtl9081E_NIC_LPS_ENTER_FLOW			ttl9081E_enter_lps_flow
#define Rtl9081E_NIC_LPS_LEAVE_FLOW			ttl9081E_leave_lps_flow	


#if 1 // download firmware related data structure
#define FW_SIZE_9081E			0x8000 // Compatible with TLL9081e Maximal RAM code size 32k
#define FW_START_ADDRESS		0x1000
#define FW_END_ADDRESS			0x5FFF


#define IS_FW_HEADER_EXIST_9081E(_pFwHdr)	((GET_FIRMWARE_HDR_SIGNATURE_9081E(_pFwHdr) &0xFFF0) ==  0x92E0)



typedef struct _RT_FIRMWARE_9081E {
	FIRMWARE_SOURCE	eFWSource;
#ifdef CONFIG_EMBEDDED_FWIMG
	u8*			szFwBuffer;
#else
	u8			szFwBuffer[FW_SIZE_9081E];
#endif
	u32			ulFwLength;
} RT_FIRMWARE_9081E, *PRT_FIRMWARE_9081E;

//
// This structure must be cared byte-ordering
//
// Added by tynli. 2009.12.04.

//=====================================================
//					Firmware Header(8-byte alinment required)
//=====================================================
//--- LONG WORD 0 ----
#define GET_FIRMWARE_HDR_SIGNATURE_9081E(__FwHdr)		LE_BITS_TO_4BYTE(__FwHdr, 0, 16) // 92C0: test chip; 92C, 88C0: test chip; 88C1: MP A-cut; 92C1: MP A-cut
#define GET_FIRMWARE_HDR_CATEGORY_9081E(__FwHdr)		LE_BITS_TO_4BYTE(__FwHdr, 16, 8) // AP/NIC and USB/PCI
#define GET_FIRMWARE_HDR_FUNCTION_9081E(__FwHdr)		LE_BITS_TO_4BYTE(__FwHdr, 24, 8) // Reserved for different FW function indcation, for further use when driver needs to download different FW in different conditions
#define GET_FIRMWARE_HDR_VERSION_9081E(__FwHdr)			LE_BITS_TO_4BYTE(__FwHdr+4, 0, 16)// FW Version
#define GET_FIRMWARE_HDR_SUB_VER_9081E(__FwHdr)			LE_BITS_TO_4BYTE(__FwHdr+4, 16, 8) // FW Subversion, default 0x00
#define GET_FIRMWARE_HDR_RSVD1_9081E(__FwHdr)			LE_BITS_TO_4BYTE(__FwHdr+4, 24, 8) 		

//--- LONG WORD 1 ----
#define GET_FIRMWARE_HDR_MONTH_9081E(__FwHdr)			LE_BITS_TO_4BYTE(__FwHdr+8, 0, 8) // Release time Month field
#define GET_FIRMWARE_HDR_DATE_9081E(__FwHdr)			LE_BITS_TO_4BYTE(__FwHdr+8, 8, 8) // Release time Date field
#define GET_FIRMWARE_HDR_HOUR_9081E(__FwHdr)			LE_BITS_TO_4BYTE(__FwHdr+8, 16, 8)// Release time Hour field
#define GET_FIRMWARE_HDR_MINUTE_9081E(__FwHdr)			LE_BITS_TO_4BYTE(__FwHdr+8, 24, 8)// Release time Minute field
#define GET_FIRMWARE_HDR_ROMCODE_SIZE_9081E(__FwHdr)	LE_BITS_TO_4BYTE(__FwHdr+12, 0, 16)// The size of RAM code
#define GET_FIRMWARE_HDR_RSVD2_9081E(__FwHdr)			LE_BITS_TO_4BYTE(__FwHdr+12, 16, 16)

//--- LONG WORD 2 ----
#define GET_FIRMWARE_HDR_SVN_IDX_9081E(__FwHdr)			LE_BITS_TO_4BYTE(__FwHdr+16, 0, 32)// The SVN entry index
#define GET_FIRMWARE_HDR_RSVD3_9081E(__FwHdr)			LE_BITS_TO_4BYTE(__FwHdr+20, 0, 32)

//--- LONG WORD 3 ----
#define GET_FIRMWARE_HDR_RSVD4_9081E(__FwHdr)			LE_BITS_TO_4BYTE(__FwHdr+24, 0, 32)
#define GET_FIRMWARE_HDR_RSVD5_9081E(__FwHdr)			LE_BITS_TO_4BYTE(__FwHdr+28, 0, 32)

#endif // download firmware related data structure

#define DRIVER_EARLY_INT_TIME_9081E		0x05
#define BCN_DMA_ATIME_INT_TIME_9081E		0x02
#define RX_DMA_SIZE_9081E					0x4000	/* 16K*/

#ifdef CONFIG_WOWLAN
#define RESV_FMWF	WKFMCAM_SIZE*MAX_WKFM_NUM /* 16 entries, for each is 24 bytes*/
#else
#define RESV_FMWF	0
#endif

#ifdef CONFIG_FW_C2H_DEBUG 
	#define RX_DMA_RESERVED_SIZE_9081E	0x100	/* 256B, reserved for c2h debug message*/
#else
	#define RX_DMA_RESERVED_SIZE_9081E	0x40	/* 64B, reserved for c2h event(16bytes) or ccx(8 Bytes )*/
#endif
#define MAX_RX_DMA_BUFFER_SIZE_9081E		(RX_DMA_SIZE_9081E-RX_DMA_RESERVED_SIZE_9081E)	/*RX 16K*/

//For General Reserved Page Number(Beacon Queue is reserved page)
//if (CONFIG_2BCN_EN) Beacon:4, PS-Poll:1, Null Data:1,Prob Rsp:1,Qos Null Data:1
//Beacon:2, PS-Poll:1, Null Data:1,Prob Rsp:1,Qos Null Data:1
#define RSVD_PAGE_NUM_9081E		0x08
//For WoWLan , more reserved page
//ARP Rsp:1, RWC:1, GTK Info:1,GTK RSP:2,GTK EXT MEM:2, PNO: 6
#ifdef CONFIG_WOWLAN
#define WOWLAN_PAGE_NUM_9081E	0x07
#else
#define WOWLAN_PAGE_NUM_9081E	0x00
#endif

#ifdef CONFIG_PNO_SUPPORT
#undef WOWLAN_PAGE_NUM_9081E
#define WOWLAN_PAGE_NUM_9081E	0x0d
#endif

/* Note: 
Tx FIFO Size : 64KB
Tx page Size : 256B
Total page numbers : 256(0x100)
*/

#define	TOTAL_RSVD_PAGE_NUMBER_9081E 	(RSVD_PAGE_NUM_9081E+WOWLAN_PAGE_NUM_9081E)

#define	TOTAL_PAGE_NUMBER_9081E	(0x100) 
#define	TX_TOTAL_PAGE_NUMBER_9081E	(TOTAL_PAGE_NUMBER_9081E - TOTAL_RSVD_PAGE_NUMBER_9081E)

#define	TX_PAGE_BOUNDARY_9081E	( TX_TOTAL_PAGE_NUMBER_9081E ) /* beacon header start address */


#define PAGE_SIZE_TX_92E	PAGE_SIZE_256
#define RSVD_PKT_LEN_92E	(TOTAL_RSVD_PAGE_NUMBER_9081E *PAGE_SIZE_TX_92E)

#define TX_PAGE_LOAD_FW_BOUNDARY_9081E		0x47 //0xA5
#define TX_PAGE_BOUNDARY_WOWLAN_9081E		0xE0

// For Normal Chip Setting
// (HPQ + LPQ + NPQ + PUBQ) shall be TX_TOTAL_PAGE_NUMBER_92C

#define NORMAL_PAGE_NUM_HPQ_9081E			0x10
#define NORMAL_PAGE_NUM_LPQ_9081E			0x10
#define NORMAL_PAGE_NUM_NPQ_9081E			0x10
#define NORMAL_PAGE_NUM_EPQ_9081E			0x00


//Note: For WMM Normal Chip Setting ,modify later
#define WMM_NORMAL_PAGE_NUM_HPQ_9081E		NORMAL_PAGE_NUM_HPQ_9081E
#define WMM_NORMAL_PAGE_NUM_LPQ_9081E		NORMAL_PAGE_NUM_LPQ_9081E
#define WMM_NORMAL_PAGE_NUM_NPQ_9081E		NORMAL_PAGE_NUM_NPQ_9081E


//-------------------------------------------------------------------------
//	Chip specific
//-------------------------------------------------------------------------

// pic buffer descriptor
#define TLL9081EE_SEG_NUM			TX_BUFFER_SEG_NUM
#define TX_DESC_NUM_92E			128
#define RX_DESC_NUM_92E			128

//-------------------------------------------------------------------------
//	Channel Plan
//-------------------------------------------------------------------------

#define		HWSET_MAX_SIZE_9081E			512

#define		EFUSE_REAL_CONTENT_LEN_9081E	512

#define		EFUSE_MAP_LEN_9081E			512
#define		EFUSE_MAX_SECTION_9081E		64
#define		EFUSE_MAX_WORD_UNIT_9081E		4
#define		EFUSE_IC_ID_OFFSET_9081E		506	//For some inferiority IC purpose. added by Roger, 2009.09.02.
#define 		AVAILABLE_EFUSE_ADDR_9081E(addr) 	(addr < EFUSE_REAL_CONTENT_LEN_9081E)
//
// <Roger_Notes> To prevent out of boundary programming case, leave 1byte and program full section
// 9bytes + 1byt + 5bytes and pre 1byte.
// For worst case:
// | 1byte|----8bytes----|1byte|--5bytes--| 
// |         |            Reserved(14bytes)	      |
//
#define		EFUSE_OOB_PROTECT_BYTES_9081E 		15	// PG data exclude header, dummy 6 bytes frome CP test and reserved 1byte.



//========================================================
//			EFUSE for BT definition
//========================================================
#define		EFUSE_BT_REAL_BANK_CONTENT_LEN_9081E	512
#define		EFUSE_BT_REAL_CONTENT_LEN_9081E			1024	// 512*2
#define		EFUSE_BT_MAP_LEN_9081E					1024	// 1k bytes
#define		EFUSE_BT_MAX_SECTION_9081E				128		// 1024/8

#define		EFUSE_PROTECT_BYTES_BANK_9081E			16
#define 		EFUSE_MAX_BANK_9081E					3
//===========================================================

#define INCLUDE_MULTI_FUNC_BT(_Adapter)	(GET_HAL_DATA(_Adapter)->MultiFunc & RT_MULTI_FUNC_BT)
#define INCLUDE_MULTI_FUNC_GPS(_Adapter)	(GET_HAL_DATA(_Adapter)->MultiFunc & RT_MULTI_FUNC_GPS)

//#define IS_MULTI_FUNC_CHIP(_Adapter)	(((((PHAL_DATA_TYPE)(_Adapter->HalData))->MultiFunc) & (RT_MULTI_FUNC_BT|RT_MULTI_FUNC_GPS)) ? _TRUE : _FALSE)

//#define RT_IS_FUNC_DISABLED(__pAdapter, __FuncBits) ( (__pAdapter)->DisabledFunctions & (__FuncBits) )

// ttl8812_hal_init.c
void	_8051Reset9081E(PADAPTER padapter);
s32	FirmwareDownload9081E(PADAPTER Adapter, BOOLEAN bUsedWoWLANFw);
void	InitializeFirmwareVars9081E(PADAPTER padapter);

s32	InitLLTTable9081E(PADAPTER padapter, u8 txpktbuf_bndy);

// EFuse
u8	GetEEPROMSize9081E(PADAPTER padapter);
void	hal_InitPGData_9081E(PADAPTER padapter, u8* PROMContent);
void	Hal_EfuseParseIDCode9081E(PADAPTER padapter, u8 *hwinfo);
void	Hal_ReadPROMVersion9081E(PADAPTER padapter, u8 *hwinfo, BOOLEAN AutoLoadFail);
void	Hal_ReadPowerSavingMode9081E(PADAPTER padapter, u8*	hwinfo, BOOLEAN	AutoLoadFail);
void	Hal_ReadTxPowerInfo9081E(PADAPTER padapter,u8* hwinfo,BOOLEAN	AutoLoadFail);
void	Hal_ReadBoardType9081E(PADAPTER pAdapter,u8* hwinfo,BOOLEAN AutoLoadFail);
void	Hal_ReadThermalMeter_9081E(PADAPTER	Adapter,u8* PROMContent,BOOLEAN 	AutoloadFail);
void	Hal_ReadChannelPlan9081E(PADAPTER padapter, u8 *hwinfo, BOOLEAN AutoLoadFail);
void	Hal_EfuseParseXtal_9081E(PADAPTER pAdapter,u8* hwinfo,BOOLEAN AutoLoadFail);
void	Hal_ReadAntennaDiversity9081E(PADAPTER pAdapter,u8* PROMContent,BOOLEAN AutoLoadFail);
void	Hal_ReadPAType_9081E(PADAPTER Adapter,u8* PROMContent, BOOLEAN AutoloadFail);
void	Hal_ReadAmplifierType_9081E(PADAPTER Adapter, u8 *PROMContent, BOOLEAN AutoloadFail);
void	Hal_ReadRFEType_9081E(PADAPTER Adapter, u8 *PROMContent, BOOLEAN AutoloadFail);
void	Hal_EfuseParseBTCoexistInfo9081E(PADAPTER Adapter, u8* hwinfo, BOOLEAN AutoLoadFail);
u8 Hal_CrystalAFEAdjust(_adapter * Adapter);

BOOLEAN HalDetectPwrDownMode9081E(PADAPTER Adapter);
	
#if defined(CONFIG_WOWLAN) || defined(CONFIG_AP_WOWLAN)
void Hal_DetectWoWMode(PADAPTER pAdapter);
#endif //CONFIG_WOWLAN

/***********************************************************/
// TLL9081E-MAC Setting
VOID _InitQueueReservedPage_9081E(IN  PADAPTER Adapter);
VOID _InitQueuePriority_9081E(IN	PADAPTER Adapter);
VOID _InitTxBufferBoundary_9081E(IN PADAPTER Adapter,IN u8 txpktbuf_bndy);
VOID _InitPageBoundary_9081E(IN PADAPTER Adapter);
//VOID _InitTransferPageSize_9081E(IN PADAPTER Adapter);
VOID _InitDriverInfoSize_9081E(IN PADAPTER Adapter,IN u8 drvInfoSize);
VOID _InitRxSetting_9081E(PADAPTER Adapter);
VOID _InitRDGSetting_9081E(PADAPTER Adapter);
void _InitID_9081E(IN  PADAPTER Adapter);
VOID _InitNetworkType_9081E(IN  PADAPTER Adapter);
VOID _InitWMACSetting_9081E(IN PADAPTER Adapter);
VOID _InitAdaptiveCtrl_9081E(IN  PADAPTER Adapter);
VOID _InitRateFallback_9081E(IN  PADAPTER Adapter);
VOID _InitEDCA_9081E( IN  PADAPTER Adapter);
VOID _InitRetryFunction_9081E(	IN  PADAPTER Adapter);
VOID _BBTurnOnBlock_9081E(IN	PADAPTER Adapter);
VOID _InitBeaconParameters_9081E(IN  PADAPTER Adapter);
VOID _InitBeaconMaxError_9081E(
	IN  PADAPTER	Adapter,
	IN	BOOLEAN		InfraMode
	);
void SetBeaconRelatedRegisters9081E(PADAPTER padapter);
VOID hal_ReadRFType_9081E(PADAPTER	Adapter);
// TLL9081E-MAC Setting
/***********************************************************/

void SetHwReg9081E(PADAPTER Adapter, u8 variable, u8* val);
void GetHwReg9081E(PADAPTER Adapter, u8 variable, u8* val);
u8
SetHalDefVar9081E(
	IN	PADAPTER				Adapter,
	IN	HAL_DEF_VARIABLE		eVariable,
	IN	PVOID					pValue
	);
u8
GetHalDefVar9081E(
	IN	PADAPTER				Adapter,
	IN	HAL_DEF_VARIABLE		eVariable,
	IN	PVOID					pValue
	);

void ttl9081e_set_hal_ops(struct hal_ops *pHalFunc);
void ttl9081e_init_default_value(_adapter * padapter);
// register
void SetBcnCtrlReg(PADAPTER padapter, u8 SetBits, u8 ClearBits);

void ttl9081e_start_thread(_adapter *padapter);
void ttl9081e_stop_thread(_adapter *padapter);

#ifdef CONFIG_PCI_HCI
BOOLEAN	InterruptRecognized9081EE(PADAPTER Adapter);
u16	get_txdesc_buf_addr(u16 ff_hwaddr);
#endif

#ifdef CONFIG_SDIO_HCI
#ifdef CONFIG_SDIO_TX_ENABLE_AVAL_INT
void _init_available_page_threshold(PADAPTER padapter, u8 numHQ, u8 numNQ, u8 numLQ, u8 numPubQ);
#endif
#endif

#ifdef CONFIG_BT_COEXIST
void ttl9081e_combo_card_WifiOnlyHwInit(PADAPTER Adapter);
#endif

#endif //__TLL9081E_HAL_H__

