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
 *******************************************************************************/
#ifndef __TLL9081E_SPEC_H__
#define __TLL9081E_SPEC_H__

#include <drv_conf.h>


//============================================================
//       9081E Regsiter offset definition
//============================================================

//============================================================
//
//============================================================

//-----------------------------------------------------
//
//	0x0000h ~ 0x00FFh	System Configuration
//
//-----------------------------------------------------
#define REG_SYS_SWR_CTRL1_9081E		0x0010	// 1 Byte        
#define REG_SYS_SWR_CTRL2_9081E		0x0014	// 1 Byte      
#define REG_AFE_CTRL1_9081E			0x0024
#define REG_AFE_CTRL2_9081E			0x0028
#define REG_AFE_CTRL3_9081E			0x002c

#define REG_PAD_CTRL1_9081E			0x0064           
#define REG_SDIO_CTRL_9081E			0x0070
#define REG_OPT_CTRL_9081E				0x0074
#define REG_RF_B_CTRL_9081E			0x0076
#define REG_AFE_CTRL4_9081E			0x0078 
#define REG_LDO_SWR_CTRL				0x007C
#define REG_FW_DRV_MSG_9081E			0x0088
#define REG_HMEBOX_E2_E3_9081E		0x008C
#define REG_HIMR0_9081E				0x00B0
#define REG_HISR0_9081E					0x00B4
#define REG_HIMR1_9081E					0x00B8
#define REG_HISR1_9081E					0x00BC

#define REG_SYS_CFG1_9081E				0x00F0
#define REG_SYS_CFG2_9081E				0x00FC 
//-----------------------------------------------------
//
//	0x0100h ~ 0x01FFh	MACTOP General Configuration
//
//-----------------------------------------------------
#define REG_PKTBUF_DBG_ADDR 			(REG_PKTBUF_DBG_CTRL)
#define REG_RXPKTBUF_DBG				(REG_PKTBUF_DBG_CTRL+2)
#define REG_TXPKTBUF_DBG				(REG_PKTBUF_DBG_CTRL+3)
#define REG_WOWLAN_WAKE_REASON		REG_MCUTST_WOWLAN

#define REG_RSVD3_9081E					0x0168
#define REG_C2HEVT_CMD_SEQ_88XX		0x01A1
#define REG_C2hEVT_CMD_CONTENT_88XX	0x01A2
#define REG_C2HEVT_CMD_LEN_88XX		0x01AE

#define REG_HMEBOX_EXT0_9081E			0x01F0
#define REG_HMEBOX_EXT1_9081E			0x01F4
#define REG_HMEBOX_EXT2_9081E			0x01F8
#define REG_HMEBOX_EXT3_9081E			0x01FC

//-----------------------------------------------------
//
//	0x0200h ~ 0x027Fh	TXDMA Configuration
//
//-----------------------------------------------------
#define REG_DWBCN0_CTRL             0x0208
#define REG_DWBCN1_CTRL             0x0228

//-----------------------------------------------------
//
//	0x0280h ~ 0x02FFh	RXDMA Configuration
//
//-----------------------------------------------------
#define REG_RXDMA_9081E					0x0290
#define REG_EARLY_MODE_CONTROL_9081E		0x02BC

#define REG_RSVD5_9081E					0x02F0
#define REG_RSVD6_9081E					0x02F4
#define REG_RSVD7_9081E					0x02F8
#define REG_RSVD8_9081E					0x02FC

//-----------------------------------------------------
//
//	0x0300h ~ 0x03FFh	PCIe
//
//-----------------------------------------------------
#define	REG_PCIE_CTRL_REG_9081E			0x0300
#define	REG_INT_MIG_9081E					0x0304	// Interrupt Migration 
#define	REG_BCNQ_TXBD_DESA_9081E		0x0308	// TX Beacon Descriptor Address
#define	REG_MGQ_TXBD_DESA_9081E			0x0310	// TX Manage Queue Descriptor Address
#define	REG_VOQ_TXBD_DESA_9081E			0x0318	// TX VO Queue Descriptor Address
#define	REG_VIQ_TXBD_DESA_9081E			0x0320	// TX VI Queue Descriptor Address
#define	REG_BEQ_TXBD_DESA_9081E			0x0328	// TX BE Queue Descriptor Address
#define	REG_BKQ_TXBD_DESA_9081E			0x0330	// TX BK Queue Descriptor Address
#define	REG_RXQ_RXBD_DESA_9081E			0x0338	// RX Queue	Descriptor Address
#define 	REG_HI0Q_TXBD_DESA_9081E			0x0340
#define 	REG_HI1Q_TXBD_DESA_9081E			0x0348
#define 	REG_HI2Q_TXBD_DESA_9081E			0x0350
#define 	REG_HI3Q_TXBD_DESA_9081E			0x0358
#define	REG_HI4Q_TXBD_DESA_9081E			0x0360
#define 	REG_HI5Q_TXBD_DESA_9081E			0x0368
#define 	REG_HI6Q_TXBD_DESA_9081E			0x0370
#define 	REG_HI7Q_TXBD_DESA_9081E			0x0378
#define	REG_MGQ_TXBD_NUM_9081E			0x0380
#define	REG_RX_RXBD_NUM_9081E			0x0382
#define	REG_VOQ_TXBD_NUM_9081E			0x0384
#define	REG_VIQ_TXBD_NUM_9081E			0x0386
#define	REG_BEQ_TXBD_NUM_9081E			0x0388
#define	REG_BKQ_TXBD_NUM_9081E			0x038A
#define	REG_HI0Q_TXBD_NUM_9081E			0x038C
#define	REG_HI1Q_TXBD_NUM_9081E			0x038E
#define	REG_HI2Q_TXBD_NUM_9081E			0x0390
#define	REG_HI3Q_TXBD_NUM_9081E			0x0392
#define	REG_HI4Q_TXBD_NUM_9081E			0x0394
#define	REG_HI5Q_TXBD_NUM_9081E			0x0396
#define	REG_HI6Q_TXBD_NUM_9081E			0x0398
#define	REG_HI7Q_TXBD_NUM_9081E			0x039A
#define	REG_TSFTIMER_HCI_9081E			0x039C

//Read Write Point
#define	REG_VOQ_TXBD_IDX_9081E			0x03A0
#define	REG_VIQ_TXBD_IDX_9081E			0x03A4
#define	REG_BEQ_TXBD_IDX_9081E			0x03A8
#define	REG_BKQ_TXBD_IDX_9081E			0x03AC
#define	REG_MGQ_TXBD_IDX_9081E			0x03B0
#define	REG_RXQ_TXBD_IDX_9081E			0x03B4
#define	REG_HI0Q_TXBD_IDX_9081E			0x03B8
#define	REG_HI1Q_TXBD_IDX_9081E			0x03BC
#define	REG_HI2Q_TXBD_IDX_9081E			0x03C0
#define	REG_HI3Q_TXBD_IDX_9081E			0x03C4
#define	REG_HI4Q_TXBD_IDX_9081E			0x03C8
#define	REG_HI5Q_TXBD_IDX_9081E			0x03CC
#define	REG_HI6Q_TXBD_IDX_9081E			0x03D0
#define	REG_HI7Q_TXBD_IDX_9081E			0x03D4

#define	REG_PCIE_HCPWM_9081EE			0x03D8 // ??????
#define	REG_PCIE_HRPWM_9081EE			0x03DC	//PCIe RPWM // ??????
#define	REG_DBI_WDATA_V1_9081E			0x03E8
#define	REG_DBI_RDATA_V1_9081E			0x03EC
#define	REG_DBI_FLAG_V1_9081E				0x03F0
#define 	REG_MDIO_V1_9081E					0x3F4
#define 	REG_PCIE_MIX_CFG_9081E				0x3F8

//-----------------------------------------------------
//
//	0x0400h ~ 0x047Fh	Protocol Configuration
//
//-----------------------------------------------------
#define REG_TXBF_CTRL_9081E				0x042C
#define REG_ARFR0_9081E					0x0444
#define REG_ARFR1_9081E					0x044C
#define REG_CCK_CHECK_9081E				0x0454
#define REG_AMPDU_MAX_TIME_9081E			0x0456
#define REG_BCNQ1_BDNY_9081E				0x0457

#define REG_AMPDU_MAX_LENGTH_9081E	0x0458
#define REG_WMAC_LBK_BUF_HD_9081E			0x045D
#define REG_NDPA_OPT_CTRL_9081E		0x045F
#define REG_DATA_SC_9081E				0x0483
#ifdef CONFIG_WOWLAN
#define REG_TXPKTBUF_IV_LOW             0x0484
#define REG_TXPKTBUF_IV_HIGH            0x0488
#endif
#define REG_ARFR2_9081E					0x048C
#define REG_ARFR3_9081E					0x0494
#define REG_TXRPT_START_OFFSET			0x04AC
#define REG_AMPDU_BURST_MODE_9081E	0x04BC
#define REG_HT_SINGLE_AMPDU_9081E		0x04C7
#define REG_MACID_PKT_DROP0_9081E		0x04D0

//-----------------------------------------------------
//
//	0x0500h ~ 0x05FFh	EDCA Configuration
//
//-----------------------------------------------------
#define REG_CTWND_9081E					0x0572
#define REG_SECONDARY_CCA_CTRL_9081E	0x0577
#define REG_SCH_TXCMD_9081E			0x05F8

//-----------------------------------------------------
//
//	0x0600h ~ 0x07FFh	WMAC Configuration
//
//-----------------------------------------------------
#define REG_MAC_CR_9081E				0x0600

#define REG_MAC_TX_SM_STATE_9081E		0x06B4

// Power
#define REG_BFMER0_INFO_9081E			0x06E4
#define REG_BFMER1_INFO_9081E			0x06EC
#define REG_CSI_RPT_PARAM_BW20_9081E	0x06F4
#define REG_CSI_RPT_PARAM_BW40_9081E	0x06F8
#define REG_CSI_RPT_PARAM_BW80_9081E	0x06FC

// Hardware Port 2
#define REG_BFMEE_SEL_9081E				0x0714
#define REG_SND_PTCL_CTRL_9081E		0x0718


//-----------------------------------------------------
//
//	Redifine register definition for compatibility
//
//-----------------------------------------------------

// TODO: use these definition when using REG_xxx naming rule.
// NOTE: DO NOT Remove these definition. Use later.
#define	ISR_9081E							REG_HISR0_9081E

//----------------------------------------------------------------------------
//       9081E IMR/ISR bits						(offset 0xB0,  8bits)
//----------------------------------------------------------------------------
#define	IMR_DISABLED_9081E					0
// IMR DW0(0x00B0-00B3) Bit 0-31
#define	IMR_TIMER2_9081E					BIT31		// Timeout interrupt 2
#define	IMR_TIMER1_9081E					BIT30		// Timeout interrupt 1	
#define	IMR_PSTIMEOUT_9081E				BIT29		// Power Save Time Out Interrupt
#define	IMR_GTINT4_9081E					BIT28		// When GTIMER4 expires, this bit is set to 1	
#define	IMR_GTINT3_9081E					BIT27		// When GTIMER3 expires, this bit is set to 1	
#define	IMR_TXBCN0ERR_9081E				BIT26		// Transmit Beacon0 Error			
#define	IMR_TXBCN0OK_9081E					BIT25		// Transmit Beacon0 OK			
#define	IMR_TSF_BIT32_TOGGLE_9081E		BIT24		// TSF Timer BIT32 toggle indication interrupt			
#define	IMR_BCNDMAINT0_9081E				BIT20		// Beacon DMA Interrupt 0			
#define	IMR_BCNDERR0_9081E					BIT16		// Beacon Queue DMA OK0			
#define	IMR_HSISR_IND_ON_INT_9081E		BIT15		// HSISR Indicator (HSIMR & HSISR is true, this bit is set to 1)
#define	IMR_BCNDMAINT_E_9081E				BIT14		// Beacon DMA Interrupt Extension for Win7			
#define	IMR_ATIMEND_9081E					BIT12		// CTWidnow End or ATIM Window End
#define	IMR_C2HCMD_9081E					BIT10		// CPU to Host Command INT Status, Write 1 clear	
#define	IMR_CPWM2_9081E					BIT9			// CPU power Mode exchange INT Status, Write 1 clear	
#define	IMR_CPWM_9081E						BIT8			// CPU power Mode exchange INT Status, Write 1 clear	
#define	IMR_HIGHDOK_9081E					BIT7			// High Queue DMA OK	
#define	IMR_MGNTDOK_9081E					BIT6			// Management Queue DMA OK	
#define	IMR_BKDOK_9081E					BIT5			// AC_BK DMA OK		
#define	IMR_BEDOK_9081E					BIT4			// AC_BE DMA OK	
#define	IMR_VIDOK_9081E					BIT3			// AC_VI DMA OK		
#define	IMR_VODOK_9081E					BIT2			// AC_VO DMA OK	
#define	IMR_RDU_9081E						BIT1			// Rx Descriptor Unavailable	
#define	IMR_ROK_9081E						BIT0			// Receive DMA OK

// IMR DW1(0x00B4-00B7) Bit 0-31
#define	IMR_BCNDMAINT7_9081E				BIT27		// Beacon DMA Interrupt 7
#define	IMR_BCNDMAINT6_9081E				BIT26		// Beacon DMA Interrupt 6
#define	IMR_BCNDMAINT5_9081E				BIT25		// Beacon DMA Interrupt 5
#define	IMR_BCNDMAINT4_9081E				BIT24		// Beacon DMA Interrupt 4
#define	IMR_BCNDMAINT3_9081E				BIT23		// Beacon DMA Interrupt 3
#define	IMR_BCNDMAINT2_9081E				BIT22		// Beacon DMA Interrupt 2
#define	IMR_BCNDMAINT1_9081E				BIT21		// Beacon DMA Interrupt 1
#define	IMR_BCNDOK7_9081E					BIT20		// Beacon Queue DMA OK Interrup 7
#define	IMR_BCNDOK6_9081E					BIT19		// Beacon Queue DMA OK Interrup 6
#define	IMR_BCNDOK5_9081E					BIT18		// Beacon Queue DMA OK Interrup 5
#define	IMR_BCNDOK4_9081E					BIT17		// Beacon Queue DMA OK Interrup 4
#define	IMR_BCNDOK3_9081E					BIT16		// Beacon Queue DMA OK Interrup 3
#define	IMR_BCNDOK2_9081E					BIT15		// Beacon Queue DMA OK Interrup 2
#define	IMR_BCNDOK1_9081E					BIT14		// Beacon Queue DMA OK Interrup 1
#define	IMR_ATIMEND_E_9081E				BIT13		// ATIM Window End Extension for Win7
#define	IMR_TXERR_9081E					BIT11		// Tx Error Flag Interrupt Status, write 1 clear.
#define	IMR_RXERR_9081E					BIT10		// Rx Error Flag INT Status, Write 1 clear
#define	IMR_TXFOVW_9081E					BIT9			// Transmit FIFO Overflow
#define	IMR_RXFOVW_9081E					BIT8			// Receive FIFO Overflow

//----------------------------------------------------------------------------
//       9081E Auto LLT bits						(offset 0x224,  8bits)
//----------------------------------------------------------------------------
//224 REG_AUTO_LLT
// move to hal_com_reg.h

//----------------------------------------------------------------------------
//       9081E Auto LLT bits						(offset 0x290,  32bits)
//----------------------------------------------------------------------------
#define BIT_DMA_MODE			BIT1
#define BIT_USB_RXDMA_AGG_EN	BIT31

//----------------------------------------------------------------------------
//       9081E REG_SYS_CFG1						(offset 0xF0,  32bits)
//----------------------------------------------------------------------------
#define BIT_SPSLDO_SEL			BIT24


//----------------------------------------------------------------------------
//       9081E REG_CCK_CHECK						(offset 0x454,  8bits)
//----------------------------------------------------------------------------
#define BIT_BCN_PORT_SEL		BIT5

//============================================================================
//       Regsiter Bit and Content definition 
//============================================================================

//2 ACMHWCTRL 0x05C0
#define	AcmHw_HwEn_9081E				BIT(0)
#define	AcmHw_VoqEn_9081E				BIT(1)
#define	AcmHw_ViqEn_9081E				BIT(2)
#define	AcmHw_BeqEn_9081E				BIT(3)
#define	AcmHw_VoqStatus_9081E			BIT(5)
#define	AcmHw_ViqStatus_9081E			BIT(6)
#define	AcmHw_BeqStatus_9081E			BIT(7)

//========================================================
// General definitions
//========================================================

#define MACID_NUM_9081E 128
#define CAM_ENTRY_NUM_9081E 64

#endif //__TLL9081E_SPEC_H__

