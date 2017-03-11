/******************************************************************************
 *
 * Copyright(c) 2007 - 2012 Realtek Corporation. All rights reserved.
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
#ifndef __TLL9083F_XMIT_H__
#define __TLL9083F_XMIT_H__


#define MAX_TID (15)


#ifndef __INC_HAL9083FDESC_H
#define __INC_HAL9083FDESC_H

#define RX_STATUS_DESC_SIZE_9083F		24
#define RX_DRV_INFO_SIZE_UNIT_9083F 8


//DWORD 0
#define SET_RX_STATUS_DESC_PKT_LEN_9083F(__pRxStatusDesc, __Value)		SET_BITS_TO_LE_4BYTE( __pRxStatusDesc, 0, 14, __Value)
#define SET_RX_STATUS_DESC_EOR_9083F(__pRxStatusDesc, __Value)		SET_BITS_TO_LE_4BYTE( __pRxStatusDesc, 30, 1, __Value)
#define SET_RX_STATUS_DESC_OWN_9083F(__pRxStatusDesc, __Value)		SET_BITS_TO_LE_4BYTE( __pRxStatusDesc, 31, 1, __Value)

#define GET_RX_STATUS_DESC_PKT_LEN_9083F(__pRxStatusDesc)			LE_BITS_TO_4BYTE( __pRxStatusDesc, 0, 14)
#define GET_RX_STATUS_DESC_CRC32_9083F(__pRxStatusDesc) 		LE_BITS_TO_4BYTE( __pRxStatusDesc, 14, 1)
#define GET_RX_STATUS_DESC_ICV_9083F(__pRxStatusDesc)				LE_BITS_TO_4BYTE( __pRxStatusDesc, 15, 1)
#define GET_RX_STATUS_DESC_DRVINFO_SIZE_9083F(__pRxStatusDesc)		LE_BITS_TO_4BYTE( __pRxStatusDesc, 16, 4)
#define GET_RX_STATUS_DESC_SECURITY_9083F(__pRxStatusDesc)			LE_BITS_TO_4BYTE( __pRxStatusDesc, 20, 3)
#define GET_RX_STATUS_DESC_QOS_9083F(__pRxStatusDesc)				LE_BITS_TO_4BYTE( __pRxStatusDesc, 23, 1)
#define GET_RX_STATUS_DESC_SHIFT_9083F(__pRxStatusDesc) 		LE_BITS_TO_4BYTE( __pRxStatusDesc, 24, 2)
#define GET_RX_STATUS_DESC_PHY_STATUS_9083F(__pRxStatusDesc)			LE_BITS_TO_4BYTE( __pRxStatusDesc, 26, 1)
#define GET_RX_STATUS_DESC_SWDEC_9083F(__pRxStatusDesc) 		LE_BITS_TO_4BYTE( __pRxStatusDesc, 27, 1)
#define GET_RX_STATUS_DESC_LAST_SEG_9083F(__pRxStatusDesc)			LE_BITS_TO_4BYTE( __pRxStatusDesc, 28, 1)
#define GET_RX_STATUS_DESC_FIRST_SEG_9083F(__pRxStatusDesc) 		LE_BITS_TO_4BYTE( __pRxStatusDesc, 29, 1)
#define GET_RX_STATUS_DESC_EOR_9083F(__pRxStatusDesc)				LE_BITS_TO_4BYTE( __pRxStatusDesc, 30, 1)
#define GET_RX_STATUS_DESC_OWN_9083F(__pRxStatusDesc)				LE_BITS_TO_4BYTE( __pRxStatusDesc, 31, 1)

//DWORD 1
#define GET_RX_STATUS_DESC_MACID_9083F(__pRxDesc)					LE_BITS_TO_4BYTE(__pRxDesc+4, 0, 7)
#define GET_RX_STATUS_DESC_TID_9083F(__pRxDesc) 					LE_BITS_TO_4BYTE(__pRxDesc+4, 8, 4)
#define GET_RX_STATUS_DESC_AMSDU_9083F(__pRxDesc)					LE_BITS_TO_4BYTE(__pRxDesc+4, 13, 1)
#define GET_RX_STATUS_DESC_RXID_MATCH_9083F(__pRxDesc)		LE_BITS_TO_4BYTE( __pRxDesc+4, 14, 1)
#define GET_RX_STATUS_DESC_PAGGR_9083F(__pRxDesc)				LE_BITS_TO_4BYTE( __pRxDesc+4, 15, 1)
#define GET_RX_STATUS_DESC_A1_FIT_9083F(__pRxDesc)				LE_BITS_TO_4BYTE( __pRxDesc+4, 16, 4)
#define GET_RX_STATUS_DESC_CHKERR_9083F(__pRxDesc)				LE_BITS_TO_4BYTE( __pRxDesc+4, 20, 1)
#define GET_RX_STATUS_DESC_IPVER_9083F(__pRxDesc)			LE_BITS_TO_4BYTE(__pRxDesc+4, 21, 1)
#define GET_RX_STATUS_DESC_IS_TCPUDP__9083F(__pRxDesc)		LE_BITS_TO_4BYTE(__pRxDesc+4, 22, 1)
#define GET_RX_STATUS_DESC_CHK_VLD_9083F(__pRxDesc) 	LE_BITS_TO_4BYTE(__pRxDesc+4, 23, 1)
#define GET_RX_STATUS_DESC_PAM_9083F(__pRxDesc) 			LE_BITS_TO_4BYTE( __pRxDesc+4, 24, 1)
#define GET_RX_STATUS_DESC_PWR_9083F(__pRxDesc) 			LE_BITS_TO_4BYTE( __pRxDesc+4, 25, 1)
#define GET_RX_STATUS_DESC_MORE_DATA_9083F(__pRxDesc)			LE_BITS_TO_4BYTE( __pRxDesc+4, 26, 1)
#define GET_RX_STATUS_DESC_MORE_FRAG_9083F(__pRxDesc)			LE_BITS_TO_4BYTE( __pRxDesc+4, 27, 1)
#define GET_RX_STATUS_DESC_TYPE_9083F(__pRxDesc)			LE_BITS_TO_4BYTE( __pRxDesc+4, 28, 2)
#define GET_RX_STATUS_DESC_MC_9083F(__pRxDesc)				LE_BITS_TO_4BYTE( __pRxDesc+4, 30, 1)
#define GET_RX_STATUS_DESC_BC_9083F(__pRxDesc)				LE_BITS_TO_4BYTE( __pRxDesc+4, 31, 1)

//DWORD 2
#define GET_RX_STATUS_DESC_SEQ_9083F(__pRxStatusDesc)					LE_BITS_TO_4BYTE( __pRxStatusDesc+8, 0, 12)
#define GET_RX_STATUS_DESC_FRAG_9083F(__pRxStatusDesc)				LE_BITS_TO_4BYTE( __pRxStatusDesc+8, 12, 4)
#define GET_RX_STATUS_DESC_RX_IS_QOS_9083F(__pRxStatusDesc) 		LE_BITS_TO_4BYTE( __pRxStatusDesc+8, 16, 1)
#define GET_RX_STATUS_DESC_WLANHD_IV_LEN_9083F(__pRxStatusDesc) 	LE_BITS_TO_4BYTE( __pRxStatusDesc+8, 18, 6)
#define GET_RX_STATUS_DESC_RPT_SEL_9083F(__pRxStatusDesc)			LE_BITS_TO_4BYTE( __pRxStatusDesc+8, 28, 1)

//DWORD 3
#define GET_RX_STATUS_DESC_RX_RATE_9083F(__pRxStatusDesc)				LE_BITS_TO_4BYTE( __pRxStatusDesc+12, 0, 7)
#define GET_RX_STATUS_DESC_HTC_9083F(__pRxStatusDesc)					LE_BITS_TO_4BYTE( __pRxStatusDesc+12, 10, 1)
#define GET_RX_STATUS_DESC_EOSP_9083F(__pRxStatusDesc)					LE_BITS_TO_4BYTE( __pRxStatusDesc+12, 11, 1)
#define GET_RX_STATUS_DESC_BSSID_FIT_9083F(__pRxStatusDesc) 		LE_BITS_TO_4BYTE( __pRxStatusDesc+12, 12, 2)
#ifdef CONFIG_USB_RX_AGGREGATION
#define GET_RX_STATUS_DESC_USB_AGG_PKTNUM_9083F(__pRxStatusDesc)	LE_BITS_TO_4BYTE( __pRxStatusDesc+12, 16, 8)
#endif
#define GET_RX_STATUS_DESC_PATTERN_MATCH_9083F(__pRxDesc)			LE_BITS_TO_4BYTE( __pRxDesc+12, 29, 1)
#define GET_RX_STATUS_DESC_UNICAST_MATCH_9083F(__pRxDesc)			LE_BITS_TO_4BYTE( __pRxDesc+12, 30, 1)
#define GET_RX_STATUS_DESC_MAGIC_MATCH_9083F(__pRxDesc) 		LE_BITS_TO_4BYTE( __pRxDesc+12, 31, 1)

//DWORD 6
#define GET_RX_STATUS_DESC_SPLCP_9083F(__pRxDesc)			LE_BITS_TO_4BYTE( __pRxDesc+16, 0, 1)
#define GET_RX_STATUS_DESC_LDPC_9083F(__pRxDesc)			LE_BITS_TO_4BYTE( __pRxDesc+16, 1, 1)
#define GET_RX_STATUS_DESC_STBC_9083F(__pRxDesc)			LE_BITS_TO_4BYTE( __pRxDesc+16, 2, 1)
#define GET_RX_STATUS_DESC_BW_9083F(__pRxDesc)			LE_BITS_TO_4BYTE( __pRxDesc+16, 4, 2)

//DWORD 5
#define GET_RX_STATUS_DESC_TSFL_9083F(__pRxStatusDesc)				LE_BITS_TO_4BYTE( __pRxStatusDesc+20, 0, 32)

#define GET_RX_STATUS_DESC_BUFF_ADDR_9083F(__pRxDesc)		LE_BITS_TO_4BYTE(__pRxDesc+24, 0, 32)
#define GET_RX_STATUS_DESC_BUFF_ADDR64_9083F(__pRxDesc) 		LE_BITS_TO_4BYTE(__pRxDesc+28, 0, 32)

#define SET_RX_STATUS_DESC_BUFF_ADDR_9083F(__pRxDesc, __Value)	SET_BITS_TO_LE_4BYTE(__pRxDesc+24, 0, 32, __Value)


// Dword 0
#define GET_TX_DESC_OWN_9083F(__pTxDesc)				LE_BITS_TO_4BYTE(__pTxDesc, 31, 1)

#define SET_TX_DESC_PKT_SIZE_9083F(__pTxDesc, __Value) SET_BITS_TO_LE_4BYTE(__pTxDesc, 0, 16, __Value)
#define SET_TX_DESC_OFFSET_9083F(__pTxDesc, __Value) SET_BITS_TO_LE_4BYTE(__pTxDesc, 16, 8, __Value)
#define SET_TX_DESC_BMC_9083F(__pTxDesc, __Value) SET_BITS_TO_LE_4BYTE(__pTxDesc, 24, 1, __Value)
#define SET_TX_DESC_HTC_9083F(__pTxDesc, __Value) SET_BITS_TO_LE_4BYTE(__pTxDesc, 25, 1, __Value)
#define SET_TX_DESC_LAST_SEG_9083F(__pTxDesc, __Value) SET_BITS_TO_LE_4BYTE(__pTxDesc, 26, 1, __Value)
#define SET_TX_DESC_FIRST_SEG_9083F(__pTxDesc, __Value) SET_BITS_TO_LE_4BYTE(__pTxDesc, 27, 1, __Value)
#define SET_TX_DESC_LINIP_9083F(__pTxDesc, __Value) SET_BITS_TO_LE_4BYTE(__pTxDesc, 28, 1, __Value)
#define SET_TX_DESC_NO_ACM_9083F(__pTxDesc, __Value) SET_BITS_TO_LE_4BYTE(__pTxDesc, 29, 1, __Value)
#define SET_TX_DESC_GF_9083F(__pTxDesc, __Value) SET_BITS_TO_LE_4BYTE(__pTxDesc, 30, 1, __Value)
#define SET_TX_DESC_OWN_9083F(__pTxDesc, __Value) SET_BITS_TO_LE_4BYTE(__pTxDesc, 31, 1, __Value)

// Dword 1
#define SET_TX_DESC_MACID_9083F(__pTxDesc, __Value) SET_BITS_TO_LE_4BYTE(__pTxDesc+4, 0, 7, __Value)
#define SET_TX_DESC_QUEUE_SEL_9083F(__pTxDesc, __Value) SET_BITS_TO_LE_4BYTE(__pTxDesc+4, 8, 5, __Value)
#define SET_TX_DESC_RDG_NAV_EXT_9083F(__pTxDesc, __Value) SET_BITS_TO_LE_4BYTE(__pTxDesc+4, 13, 1, __Value)
#define SET_TX_DESC_LSIG_TXOP_EN_9083F(__pTxDesc, __Value) SET_BITS_TO_LE_4BYTE(__pTxDesc+4, 14, 1, __Value)
#define SET_TX_DESC_PIFS_9083F(__pTxDesc, __Value) SET_BITS_TO_LE_4BYTE(__pTxDesc+4, 15, 1, __Value)
#define SET_TX_DESC_RATE_ID_9083F(__pTxDesc, __Value) SET_BITS_TO_LE_4BYTE(__pTxDesc+4, 16, 5, __Value)
#define SET_TX_DESC_EN_DESC_ID_9083F(__pTxDesc, __Value) SET_BITS_TO_LE_4BYTE(__pTxDesc+4, 21, 1, __Value)
#define SET_TX_DESC_SEC_TYPE_9083F(__pTxDesc, __Value) SET_BITS_TO_LE_4BYTE(__pTxDesc+4, 22, 2, __Value)
#define SET_TX_DESC_PKT_OFFSET_9083F(__pTxDesc, __Value)		SET_BITS_TO_LE_4BYTE(__pTxDesc+4, 24, 5, __Value)


// Dword 2
#define SET_TX_DESC_PAID_9083F(__pTxDesc, __Value) SET_BITS_TO_LE_4BYTE(__pTxDesc+8, 0,  9, __Value) 
#define SET_TX_DESC_CCA_RTS_9083F(__pTxDesc, __Value) SET_BITS_TO_LE_4BYTE(__pTxDesc+8, 10, 2, __Value)
#define SET_TX_DESC_AGG_ENABLE_9083F(__pTxDesc, __Value)		SET_BITS_TO_LE_4BYTE(__pTxDesc+8, 12, 1, __Value)
#define SET_TX_DESC_RDG_ENABLE_9083F(__pTxDesc, __Value)		SET_BITS_TO_LE_4BYTE(__pTxDesc+8, 13, 1, __Value)
#define SET_TX_DESC_AGG_BREAK_9083F(__pTxDesc, __Value) 				SET_BITS_TO_LE_4BYTE(__pTxDesc+8, 16, 1, __Value)
#define SET_TX_DESC_MORE_FRAG_9083F(__pTxDesc, __Value) SET_BITS_TO_LE_4BYTE(__pTxDesc+8, 17, 1, __Value)
#define SET_TX_DESC_RAW_9083F(__pTxDesc, __Value) SET_BITS_TO_LE_4BYTE(__pTxDesc+8, 18, 1, __Value)
#define SET_TX_DESC_SPE_RPT_9083F(__pTxDesc, __Value) SET_BITS_TO_LE_4BYTE(__pTxDesc+8, 19, 1, __Value)
#define SET_TX_DESC_AMPDU_DENSITY_9083F(__pTxDesc, __Value) SET_BITS_TO_LE_4BYTE(__pTxDesc+8, 20, 3, __Value)
#define SET_TX_DESC_BT_INT_9083F(__pTxDesc, __Value)			SET_BITS_TO_LE_4BYTE(__pTxDesc+8, 23, 1, __Value)
#define SET_TX_DESC_GID_9083F(__pTxDesc, __Value)			SET_BITS_TO_LE_4BYTE(__pTxDesc+8, 24, 6, __Value)


// Dword 3
#define SET_TX_DESC_WHEADER_LEN_9083F(__pTxDesc, __Value) SET_BITS_TO_LE_4BYTE(__pTxDesc+12, 0, 4, __Value)
#define SET_TX_DESC_CHK_EN_9083F(__pTxDesc, __Value) SET_BITS_TO_LE_4BYTE(__pTxDesc+12, 4, 1, __Value)
#define SET_TX_DESC_EARLY_MODE_9083F(__pTxDesc, __Value) SET_BITS_TO_LE_4BYTE(__pTxDesc+12, 5, 1, __Value)
#define SET_TX_DESC_HWSEQ_SEL_9083F(__pTxDesc, __Value) SET_BITS_TO_LE_4BYTE(__pTxDesc+12, 6, 2, __Value)
#define SET_TX_DESC_USE_RATE_9083F(__pTxDesc, __Value) SET_BITS_TO_LE_4BYTE(__pTxDesc+12, 8, 1, __Value)
#define SET_TX_DESC_DISABLE_RTS_FB_9083F(__pTxDesc, __Value) SET_BITS_TO_LE_4BYTE(__pTxDesc+12, 9, 1, __Value)
#define SET_TX_DESC_DISABLE_FB_9083F(__pTxDesc, __Value) SET_BITS_TO_LE_4BYTE(__pTxDesc+12, 10, 1, __Value)
#define SET_TX_DESC_CTS2SELF_9083F(__pTxDesc, __Value) SET_BITS_TO_LE_4BYTE(__pTxDesc+12, 11, 1, __Value)
#define SET_TX_DESC_RTS_ENABLE_9083F(__pTxDesc, __Value) SET_BITS_TO_LE_4BYTE(__pTxDesc+12, 12, 1, __Value)
#define SET_TX_DESC_HW_RTS_ENABLE_9083F(__pTxDesc, __Value) SET_BITS_TO_LE_4BYTE(__pTxDesc+12, 13, 1, __Value)
#define SET_TX_DESC_NAV_USE_HDR_9083F(__pTxDesc, __Value) SET_BITS_TO_LE_4BYTE(__pTxDesc+12, 15, 1, __Value)
#define SET_TX_DESC_USE_MAX_LEN_9083F(__pTxDesc, __Value) SET_BITS_TO_LE_4BYTE(__pTxDesc+12, 16, 1, __Value)
#define SET_TX_DESC_MAX_AGG_NUM_9083F(__pTxDesc, __Value) SET_BITS_TO_LE_4BYTE(__pTxDesc+12, 17, 5, __Value)
#define SET_TX_DESC_NDPA_9083F(__pTxDesc, __Value)		SET_BITS_TO_LE_4BYTE(__pTxDesc+12, 22, 2, __Value)
#define SET_TX_DESC_AMPDU_MAX_TIME_9083F(__pTxDesc, __Value)		SET_BITS_TO_LE_4BYTE(__pTxDesc+12, 24, 8, __Value)

// Dword 4
#define SET_TX_DESC_TX_RATE_9083F(__pTxDesc, __Value) SET_BITS_TO_LE_4BYTE(__pTxDesc+16, 0, 7, __Value)
#define SET_TX_DESC_DATA_RATE_FB_LIMIT_9083F(__pTxDesc, __Value) SET_BITS_TO_LE_4BYTE(__pTxDesc+16, 8, 5, __Value)
#define SET_TX_DESC_RTS_RATE_FB_LIMIT_9083F(__pTxDesc, __Value) SET_BITS_TO_LE_4BYTE(__pTxDesc+16, 13, 4, __Value)
#define SET_TX_DESC_RETRY_LIMIT_ENABLE_9083F(__pTxDesc, __Value) SET_BITS_TO_LE_4BYTE(__pTxDesc+16, 17, 1, __Value)
#define SET_TX_DESC_DATA_RETRY_LIMIT_9083F(__pTxDesc, __Value) SET_BITS_TO_LE_4BYTE(__pTxDesc+16, 18, 6, __Value)
#define SET_TX_DESC_RTS_RATE_9083F(__pTxDesc, __Value) SET_BITS_TO_LE_4BYTE(__pTxDesc+16, 24, 5, __Value)


// Dword 5
#define SET_TX_DESC_DATA_SC_9083F(__pTxDesc, __Value) SET_BITS_TO_LE_4BYTE(__pTxDesc+20, 0, 4, __Value)
#define SET_TX_DESC_DATA_SHORT_9083F(__pTxDesc, __Value)	SET_BITS_TO_LE_4BYTE(__pTxDesc+20, 4, 1, __Value)
#define SET_TX_DESC_DATA_BW_9083F(__pTxDesc, __Value) SET_BITS_TO_LE_4BYTE(__pTxDesc+20, 5, 2, __Value)
#define SET_TX_DESC_DATA_LDPC_9083F(__pTxDesc, __Value) SET_BITS_TO_LE_4BYTE(__pTxDesc+20, 7, 1, __Value)
#define SET_TX_DESC_DATA_STBC_9083F(__pTxDesc, __Value) SET_BITS_TO_LE_4BYTE(__pTxDesc+20, 8, 2, __Value)
#define SET_TX_DESC_CTROL_STBC_9083F(__pTxDesc, __Value) SET_BITS_TO_LE_4BYTE(__pTxDesc+20, 10, 2, __Value)
#define SET_TX_DESC_RTS_SHORT_9083F(__pTxDesc, __Value) SET_BITS_TO_LE_4BYTE(__pTxDesc+20, 12, 1, __Value)
#define SET_TX_DESC_RTS_SC_9083F(__pTxDesc, __Value) SET_BITS_TO_LE_4BYTE(__pTxDesc+20, 13, 4, __Value)


// Dword 6
#define SET_TX_DESC_SW_DEFINE_9083F(__pTxDesc, __Value) SET_BITS_TO_LE_4BYTE(__pTxDesc+24, 0, 12, __Value)
#define SET_TX_DESC_MBSSID_9083F(__pTxDesc, __Value) SET_BITS_TO_LE_4BYTE(__pTxDesc+24, 12, 4, __Value)
#define SET_TX_DESC_ANTSEL_A_9083F(__pTxDesc, __Value) SET_BITS_TO_LE_4BYTE(__pTxDesc+24, 16, 3, __Value)
#define SET_TX_DESC_ANTSEL_B_9083F(__pTxDesc, __Value) SET_BITS_TO_LE_4BYTE(__pTxDesc+24, 19, 3, __Value)
#define SET_TX_DESC_ANTSEL_C_9083F(__pTxDesc, __Value) SET_BITS_TO_LE_4BYTE(__pTxDesc+24, 22, 3, __Value)
#define SET_TX_DESC_ANTSEL_D_9083F(__pTxDesc, __Value) SET_BITS_TO_LE_4BYTE(__pTxDesc+24, 25, 3, __Value)

// Dword 7
#if(DEV_BUS_TYPE == RT_PCI_INTERFACE)
#define SET_TX_DESC_TX_BUFFER_SIZE_9083F(__pTxDesc, __Value)		SET_BITS_TO_LE_4BYTE(__pTxDesc+28, 0, 16, __Value)
#else
#define SET_TX_DESC_TX_DESC_CHECKSUM_9083F(__pTxDesc, __Value) SET_BITS_TO_LE_4BYTE(__pTxDesc+28, 0, 16, __Value)
#endif
#define SET_TX_DESC_USB_TXAGG_NUM_9083F(__pTxDesc, __Value) SET_BITS_TO_LE_4BYTE(__pTxDesc+28, 24, 8, __Value)
#if(DEV_BUS_TYPE == RT_SDIO_INTERFACE)
#define SET_TX_DESC_SDIO_TXSEQ_9083F(__pTxDesc, __Value)			SET_BITS_TO_LE_4BYTE(__pTxDesc+28, 16, 8, __Value)
#endif

// Dword 8
#define SET_TX_DESC_HWSEQ_EN_9083F(__pTxDesc, __Value)			SET_BITS_TO_LE_4BYTE(__pTxDesc+32, 15, 1, __Value)

// Dword 9
#define SET_TX_DESC_SEQ_9083F(__pTxDesc, __Value)					SET_BITS_TO_LE_4BYTE(__pTxDesc+36, 12, 12, __Value)

// Dword 10
#define SET_TX_DESC_TX_BUFFER_ADDRESS_9083F(__pTxDesc, __Value) 	SET_BITS_TO_LE_4BYTE(__pTxDesc+40, 0, 32, __Value)
#define GET_TX_DESC_TX_BUFFER_ADDRESS_9083F(__pTxDesc) 	LE_BITS_TO_4BYTE(__pTxDesc+40, 0, 32)

// Dword 11
#define SET_TX_DESC_NEXT_DESC_ADDRESS_9083F(__pTxDesc, __Value) 	SET_BITS_TO_LE_4BYTE(__pTxDesc+48, 0, 32, __Value)


#define SET_EARLYMODE_PKTNUM_9083F(__pAddr, __Value)					SET_BITS_TO_LE_4BYTE(__pAddr, 0, 4, __Value)
#define SET_EARLYMODE_LEN0_9083F(__pAddr, __Value)					SET_BITS_TO_LE_4BYTE(__pAddr, 4, 15, __Value)
#define SET_EARLYMODE_LEN1_1_9083F(__pAddr, __Value)					SET_BITS_TO_LE_4BYTE(__pAddr, 19, 13, __Value)
#define SET_EARLYMODE_LEN1_2_9083F(__pAddr, __Value)					SET_BITS_TO_LE_4BYTE(__pAddr+4, 0, 2, __Value)
#define SET_EARLYMODE_LEN2_9083F(__pAddr, __Value)					SET_BITS_TO_LE_4BYTE(__pAddr+4, 2, 15,	__Value)
#define SET_EARLYMODE_LEN3_9083F(__pAddr, __Value)					SET_BITS_TO_LE_4BYTE(__pAddr+4, 17, 15, __Value)

#endif
//-----------------------------------------------------------
//
//	Rate
//
//-----------------------------------------------------------
// CCK Rates, TxHT = 0
#define DESC9083F_RATE1M				0x00
#define DESC9083F_RATE2M				0x01
#define DESC9083F_RATE5_5M				0x02
#define DESC9083F_RATE11M				0x03

// OFDM Rates, TxHT = 0
#define DESC9083F_RATE6M				0x04
#define DESC9083F_RATE9M				0x05
#define DESC9083F_RATE12M				0x06
#define DESC9083F_RATE18M				0x07
#define DESC9083F_RATE24M				0x08
#define DESC9083F_RATE36M				0x09
#define DESC9083F_RATE48M				0x0a
#define DESC9083F_RATE54M				0x0b

// MCS Rates, TxHT = 1
#define DESC9083F_RATEMCS0				0x0c
#define DESC9083F_RATEMCS1				0x0d
#define DESC9083F_RATEMCS2				0x0e
#define DESC9083F_RATEMCS3				0x0f
#define DESC9083F_RATEMCS4				0x10
#define DESC9083F_RATEMCS5				0x11
#define DESC9083F_RATEMCS6				0x12
#define DESC9083F_RATEMCS7				0x13
#define DESC9083F_RATEMCS8				0x14
#define DESC9083F_RATEMCS9				0x15
#define DESC9083F_RATEMCS10 		0x16
#define DESC9083F_RATEMCS11 		0x17
#define DESC9083F_RATEMCS12 		0x18
#define DESC9083F_RATEMCS13 		0x19
#define DESC9083F_RATEMCS14 		0x1a
#define DESC9083F_RATEMCS15 		0x1b
#define DESC9083F_RATEVHTSS1MCS0		0x2c
#define DESC9083F_RATEVHTSS1MCS1		0x2d
#define DESC9083F_RATEVHTSS1MCS2		0x2e
#define DESC9083F_RATEVHTSS1MCS3		0x2f
#define DESC9083F_RATEVHTSS1MCS4		0x30
#define DESC9083F_RATEVHTSS1MCS5		0x31
#define DESC9083F_RATEVHTSS1MCS6		0x32
#define DESC9083F_RATEVHTSS1MCS7		0x33
#define DESC9083F_RATEVHTSS1MCS8		0x34
#define DESC9083F_RATEVHTSS1MCS9		0x35
#define DESC9083F_RATEVHTSS2MCS0		0x36
#define DESC9083F_RATEVHTSS2MCS1		0x37
#define DESC9083F_RATEVHTSS2MCS2		0x38
#define DESC9083F_RATEVHTSS2MCS3		0x39
#define DESC9083F_RATEVHTSS2MCS4		0x3a
#define DESC9083F_RATEVHTSS2MCS5		0x3b
#define DESC9083F_RATEVHTSS2MCS6		0x3c
#define DESC9083F_RATEVHTSS2MCS7		0x3d
#define DESC9083F_RATEVHTSS2MCS8		0x3e
#define DESC9083F_RATEVHTSS2MCS9		0x3f


#define 	RX_HAL_IS_CCK_RATE_9083F(pDesc)\
			(GET_RX_STATUS_DESC_RX_RATE_9083F(pDesc) == DESC9083F_RATE1M ||\
			GET_RX_STATUS_DESC_RX_RATE_9083F(pDesc) == DESC9083F_RATE2M ||\
			GET_RX_STATUS_DESC_RX_RATE_9083F(pDesc) == DESC9083F_RATE5_5M ||\
			GET_RX_STATUS_DESC_RX_RATE_9083F(pDesc) == DESC9083F_RATE11M)


void ttl9083f_update_txdesc(struct xmit_frame *pxmitframe, u8 *pmem);
void ttl9083f_fill_fake_txdesc(PADAPTER padapter, u8 *pDesc, u32 BufferLen, u8 IsPsPoll, u8 IsBTQosNull, u8 bDataFrame);

#if defined(CONFIG_SDIO_HCI) || defined(CONFIG_GSPI_HCI)
s32 ttl9083fs_init_xmit_priv(PADAPTER padapter);
void ttl9083fs_free_xmit_priv(PADAPTER padapter);
s32 ttl9083fs_hal_xmit(PADAPTER padapter, struct xmit_frame *pxmitframe);
s32 ttl9083fs_mgnt_xmit(PADAPTER padapter, struct xmit_frame *pmgntframe);
s32	ttl9083fs_hal_xmitframe_enqueue(_adapter *padapter, struct xmit_frame *pxmitframe);
s32 ttl9083fs_xmit_buf_handler(PADAPTER padapter);
thread_return ttl9083fs_xmit_thread(thread_context context);
#define hal_xmit_handler ttl9083fs_xmit_buf_handler
#endif

#ifdef CONFIG_USB_HCI
s32 ttl9083fu_xmit_buf_handler(PADAPTER padapter);
#define hal_xmit_handler ttl9083fu_xmit_buf_handler


s32 ttl9083fu_init_xmit_priv(PADAPTER padapter);
void ttl9083fu_free_xmit_priv(PADAPTER padapter);
s32 ttl9083fu_hal_xmit(PADAPTER padapter, struct xmit_frame *pxmitframe);
s32 ttl9083fu_mgnt_xmit(PADAPTER padapter, struct xmit_frame *pmgntframe);
s32	 ttl9083fu_hal_xmitframe_enqueue(_adapter *padapter, struct xmit_frame *pxmitframe);
//s32 ttl8812au_xmit_buf_handler(PADAPTER padapter);
void ttl9083fu_xmit_tasklet(void *priv);
s32 ttl9083fu_xmitframe_complete(_adapter *padapter, struct xmit_priv *pxmitpriv, struct xmit_buf *pxmitbuf);
void _dbg_dump_tx_info(_adapter	*padapter,int frame_tag,struct tx_desc *ptxdesc);
#endif

#ifdef CONFIG_PCI_HCI
s32 ttl9083fe_init_xmit_priv(PADAPTER padapter);
void ttl9083fe_free_xmit_priv(PADAPTER padapter);
struct xmit_buf *ttl9083fe_dequeue_xmitbuf(struct tlw_tx_ring *ring);
void	ttl9083fe_xmitframe_resume(_adapter *padapter);
s32 ttl9083fe_hal_xmit(PADAPTER padapter, struct xmit_frame *pxmitframe);
s32 ttl9083fe_mgnt_xmit(PADAPTER padapter, struct xmit_frame *pmgntframe);
s32	ttl9083fe_hal_xmitframe_enqueue(_adapter *padapter, struct xmit_frame *pxmitframe);
void ttl9083fe_xmit_tasklet(void *priv);
#endif

u8	BWMapping_9083F(PADAPTER Adapter, struct pkt_attrib *pattrib);
u8	SCMapping_9083F(PADAPTER Adapter, struct pkt_attrib	*pattrib);

#endif

