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
#ifndef __INC_HAL9083EPHYCFG_H__
#define __INC_HAL9083EPHYCFG_H__


/*--------------------------Define Parameters-------------------------------*/
#define LOOP_LIMIT				5
#define MAX_STALL_TIME			50		//us
#define AntennaDiversityValue		0x80	//(Adapter->bSoftwareAntennaDiversity ? 0x00:0x80)
#define MAX_TXPWR_IDX_NMODE_92S	63
#define Reset_Cnt_Limit			3

#ifdef CONFIG_PCI_HCI
#define MAX_AGGR_NUM	0x0B
#else
#define MAX_AGGR_NUM	0x07
#endif // CONFIG_PCI_HCI


/*--------------------------Define Parameters-------------------------------*/


/*------------------------------Define structure----------------------------*/ 

#define	MAX_TX_COUNT_9083E			1

/* BB/RF related */


/*------------------------------Define structure----------------------------*/ 


/*------------------------Export global variable----------------------------*/
/*------------------------Export global variable----------------------------*/


/*------------------------Export Marco Definition---------------------------*/
/*------------------------Export Marco Definition---------------------------*/


/*--------------------------Exported Function prototype---------------------*/
//
// BB and RF register read/write
//
u32	PHY_QueryBBReg9083E(	IN	PADAPTER	Adapter,
								IN	u32		RegAddr,
								IN	u32		BitMask	);
void	PHY_SetBBReg9083E(	IN	PADAPTER	Adapter,
								IN	u32		RegAddr,
								IN	u32		BitMask,
								IN	u32		Data	);
u32	PHY_QueryRFReg9083E(	IN	PADAPTER	Adapter,
								IN	u8				eRFPath,
								IN	u32				RegAddr,
								IN	u32				BitMask	);
void	PHY_SetRFReg9083E(	IN	PADAPTER		Adapter,
								IN	u8				eRFPath,
								IN	u32				RegAddr,
								IN	u32				BitMask,
								IN	u32				Data	);

//
// Initialization related function
//
/* MAC/BB/RF HAL config */
int	PHY_MACConfig9083E(IN	PADAPTER	Adapter	);
int	PHY_BBConfig9083E(IN	PADAPTER	Adapter	);
int	PHY_RFConfig9083E(IN	PADAPTER	Adapter	);

/* RF config */
int	ttl9083e_PHY_ConfigRFWithParaFile(IN PADAPTER Adapter, IN u8 * pFileName, u8 eRFPath);

//
// RF Power setting
//
//extern	BOOLEAN	PHY_SetRFPowerState(IN	PADAPTER			Adapter, 
//									IN	RT_RF_POWER_STATE	eRFPowerState);

//
// BB TX Power R/W
//
void	PHY_GetTxPowerLevel9083E(	IN	PADAPTER		Adapter,
											OUT s32*    		powerlevel	);
void	PHY_SetTxPowerLevel9083E(	IN	PADAPTER		Adapter,
											IN	u8			channel	);
BOOLEAN	PHY_UpdateTxPowerDbm9083E(	IN	PADAPTER	Adapter,
											IN	int		powerInDbm	);

VOID
PHY_SetTxPowerIndex_9083E(
	IN	PADAPTER			Adapter,
	IN	u32					PowerIndex,
	IN	u8					RFPath,	
	IN	u8					Rate
	);

u8
PHY_GetTxPowerIndex_9083E(
	IN	PADAPTER		pAdapter,
	IN	u8				RFPath,
	IN	u8				Rate,	
	IN	CHANNEL_WIDTH	BandWidth,	
	IN	u8				Channel
	);

//
// Switch bandwidth for 9081S
//
//extern	void	PHY_SetBWModeCallback9081C(	IN	PRT_TIMER		pTimer	);
void	PHY_SetBWMode9083E(	IN	PADAPTER			pAdapter,
									IN	CHANNEL_WIDTH	ChnlWidth,
									IN	unsigned char	Offset	);

//
// Set FW CMD IO for 9081S.
//
//extern	BOOLEAN HalSetIO9081C(	IN	PADAPTER			Adapter,
//									IN	IO_TYPE				IOType);

//
// Set A2 entry to fw for 9081S
//
extern	void FillA2Entry9081C(		IN	PADAPTER			Adapter,
										IN	u8				index,
										IN	u8*				val);


//
// channel switch related funciton
//
//extern	void	PHY_SwChnlCallback9081C(	IN	PRT_TIMER		pTimer	);
void	PHY_SwChnl9083E(	IN	PADAPTER		pAdapter,
									IN	u8			channel	);

VOID
PHY_SetSwChnlBWMode9083E(
	IN	PADAPTER			Adapter,
	IN	u8					channel,
	IN	CHANNEL_WIDTH	Bandwidth,
	IN	u8					Offset40,
	IN	u8					Offset80
);

//
// BB/MAC/RF other monitor API
//
void	PHY_SetMonitorMode9081C(IN	PADAPTER	pAdapter,
										IN	BOOLEAN		bEnableMonitorMode	);

BOOLEAN	PHY_CheckIsLegalRfPath9081C(IN	PADAPTER	pAdapter,
											IN	u32		eRFPath	);

VOID PHY_SetRFPathSwitch_9083E(IN	PADAPTER	pAdapter, IN	BOOLEAN		bMain);

extern	VOID
PHY_SwitchEphyParameter(
	IN	PADAPTER			Adapter
	);

extern	VOID
PHY_EnableHostClkReq(
	IN	PADAPTER			Adapter
	);

BOOLEAN
SetAntennaConfig92C(
	IN	PADAPTER	Adapter,
	IN	u8		DefaultAnt	
	);

VOID
storePwrIndexDiffRateOffset(
	IN	PADAPTER	Adapter,
	IN	u32		RegAddr,
	IN	u32		BitMask,
	IN	u32		Data
	);
/*--------------------------Exported Function prototype---------------------*/

//
// Initialization related function
//
/* MAC/BB/RF HAL config */
//extern s32 PHY_MACConfig8723(PADAPTER padapter);
//s32 PHY_BBConfig8723(PADAPTER padapter);
//s32 PHY_RFConfig8723(PADAPTER padapter);



//==================================================================
// Note: If SIC_ENABLE under PCIE, because of the slow operation
//	you should 
//	2) "#define TLL8723_FPGA_VERIFICATION	1"				in Precomp.h.WlanE.Windows
//	3) "#define TLL8190_Download_Firmware_From_Header	0"	in Precomp.h.WlanE.Windows if needed.
//
#if (TLL9083E_SUPPORT == 1) && (TLL9083E_FPGA_TRUE_PHY_VERIFICATION == 1)
#define	SIC_ENABLE				1
#define	SIC_HW_SUPPORT		1
#else
#define	SIC_ENABLE				0
#define	SIC_HW_SUPPORT		0
#endif
//==================================================================


#define	SIC_MAX_POLL_CNT		5

#if(SIC_HW_SUPPORT == 1)
#define	SIC_CMD_READY			0
#define	SIC_CMD_PREWRITE		0x1
#if(TLL9083E_SUPPORT == 1)
#define	SIC_CMD_WRITE			0x40
#define	SIC_CMD_PREREAD		0x2
#define	SIC_CMD_READ			0x80
#define	SIC_CMD_INIT			0xf0
#define	SIC_INIT_VAL			0xff

#define	SIC_INIT_REG			0x1b7
#define	SIC_CMD_REG			0x1EB		// 1byte
#define	SIC_ADDR_REG			0x1E8		// 1b4~1b5, 2 bytes
#define	SIC_DATA_REG			0x1EC		// 1b0~1b3
#else
#define	SIC_CMD_WRITE			0x11
#define	SIC_CMD_PREREAD		0x2
#define	SIC_CMD_READ			0x12
#define	SIC_CMD_INIT			0x1f
#define	SIC_INIT_VAL			0xff

#define	SIC_INIT_REG			0x1b7
#define	SIC_CMD_REG			0x1b6		// 1byte
#define	SIC_ADDR_REG			0x1b4		// 1b4~1b5, 2 bytes
#define	SIC_DATA_REG			0x1b0		// 1b0~1b3
#endif
#else
#define	SIC_CMD_READY			0
#define	SIC_CMD_WRITE			1
#define	SIC_CMD_READ			2

#if(TLL9083E_SUPPORT == 1)
#define	SIC_CMD_REG			0x1EB		// 1byte
#define	SIC_ADDR_REG			0x1E8		// 1b9~1ba, 2 bytes
#define	SIC_DATA_REG			0x1EC		// 1bc~1bf
#else
#define	SIC_CMD_REG			0x1b8		// 1byte
#define	SIC_ADDR_REG			0x1b9		// 1b9~1ba, 2 bytes
#define	SIC_DATA_REG			0x1bc		// 1bc~1bf
#endif
#endif

#if(SIC_ENABLE == 1)
VOID SIC_Init(IN PADAPTER Adapter);
#endif


#endif	// __INC_HAL9081CPHYCFG_H

