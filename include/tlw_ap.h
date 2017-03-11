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
#ifndef __TLW_AP_H_
#define __TLW_AP_H_


#ifdef CONFIG_AP_MODE

//external function
extern void tlw_indicate_sta_assoc_event(_adapter *padapter, struct sta_info *psta);
extern void tlw_indicate_sta_disassoc_event(_adapter *padapter, struct sta_info *psta);


void init_mlme_ap_info(_adapter *padapter);
void free_mlme_ap_info(_adapter *padapter);
//void update_BCNTIM(_adapter *padapter);
void tlw_add_bcn_ie(_adapter *padapter, WLAN_BSSID_EX *pnetwork, u8 index, u8 *data, u8 len);
void tlw_remove_bcn_ie(_adapter *padapter, WLAN_BSSID_EX *pnetwork, u8 index);
void _update_beacon(_adapter *padapter, u8 ie_id, u8 *oui, u8 tx, const char *tag);
#define update_beacon(adapter, ie_id, oui, tx) _update_beacon((adapter), (ie_id), (oui), (tx), __func__)
void add_RATid(_adapter *padapter, struct sta_info *psta, u8 rssi_level);
void expire_timeout_chk(_adapter *padapter);
void update_sta_info_apmode(_adapter *padapter, struct sta_info *psta);
void tlw_start_bss_hdl_after_chbw_decided(_adapter *adapter);
void start_bss_network(_adapter *padapter, struct createbss_parm *parm);
int tlw_check_beacon_data(_adapter *padapter, u8 *pbuf,  int len);
void tlw_ap_restore_network(_adapter *padapter);
void tlw_set_macaddr_acl(_adapter *padapter, int mode);
int tlw_acl_add_sta(_adapter *padapter, u8 *addr);
int tlw_acl_remove_sta(_adapter *padapter, u8 *addr);

u8 tlw_ap_set_pairwise_key(_adapter *padapter, struct sta_info *psta);
int tlw_ap_set_group_key(_adapter *padapter, u8 *key, u8 alg, int keyid);
int tlw_ap_set_wep_key(_adapter *padapter, u8 *key, u8 keylen, int keyid, u8 set_tx);

#ifdef CONFIG_NATIVEAP_MLME
void associated_clients_update(_adapter *padapter, u8 updated, u32 sta_info_type);
void bss_cap_update_on_sta_join(_adapter *padapter, struct sta_info *psta);
u8 bss_cap_update_on_sta_leave(_adapter *padapter, struct sta_info *psta);
void sta_info_update(_adapter *padapter, struct sta_info *psta);
void ap_sta_info_defer_update(_adapter *padapter, struct sta_info *psta);
u8 ap_free_sta(_adapter *padapter, struct sta_info *psta, bool active, u16 reason, bool enqueue);
int tlw_sta_flush(_adapter *padapter, bool enqueue);
int tlw_ap_inform_ch_switch(_adapter *padapter, u8 new_ch, u8 ch_offset);
void start_ap_mode(_adapter *padapter);
void stop_ap_mode(_adapter *padapter);
#endif

void tlw_ap_update_bss_chbw(_adapter *adapter, WLAN_BSSID_EX *bss, u8 ch, u8 bw, u8 offset);
bool tlw_ap_chbw_decision(_adapter *adapter, u8 req_ch, u8 req_bw, u8 req_offset, u8 *ch, u8 *bw, u8 *offset);

#ifdef CONFIG_AUTO_AP_MODE
extern void tlw_start_auto_ap(_adapter *adapter);
#endif //CONFIG_AUTO_AP_MODE

#endif //end of CONFIG_AP_MODE

#endif
void update_bmc_sta(_adapter *padapter);

void tlw_process_ht_action_smps(_adapter *padapter, u8 *ta, u8 ctrl_field);
void tlw_process_public_act_bsscoex(_adapter *padapter, u8 *pframe, uint frame_len);

