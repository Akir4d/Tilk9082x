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
#ifndef __RTL9083F_HAL_H__
#define __RTL9083F_HAL_H__

#include "hal_data.h"

#include "rtl9083f_spec.h"
#include "rtl9083f_rf.h"
#include "rtl9083f_dm.h"
#include "rtl9083f_recv.h"
#include "rtl9083f_xmit.h"
#include "rtl9083f_cmd.h"
#include "rtl9083f_led.h"
#include "Hal9083FPwrSeq.h"
#include "Hal9083FPhyReg.h"
#include "Hal9083FPhyCfg.h"
#ifdef DBG_CONFIG_ERROR_DETECT
#include "rtl9083f_sreset.h"
#endif


//---------------------------------------------------------------------
//		RTL9083F From file
//---------------------------------------------------------------------
	#define RTL9083F_FW_IMG					"rtl9083f/FW_NIC.bin"
	#define RTL9083F_FW_WW_IMG				"rtl9083f/FW_WoWLAN.bin"
	#define RTL9083F_PHY_REG					"rtl9083f/PHY_REG.txt"
	#define RTL9083F_PHY_RADIO_A				"rtl9083f/RadioA.txt"
	#define RTL9083F_PHY_RADIO_B				"rtl9083f/RadioB.txt"
	#define RTL9083F_TXPWR_TRACK				"rtl9083f/TxPowerTrack.txt" 
	#define RTL9083F_AGC_TAB					"rtl9083f/AGC_TAB.txt"
	#define RTL9083F_PHY_MACREG 				"rtl9083f/MAC_REG.txt"
	#define RTL9083F_PHY_REG_PG				"rtl9083f/PHY_REG_PG.txt"
	#define RTL9083F_PHY_REG_MP				"rtl9083f/PHY_REG_MP.txt"
	#define RTL9083F_TXPWR_LMT 				"rtl9083f/TXPWR_LMT.txt"

//---------------------------------------------------------------------
//		RTL9083F From header
//---------------------------------------------------------------------

#if MP_DRIVER == 1
	#define Rtl9083F_FwBTImgArray				Rtl9083FFwBTImgArray
	#define Rtl9083F_FwBTImgArrayLength		Rtl9083FFwBTImgArrayLength

	#define Rtl9083F_FwMPImageArray			Rtl9083FFwMPImgArray
	#define Rtl9083F_FwMPImgArrayLength		Rtl9083FMPImgArrayLength

	#define Rtl9083F_PHY_REG_Array_MP			Rtl9083F_PHYREG_Array_MP
	#define Rtl9083F_PHY_REG_Array_MPLength	Rtl9083F_PHYREG_Array_MPLength
#endif


#define FW_9083F_SIZE			0x8000
#define FW_9083F_START_ADDRESS	0x1000
#define FW_9083F_END_ADDRESS		0x1FFF //0x5FFF

#define IS_FW_HEADER_EXIST_9083F(_pFwHdr)	((le16_to_cpu(_pFwHdr->Signature)&0xFFF0) == 0x88F0)

typedef struct _RT_FIRMWARE {
	FIRMWARE_SOURCE	eFWSource;
#ifdef CONFIG_EMBEDDED_FWIMG
	u8*			szFwBuffer;
#else
	u8			szFwBuffer[FW_9083F_SIZE];
#endif
	u32			ulFwLength;
} RT_FIRMWARE_9083F, *PRT_FIRMWARE_9083F;

//
// This structure must be cared byte-ordering
//
// Added by tynli. 2009.12.04.
typedef struct _RT_9083F_FIRMWARE_HDR
{
	// 8-byte alinment required

	//--- LONG WORD 0 ----
	u16		Signature;	// 92C0: test chip; 92C, 88C0: test chip; 88C1: MP A-cut; 92C1: MP A-cut
	u8		Category;	// AP/NIC and USB/PCI
	u8		Function;	// Reserved for different FW function indcation, for further use when driver needs to download different FW in different conditions
	u16		Version;		// FW Version
	u16		Subversion;	// FW Subversion, default 0x00

	//--- LONG WORD 1 ----
	u8		Month;	// Release time Month field
	u8		Date;	// Release time Date field
	u8		Hour;	// Release time Hour field
	u8		Minute;	// Release time Minute field
	u16		RamCodeSize;	// The size of RAM code
	u16		Rsvd2;

	//--- LONG WORD 2 ----
	u32		SvnIdx;	// The SVN entry index
	u32		Rsvd3;

	//--- LONG WORD 3 ----
	u32		Rsvd4;
	u32		Rsvd5;
}RT_9083F_FIRMWARE_HDR, *PRT_9083F_FIRMWARE_HDR;

#define DRIVER_EARLY_INT_TIME_9083F		0x05
#define BCN_DMA_ATIME_INT_TIME_9083F		0x02

// for 9083F
// TX 32K, RX 16K, Page size 128B for TX, 8B for RX
#define PAGE_SIZE_TX_9083F			128
#define PAGE_SIZE_RX_9083F			8

#define RX_DMA_SIZE_9083F			0x4000	// 16K
#ifdef CONFIG_FW_C2H_DEBUG 
#define RX_DMA_RESERVED_SIZE_9083F	0x100	// 256B, reserved for c2h debug message
#else
#define RX_DMA_RESERVED_SIZE_9083F	0x80	// 128B, reserved for tx report
#endif

#ifdef CONFIG_WOWLAN
#define RESV_FMWF	WKFMCAM_SIZE*MAX_WKFM_NUM /* 16 entries, for each is 24 bytes*/
#else
#define RESV_FMWF	0
#endif

#define RX_DMA_BOUNDARY_9083F		(RX_DMA_SIZE_9083F - RX_DMA_RESERVED_SIZE_9083F - 1)

// Note: We will divide number of page equally for each queue other than public queue!

//For General Reserved Page Number(Beacon Queue is reserved page)
//Beacon:2, PS-Poll:1, Null Data:1,Qos Null Data:1,BT Qos Null Data:1
#define BCNQ_PAGE_NUM_9083F		0x08
#ifdef CONFIG_CONCURRENT_MODE
#define BCNQ1_PAGE_NUM_9083F		0x08 // 0x04
#else
#define BCNQ1_PAGE_NUM_9083F		0x00
#endif

#ifdef CONFIG_PNO_SUPPORT
#undef BCNQ1_PAGE_NUM_9083F
#define BCNQ1_PAGE_NUM_9083F		0x00 // 0x04
#endif

//For WoWLan , more reserved page
//ARP Rsp:1, RWC:1, GTK Info:1,GTK RSP:2,GTK EXT MEM:2, PNO: 6
#ifdef CONFIG_WOWLAN
#define WOWLAN_PAGE_NUM_9083F	0x07
#else
#define WOWLAN_PAGE_NUM_9083F	0x00
#endif

#ifdef CONFIG_PNO_SUPPORT
#undef WOWLAN_PAGE_NUM_9083F
#define WOWLAN_PAGE_NUM_9083F	0x15
#endif

#ifdef CONFIG_AP_WOWLAN
#define AP_WOWLAN_PAGE_NUM_9083F	0x02
#endif

#define TX_TOTAL_PAGE_NUMBER_9083F	(0xFF - BCNQ_PAGE_NUM_9083F - BCNQ1_PAGE_NUM_9083F - WOWLAN_PAGE_NUM_9083F)
#define TX_PAGE_BOUNDARY_9083F		(TX_TOTAL_PAGE_NUMBER_9083F + 1)

#define WMM_NORMAL_TX_TOTAL_PAGE_NUMBER_9083F	TX_TOTAL_PAGE_NUMBER_9083F
#define WMM_NORMAL_TX_PAGE_BOUNDARY_9083F		(WMM_NORMAL_TX_TOTAL_PAGE_NUMBER_9083F + 1)

// For Normal Chip Setting
// (HPQ + LPQ + NPQ + PUBQ) shall be TX_TOTAL_PAGE_NUMBER_9083F
#define NORMAL_PAGE_NUM_HPQ_9083F		0x0C
#define NORMAL_PAGE_NUM_LPQ_9083F		0x02
#define NORMAL_PAGE_NUM_NPQ_9083F		0x02

// Note: For Normal Chip Setting, modify later
#define WMM_NORMAL_PAGE_NUM_HPQ_9083F		0x30
#define WMM_NORMAL_PAGE_NUM_LPQ_9083F		0x20
#define WMM_NORMAL_PAGE_NUM_NPQ_9083F		0x20


#include "HalVerDef.h"
#include "hal_com.h"

#define EFUSE_OOB_PROTECT_BYTES 		15

#define HAL_EFUSE_MEMORY

#define HWSET_MAX_SIZE_9083F			512
#define EFUSE_REAL_CONTENT_LEN_9083F		512
#define EFUSE_MAP_LEN_9083F				512
#define EFUSE_MAX_SECTION_9083F			64

#define EFUSE_IC_ID_OFFSET			506	//For some inferiority IC purpose. added by Roger, 2009.09.02.
#define AVAILABLE_EFUSE_ADDR(addr) 	(addr < EFUSE_REAL_CONTENT_LEN_9083F)

#define EFUSE_ACCESS_ON			0x69	// For RTL9083 only.
#define EFUSE_ACCESS_OFF			0x00	// For RTL9083 only.

//========================================================
//			EFUSE for BT definition
//========================================================
#define EFUSE_BT_REAL_BANK_CONTENT_LEN	512
#define EFUSE_BT_REAL_CONTENT_LEN		1536	// 512*3
#define EFUSE_BT_MAP_LEN				1024	// 1k bytes
#define EFUSE_BT_MAX_SECTION			128		// 1024/8

#define EFUSE_PROTECT_BYTES_BANK		16

// Description: Determine the types of C2H events that are the same in driver and Fw.
// Fisrt constructed by tynli. 2009.10.09.
typedef enum _C2H_EVT
{
	C2H_DBG = 0,
	C2H_TSF = 1,
	C2H_AP_RPT_RSP = 2,
	C2H_CCX_TX_RPT = 3,	// The FW notify the report of the specific tx packet.
	C2H_BT_RSSI = 4,
	C2H_BT_OP_MODE = 5,
	C2H_EXT_RA_RPT = 6,
	C2H_9083F_BT_INFO = 9,
	C2H_HW_INFO_EXCH = 10,
	C2H_9083F_BT_MP_INFO = 11,
	C2H_9083F_P2P_RPORT = 0x16,
#ifdef CONFIG_FW_C2H_DEBUG
	C2H_9083F_FW_DEBUG = 0xff,
#endif //CONFIG_FW_C2H_DEBUG
	MAX_C2HEVENT
} C2H_EVT;

typedef struct _C2H_EVT_HDR
{
	u8	CmdID;
	u8	CmdLen;
	u8	CmdSeq;
} __attribute__((__packed__)) C2H_EVT_HDR, *PC2H_EVT_HDR;

typedef enum tag_Package_Definition
{
    PACKAGE_DEFAULT,
    PACKAGE_QFN68,
    PACKAGE_TFBGA90,
    PACKAGE_TFBGA80,
    PACKAGE_TFBGA79
}PACKAGE_TYPE_E;

#define INCLUDE_MULTI_FUNC_BT(_Adapter)		(GET_HAL_DATA(_Adapter)->MultiFunc & RT_MULTI_FUNC_BT)
#define INCLUDE_MULTI_FUNC_GPS(_Adapter)	(GET_HAL_DATA(_Adapter)->MultiFunc & RT_MULTI_FUNC_GPS)

// rtl9083a_hal_init.c
s32 rtl9083f_FirmwareDownload(PADAPTER padapter, BOOLEAN  bUsedWoWLANFw);
void rtl9083f_FirmwareSelfReset(PADAPTER padapter);
void rtl9083f_InitializeFirmwareVars(PADAPTER padapter);

void rtl9083f_InitAntenna_Selection(PADAPTER padapter);
void rtl9083f_DeinitAntenna_Selection(PADAPTER padapter);
void rtl9083f_CheckAntenna_Selection(PADAPTER padapter);
void rtl9083f_init_default_value(PADAPTER padapter);

s32 rtl9083f_InitLLTTable(PADAPTER padapter);

s32 CardDisableHWSM(PADAPTER padapter, u8 resetMCU);
s32 CardDisableWithoutHWSM(PADAPTER padapter);

// EFuse
u8 GetEEPROMSize9083F(PADAPTER padapter);
void Hal_InitPGData(PADAPTER padapter, u8 *PROMContent);
void Hal_EfuseParseIDCode(PADAPTER padapter, u8 *hwinfo);
void Hal_EfuseParseTxPowerInfo_9083F(PADAPTER padapter, u8 *PROMContent, BOOLEAN AutoLoadFail);
/* void Hal_EfuseParseBTCoexistInfo_9083F(PADAPTER padapter, u8 *hwinfo, BOOLEAN AutoLoadFail); */
void Hal_EfuseParseEEPROMVer_9083F(PADAPTER padapter, u8 *hwinfo, BOOLEAN AutoLoadFail);
void Hal_EfuseParseChnlPlan_9083F(PADAPTER padapter, u8 *hwinfo, BOOLEAN AutoLoadFail);
void Hal_EfuseParseCustomerID_9083F(PADAPTER padapter, u8 *hwinfo, BOOLEAN AutoLoadFail);
void Hal_EfuseParsePowerSavingMode_9083F(PADAPTER pAdapter, u8 *hwinfo, BOOLEAN AutoLoadFail);
void Hal_EfuseParseAntennaDiversity_9083F(PADAPTER padapter, u8 *hwinfo, BOOLEAN AutoLoadFail);
void Hal_EfuseParseXtal_9083F(PADAPTER pAdapter, u8 *hwinfo, u8 AutoLoadFail);
void Hal_EfuseParseThermalMeter_9083F(PADAPTER padapter, u8 *hwinfo, u8 AutoLoadFail);
VOID Hal_EfuseParsePackageType_9083F(PADAPTER pAdapter,u8* hwinfo,BOOLEAN AutoLoadFail);
void Hal_EfuseParseKFreeData_9083F(PADAPTER pAdapter, u8 *hwinfo, BOOLEAN AutoLoadFail);

#if 0 /* Do not need for rtl9083f */
VOID Hal_EfuseParseVoltage_9083F(PADAPTER pAdapter,u8* hwinfo,BOOLEAN 	AutoLoadFail); 
#endif

#ifdef CONFIG_C2H_PACKET_EN
void rtl9083f_c2h_packet_handler(PADAPTER padapter, u8 *pbuf, u16 length);
#endif

void rtl9083f_set_pll_ref_clk_sel(_adapter *adapter, u8 sel);

void rtl9083f_set_hal_ops(struct hal_ops *pHalFunc);
void SetHwReg9083F(PADAPTER padapter, u8 variable, u8 *val);
void GetHwReg9083F(PADAPTER padapter, u8 variable, u8 *val);
#ifdef CONFIG_C2H_PACKET_EN
void SetHwRegWithBuf9083F(PADAPTER padapter, u8 variable, u8 *pbuf, int len);
#endif // CONFIG_C2H_PACKET_EN
u8 SetHalDefVar9083F(PADAPTER padapter, HAL_DEF_VARIABLE variable, void *pval);
u8 GetHalDefVar9083F(PADAPTER padapter, HAL_DEF_VARIABLE variable, void *pval);

// register
void rtl9083f_InitBeaconParameters(PADAPTER padapter);
void rtl9083f_InitBeaconMaxError(PADAPTER padapter, u8 InfraMode);
void	_InitBurstPktLen_9083FS(PADAPTER Adapter);
void _8051Reset9083(PADAPTER padapter);
#ifdef CONFIG_WOWLAN
void Hal_DetectWoWMode(PADAPTER pAdapter);
#endif //CONFIG_WOWLAN

void rtl9083f_start_thread(_adapter *padapter);
void rtl9083f_stop_thread(_adapter *padapter);

#if defined(CONFIG_CHECK_BT_HANG) && defined(CONFIG_BT_COEXIST)
void rtl9083fs_init_checkbthang_workqueue(_adapter * adapter);
void rtl9083fs_free_checkbthang_workqueue(_adapter * adapter);
void rtl9083fs_cancle_checkbthang_workqueue(_adapter * adapter);
void rtl9083fs_hal_check_bt_hang(_adapter * adapter);
#endif

#ifdef CONFIG_GPIO_WAKEUP
void HalSetOutPutGPIO(PADAPTER padapter, u8 index, u8 OutPutValue);
#endif

int FirmwareDownloadBT(IN PADAPTER Adapter, PRT_MP_FIRMWARE pFirmware);

void CCX_FwC2HTxRpt_9083f(PADAPTER padapter, u8 *pdata, u8 len);
#ifdef CONFIG_FW_C2H_DEBUG
void Debug_FwC2H_9083f(PADAPTER padapter, u8 *pdata, u8 len);
#endif //CONFIG_FW_C2H_DEBUG
s32 c2h_id_filter_ccx_9083f(u8 *buf);
s32 c2h_handler_9083f(PADAPTER padapter, u8 *pC2hEvent);
u8 MRateToHwRate9083F(u8  rate);
u8 HwRateToMRate9083F(u8	 rate);

#ifdef CONFIG_PCI_HCI
BOOLEAN	InterruptRecognized9083FE(PADAPTER Adapter);
VOID	UpdateInterruptMask9083FE(PADAPTER Adapter, u32 AddMSR, u32 AddMSR1, u32 RemoveMSR, u32 RemoveMSR1);
#endif

#endif

