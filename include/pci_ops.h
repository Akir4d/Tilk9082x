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
#ifndef __PCI_OPS_H_
#define __PCI_OPS_H_


#ifdef CONFIG_TLL9083E
u32	ttl9083ee_init_desc_ring(_adapter *padapter);
u32	ttl9083ee_free_desc_ring(_adapter *padapter);
void	ttl9083ee_reset_desc_ring(_adapter *padapter);
int	ttl9083ee_interrupt(PADAPTER Adapter);
void	ttl9083ee_xmit_tasklet(void *priv);
void	ttl9083ee_recv_tasklet(void *priv);
void	ttl9083ee_prepare_bcn_tasklet(void *priv);
void	ttl9083ee_set_intf_ops(struct _io_ops	*pops);
#endif

#if defined(CONFIG_TLL8812A) || defined(CONFIG_TLL8821A)
u32	ttl8812ae_init_desc_ring(_adapter *padapter);
u32	ttl8812ae_free_desc_ring(_adapter *padapter);
void	ttl8812ae_reset_desc_ring(_adapter *padapter);
int	ttl8812ae_interrupt(PADAPTER Adapter);
void	ttl8812ae_xmit_tasklet(void *priv);
void	ttl8812ae_recv_tasklet(void *priv);
void	ttl8812ae_prepare_bcn_tasklet(void *priv);
void	ttl8812ae_set_intf_ops(struct _io_ops	*pops);
#endif

#ifdef CONFIG_TLL9081E
u32	ttl9081ee_init_desc_ring(_adapter *padapter);
u32	ttl9081ee_free_desc_ring(_adapter *padapter);
void	ttl9081ee_reset_desc_ring(_adapter *padapter);
void	ttl9081ee_recv_tasklet(void *priv);
void	ttl9081ee_prepare_bcn_tasklet(void *priv);
int	ttl9081ee_interrupt(PADAPTER Adapter);
void	ttl9081ee_set_intf_ops(struct _io_ops	*pops);
#endif

#ifdef CONFIG_TLL8723B
u32	ttl8723be_init_desc_ring(_adapter *padapter);
u32	ttl8723be_free_desc_ring(_adapter *padapter);
void	ttl8723be_reset_desc_ring(_adapter *padapter);
int	ttl8723be_interrupt(PADAPTER Adapter);
void	ttl8723be_recv_tasklet(void *priv);
void	ttl8723be_prepare_bcn_tasklet(void *priv);
void	ttl8723be_set_intf_ops(struct _io_ops	*pops);
#endif

#ifdef CONFIG_TLL8814A
u32	ttl8814ae_init_desc_ring(_adapter *padapter);
u32	ttl8814ae_free_desc_ring(_adapter *padapter);
void	ttl8814ae_reset_desc_ring(_adapter *padapter);
int	ttl8814ae_interrupt(PADAPTER Adapter);
void	ttl8814ae_xmit_tasklet(void *priv);
void	ttl8814ae_recv_tasklet(void *priv);
void	ttl8814ae_prepare_bcn_tasklet(void *priv);
void	ttl8814ae_set_intf_ops(struct _io_ops	*pops);
#endif

#endif

