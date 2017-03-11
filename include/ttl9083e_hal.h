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
#ifndef __TLL9083E_HAL_H__
#define __TLL9083E_HAL_H__

//#include "hal_com.h"
#include "hal_data.h"

//include HAL Related header after HAL Related compiling flags 
#include "ttl9083e_spec.h"
#include "Hal9083EPhyReg.h"
#include "Hal9083EPhyCfg.h"
#include "ttl9083e_rf.h"
#include "ttl9083e_dm.h"
#include "ttl9083e_recv.h"
#include "ttl9083e_xmit.h"
#include "ttl9083e_cmd.h"
#include "ttl9083e_led.h"
#include "Hal9083EPwrSeq.h"
#ifdef DBG_CONFIG_ERROR_DETECT
#include "ttl9083e_sreset.h"
#endif

#if 0
	// Fw Array
	#define Rtl9083E_FwImageArray				Rtl9083EFwImgArray
	#define Rtl9083E_FWImgArrayLength			Rtl9083EFWImgArrayLength
#ifdef CONFIG_WOWLAN
	#define Rtl9083E_FwWoWImageArray			Array_MP_9083E_FW_WoWLAN
	#define Rtl9083E_FwWoWImgArrayLength		ArrayLength_MP_9083E_FW_WoWLAN
#endif //CONFIG_WOWLAN
#endif


	#define TLL9083E_FW_IMG					"ttl9083e/FW_NIC.bin"
	#define TLL9083E_FW_WW_IMG				"ttl9083e/FW_WoWLAN.bin"
	#define TLL9083E_PHY_REG					"ttl9083e/PHY_REG.txt" 
	#define TLL9083E_PHY_RADIO_A				"ttl9083e/RadioA.txt"
	#define TLL9083E_PHY_RADIO_B				"ttl9083e/RadioB.txt"
	#define TLL9083E_TXPWR_TRACK				"ttl9083e/TxPowerTrack.txt"			
	#define TLL9083E_AGC_TAB					"ttl9083e/AGC_TAB.txt"
	#define TLL9083E_PHY_MACREG 				"ttl9083e/MAC_REG.txt"
	#define TLL9083E_PHY_REG_PG				"ttl9083e/PHY_REG_PG.txt"
	#define TLL9083E_PHY_REG_MP 				"ttl9083e/PHY_REG_MP.txt" 
	#define TLL9083E_TXPWR_LMT				"ttl9083e/TXPWR_LMT.txt" 

	//---------------------------------------------------------------------
	//		TLL9083E Power Configuration CMDs for USB/SDIO/PCIE interfaces
	//---------------------------------------------------------------------
	#define Rtl9083E_NIC_PWR_ON_FLOW				ttl9083E_power_on_flow
	#define Rtl9083E_NIC_RF_OFF_FLOW				ttl9083E_radio_off_flow
	#define Rtl9083E_NIC_DISABLE_FLOW				ttl9083E_card_disable_flow
	#define Rtl9083E_NIC_ENABLE_FLOW				ttl9083E_card_enable_flow
	#define Rtl9083E_NIC_SUSPEND_FLOW				ttl9083E_suspend_flow
	#define Rtl9083E_NIC_RESUME_FLOW				ttl9083E_resume_flow
	#define Rtl9083E_NIC_PDN_FLOW					ttl9083E_hwpdn_flow
	#define Rtl9083E_NIC_LPS_ENTER_FLOW			ttl9083E_enter_lps_flow
	#define Rtl9083E_NIC_LPS_LEAVE_FLOW			ttl9083E_leave_lps_flow


#if 1 // download firmware related data structure
#define MAX_FW_9083E_SIZE			0x8000 //32768,32k / 16384,16k

#define FW_9083E_SIZE				0x4000 //16384,16k
#define FW_9083E_SIZE_2			0x8000 //32768,32k 

#define FW_9083E_START_ADDRESS	0x1000
#define FW_9083E_END_ADDRESS		0x1FFF //0x5FFF


#define IS_FW_HEADER_EXIST_88E(_pFwHdr)	((le16_to_cpu(_pFwHdr->Signature)&0xFFF0) == 0x88E0)

typedef struct _RT_FIRMWARE_9083E {
	FIRMWARE_SOURCE	eFWSource;
#ifdef CONFIG_EMBEDDED_FWIMG
	u8*			szFwBuffer;
#else
	u8			szFwBuffer[MAX_FW_9083E_SIZE];
#endif
	u32			ulFwLength;
} RT_FIRMWARE_9083E, *PRT_FIRMWARE_9083E;

//
// This structure must be cared byte-ordering
//

typedef struct _RT_9083E_FIRMWARE_HDR
{
	// 8-byte alinment required

	//--- LONG WORD 0 ----
	u16		Signature;	// 92C0: test chip; 92C, 88C0: test chip; 88C1: MP A-cut; 92C1: MP A-cut
	u8		Category;	// AP/NIC and USB/PCI
	u8		Function;	// Reserved for different FW function indcation, for further use when driver needs to download different FW in different conditions
	u16		Version;		// FW Version
	u8		Subversion;	// FW Subversion, default 0x00
	u16		Rsvd1;


	//--- LONG WORD 1 ----
	u8		Month;	// Release time Month field
	u8		Date;	// Release time Date field
	u8		Hour;	// Release time Hour field
	u8		Minute;	// Release time Minute field
	u16		RamCodeSize;	// The size of RAM code
	u8		Foundry;
	u8		Rsvd2;

	//--- LONG WORD 2 ----
	u32		SvnIdx;	// The SVN entry index
	u32		Rsvd3;

	//--- LONG WORD 3 ----
	u32		Rsvd4;
	u32		Rsvd5;
}RT_9083E_FIRMWARE_HDR, *PRT_9083E_FIRMWARE_HDR;
#endif // download firmware related data structure


#define DRIVER_EARLY_INT_TIME_9083E			0x05
#define BCN_DMA_ATIME_INT_TIME_9083E		0x02


//#define MAX_RX_DMA_BUFFER_SIZE_88E	      0x2400 //9k for 88E nornal chip , //MaxRxBuff=10k-max(TxReportSize(64*8), WOLPattern(16*24))
#define RX_DMA_SIZE_88E(__Adapter) ((!IS_VENDOR_9083E_I_CUT_SERIES(__Adapter))?0x2800:0x4000)

#ifdef CONFIG_WOWLAN
#define RESV_FMWF	WKFMCAM_SIZE*MAX_WKFM_NUM /* 16 entries, for each is 24 bytes*/
#else
#define RESV_FMWF	0
#endif

#define RX_DMA_RESERVD_FW_FEATURE	0x200 /* for tx report (64*8) */

#define MAX_RX_DMA_BUFFER_SIZE_88E(__Adapter) RX_DMA_SIZE_88E(__Adapter)-RX_DMA_RESERVD_FW_FEATURE

#define MAX_TX_REPORT_BUFFER_SIZE			0x0400 /* 1k */

// Note: We will divide number of page equally for each queue other than public queue!
// 22k = 22528 bytes = 176 pages (@page =  128 bytes)
// must reserved about 7 pages for LPS =>  176-7 = 169 (0xA9)
// 2*BCN / 1*ps-poll / 1*null-data /1*prob_rsp /1*QOS null-data /1*BT QOS null-data 

#define BCNQ_PAGE_NUM_88E		0x08

//For WoWLan , more reserved page
#if defined(CONFIG_WOWLAN) && defined(CONFIG_GTK_OL)
#define WOWLAN_PAGE_NUM_88E	0x05
#else
#define WOWLAN_PAGE_NUM_88E	0x00
#endif

/* Note: 
Tx FIFO Size : previous CUT:22K /I_CUT after:32KB
Tx page Size : 128B
Total page numbers : 176(0xB0) / 256(0x100)
*/
#define TOTAL_PAGE_NUMBER_88E(_Adapter)	((IS_VENDOR_9083E_I_CUT_SERIES(_Adapter)?0x100:0xB0) - 1)/* must reserved 1 page for dma issue */
#define TX_TOTAL_PAGE_NUMBER_88E(_Adapter)	(TOTAL_PAGE_NUMBER_88E(_Adapter) - BCNQ_PAGE_NUM_88E - WOWLAN_PAGE_NUM_88E)
#define TX_PAGE_BOUNDARY_88E(_Adapter)		(TX_TOTAL_PAGE_NUMBER_88E(_Adapter) + 1) /* beacon header start address */

#define WMM_NORMAL_TX_TOTAL_PAGE_NUMBER_88E(_Adapter)	TX_TOTAL_PAGE_NUMBER_88E(_Adapter)
#define WMM_NORMAL_TX_PAGE_BOUNDARY_88E(_Adapter)		(WMM_NORMAL_TX_TOTAL_PAGE_NUMBER_88E(_Adapter) + 1)

// For Normal Chip Setting
// (HPQ + LPQ + NPQ + PUBQ) shall be TX_TOTAL_PAGE_NUMBER_8723B
#define NORMAL_PAGE_NUM_HPQ_88E		0x0
#define NORMAL_PAGE_NUM_LPQ_88E		0x09
#define NORMAL_PAGE_NUM_NPQ_88E		0x0

// Note: For Normal Chip Setting, modify later
#define WMM_NORMAL_PAGE_NUM_HPQ_88E		0x29
#define WMM_NORMAL_PAGE_NUM_LPQ_88E		0x1C
#define WMM_NORMAL_PAGE_NUM_NPQ_88E		0x1C


//-------------------------------------------------------------------------
//	Chip specific
//-------------------------------------------------------------------------
#define CHIP_BONDING_IDENTIFIER(_value)	(((_value)>>22)&0x3)
#define CHIP_BONDING_92C_1T2R	0x1
#define CHIP_BONDING_88C_USB_MCARD	0x2
#define CHIP_BONDING_88C_USB_HP	0x1

//-------------------------------------------------------------------------
//	Channel Plan
//-------------------------------------------------------------------------


#define EFUSE_REAL_CONTENT_LEN		512
#define EFUSE_MAP_LEN				128
#define EFUSE_MAX_SECTION			16
#define EFUSE_IC_ID_OFFSET			506	//For some inferiority IC purpose. added by Roger, 2009.09.02.
#define AVAILABLE_EFUSE_ADDR(addr) 	(addr < EFUSE_REAL_CONTENT_LEN)
//
// <Roger_Notes>
// To prevent out of boundary programming case,
// leave 1byte and program full section
// 9bytes + 1byt + 5bytes and pre 1byte.
// For worst case:
// | 1byte|----8bytes----|1byte|--5bytes--| 
// |         |            Reserved(14bytes)	      |
//
#define EFUSE_OOB_PROTECT_BYTES 		15	// PG data exclude header, dummy 6 bytes frome CP test and reserved 1byte.

#define		EFUSE_REAL_CONTENT_LEN_88E	256
#define		EFUSE_MAP_LEN_88E		512
#define		EFUSE_MAX_SECTION_88E		64
#define		EFUSE_MAX_WORD_UNIT_88E		4
#define		EFUSE_IC_ID_OFFSET_88E			506	//For some inferiority IC purpose. added by Roger, 2009.09.02.
#define 		AVAILABLE_EFUSE_ADDR_88E(addr) 	(addr < EFUSE_REAL_CONTENT_LEN_88E)
// <Roger_Notes> To prevent out of boundary programming case, leave 1byte and program full section
// 9bytes + 1byt + 5bytes and pre 1byte.
// For worst case:
// | 2byte|----8bytes----|1byte|--7bytes--| //92D
#define 		EFUSE_OOB_PROTECT_BYTES_88E	18 	// PG data exclude header, dummy 7 bytes frome CP test and reserved 1byte.
#define		EFUSE_PROTECT_BYTES_BANK_88E	16


//========================================================
//			EFUSE for BT definition
//========================================================
#define EFUSE_BT_REAL_CONTENT_LEN		1536	// 512*3
#define EFUSE_BT_MAP_LEN				1024	// 1k bytes
#define EFUSE_BT_MAX_SECTION			128		// 1024/8

#define EFUSE_PROTECT_BYTES_BANK		16

#define INCLUDE_MULTI_FUNC_BT(_Adapter)	(GET_HAL_DATA(_Adapter)->MultiFunc & RT_MULTI_FUNC_BT)
#define INCLUDE_MULTI_FUNC_GPS(_Adapter)	(GET_HAL_DATA(_Adapter)->MultiFunc & RT_MULTI_FUNC_GPS)

//#define IS_MULTI_FUNC_CHIP(_Adapter)	(((((PHAL_DATA_TYPE)(_Adapter->HalData))->MultiFunc) & (RT_MULTI_FUNC_BT|RT_MULTI_FUNC_GPS)) ? _TRUE : _FALSE)

//#define RT_IS_FUNC_DISABLED(__pAdapter, __FuncBits) ( (__pAdapter)->DisabledFunctions & (__FuncBits) )

#ifdef CONFIG_PCI_HCI
 /* according to the define in the tlw_xmit.h, tlw_recv.h */
#define TX_DESC_NUM_9083EE  TXDESC_NUM   /* 128 */
#ifdef CONFIG_CONCURRENT_MODE
/*#define BE_QUEUE_TX_DESC_NUM_9083EE  (TXDESC_NUM<<1)*/    		/* 256 */
#define BE_QUEUE_TX_DESC_NUM_9083EE  ((TXDESC_NUM<<1)+(TXDESC_NUM>>1))    /* 320 */
/*#define BE_QUEUE_TX_DESC_NUM_9083EE  ((TXDESC_NUM<<1)+TXDESC_NUM)*/    /* 384 */
#else
#define BE_QUEUE_TX_DESC_NUM_9083EE  TXDESC_NUM /* 128 */
/*#define BE_QUEUE_TX_DESC_NUM_9083EE  (TXDESC_NUM+(TXDESC_NUM>>1)) *//* 192 */
#endif

void InterruptRecognized9083EE(PADAPTER Adapter, PRT_ISR_CONTENT pIsrContent);
void UpdateInterruptMask9083EE(PADAPTER Adapter, u32 AddMSR, u32 AddMSR1, u32 RemoveMSR, u32 RemoveMSR1);
#endif	//CONFIG_PCI_HCI

// ttl9083e_hal_init.c

s32 ttl9083e_FirmwareDownload(PADAPTER padapter, BOOLEAN  bUsedWoWLANFw);
void _8051Reset88E(PADAPTER padapter);
void ttl9083e_InitializeFirmwareVars(PADAPTER padapter);


s32 InitLLTTable(PADAPTER padapter, u8 txpktbuf_bndy);

// EFuse
u8 GetEEPROMSize9083E(PADAPTER padapter);
void Hal_InitPGData88E(PADAPTER padapter);
void Hal_EfuseParseIDCode88E(PADAPTER padapter, u8 *hwinfo);
void Hal_ReadTxPowerInfo88E(PADAPTER padapter,u8* hwinfo,BOOLEAN	AutoLoadFail);
	
void Hal_EfuseParseEEPROMVer88E(PADAPTER padapter, u8 *hwinfo, BOOLEAN AutoLoadFail);
void ttl9083e_EfuseParseChnlPlan(PADAPTER padapter, u8 *hwinfo, BOOLEAN AutoLoadFail);
void Hal_EfuseParseCustomerID88E(PADAPTER padapter, u8 *hwinfo, BOOLEAN AutoLoadFail);
void Hal_ReadAntennaDiversity88E	(PADAPTER pAdapter,u8*PROMContent,BOOLEAN AutoLoadFail);
void Hal_ReadThermalMeter_88E(PADAPTER	Adapter,u8* PROMContent,BOOLEAN 	AutoloadFail);
void Hal_EfuseParseXtal_9083E(PADAPTER pAdapter,u8* hwinfo,BOOLEAN AutoLoadFail);
void Hal_EfuseParseBoardType88E(PADAPTER pAdapter,u8* hwinfo,BOOLEAN AutoLoadFail);
void Hal_ReadPowerSavingMode88E(PADAPTER pAdapter,u8* hwinfo,BOOLEAN AutoLoadFail);

BOOLEAN HalDetectPwrDownMode88E(PADAPTER Adapter);
	
#if defined(CONFIG_WOWLAN) || defined(CONFIG_AP_WOWLAN)
void Hal_DetectWoWMode(PADAPTER pAdapter);
#endif //CONFIG_WOWLAN


#ifdef CONFIG_RF_GAIN_OFFSET
void Hal_ReadRFGainOffset(PADAPTER pAdapter,u8* hwinfo,BOOLEAN AutoLoadFail);
#endif //CONFIG_RF_GAIN_OFFSET

void ttl9083e_init_default_value(_adapter *adapter);

void ttl9083e_set_hal_ops(struct hal_ops *pHalFunc);

// register
void SetBcnCtrlReg(PADAPTER padapter, u8 SetBits, u8 ClearBits);

void ttl9083e_start_thread(_adapter *padapter);
void ttl9083e_stop_thread(_adapter *padapter);

void tlw_IOL_cmd_tx_pkt_buf_dump(ADAPTER *Adapter,int data_len);
#ifdef CONFIG_IOL_EFUSE_PATCH
s32 ttl9083e_iol_efuse_patch(PADAPTER padapter);
#endif//CONFIG_IOL_EFUSE_PATCH
void _InitTransferPageSize(PADAPTER padapter);

void SetHwReg9083E(PADAPTER padapter, u8 variable, u8 *val);
void GetHwReg9083E(PADAPTER padapter, u8 variable, u8 *val);
void ResumeTxBeacon(PADAPTER padapter);
void StopTxBeacon(PADAPTER padapter);
u8
GetHalDefVar9083E(
	IN	PADAPTER				Adapter,
	IN	HAL_DEF_VARIABLE		eVariable,
	IN	PVOID					pValue
	);
#endif //__TLL9083E_HAL_H__

