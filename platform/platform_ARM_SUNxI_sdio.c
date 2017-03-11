/******************************************************************************
 *
 * Copyright(c) 2013 Realtek Corporation. All rights reserved.
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
#include <drv_types.h>

#ifdef CONFIG_MMC_SUNXI_POWER_CONTROL
#ifdef CONFIG_WITS_EVB_V13
#define SDIOID	0
#else // !CONFIG_WITS_EVB_V13
#define SDIOID (CONFIG_CHIP_ID==1123 ? 3 : 1)
#endif // !CONFIG_WITS_EVB_V13

#define SUNXI_SDIO_WIFI_NUM_TLL9082ES  10
extern void sunximmc_rescan_card(unsigned id, unsigned insert);
extern int mmc_pm_get_mod_type(void);
extern int mmc_pm_gpio_ctrl(char* name, int level);
/*
 *	ttl9082xs_shdn	= port:PH09<1><default><default><0>
 *	ttl9082xs_wakeup	= port:PH10<1><default><default><1>
 *	ttl9082xs_vdd_en  = port:PH11<1><default><default><0>
 *	ttl9082xs_vcc_en  = port:PH12<1><default><default><0>
 */

int ttl9082xs_sdio_powerup(void)
{
	mmc_pm_gpio_ctrl("ttl9082xs_vdd_en", 1);
	udelay(100);
	mmc_pm_gpio_ctrl("ttl9082xs_vcc_en", 1);
	udelay(50);
	mmc_pm_gpio_ctrl("ttl9082xs_shdn", 1);
	return 0;
}

int ttl9082xs_sdio_poweroff(void)
{
	mmc_pm_gpio_ctrl("ttl9082xs_shdn", 0);
	mmc_pm_gpio_ctrl("ttl9082xs_vcc_en", 0);
	mmc_pm_gpio_ctrl("ttl9082xs_vdd_en", 0);
	return 0;
}
#endif // CONFIG_MMC_SUNXI_POWER_CONTROL

/*
 * Return:
 *	0:	power on successfully
 *	others:	power on failed
 */
int platform_wifi_power_on(void)
{
	int ret = 0;
#ifdef CONFIG_MMC_SUNXI_POWER_CONTROL
	unsigned int mod_sel = mmc_pm_get_mod_type();
#endif // CONFIG_MMC_SUNXI_POWER_CONTROL


#ifdef CONFIG_MMC_SUNXI_POWER_CONTROL
	if (mod_sel == SUNXI_SDIO_WIFI_NUM_TLL9082ES) {
		ttl9082xs_sdio_powerup();
		sunximmc_rescan_card(SDIOID, 1);
		printk("[ttl9082xs] %s: power up, rescan card.\n", __FUNCTION__);
	} else {
		ret = -1;
		printk("[ttl9082xs] %s: mod_sel = %d is incorrect.\n", __FUNCTION__, mod_sel);
	}
#endif // CONFIG_MMC_SUNXI_POWER_CONTROL

	return ret;
}

void platform_wifi_power_off(void)
{
#ifdef CONFIG_MMC_SUNXI_POWER_CONTROL
	sunximmc_rescan_card(SDIOID, 0);
#ifdef CONFIG_TLL9083E
	ttl9082xs_sdio_poweroff();
	printk("[ttl9082xs] %s: remove card, power off.\n", __FUNCTION__);
#endif // CONFIG_TLL9083E
#endif // CONFIG_MMC_SUNXI_POWER_CONTROL
}
