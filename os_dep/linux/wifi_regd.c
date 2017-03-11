/******************************************************************************
 *
 * Copyright(c) 2009-2010  Realtek Corporation.
 *
 *****************************************************************************/

#include <drv_types.h>

#ifdef CONFIG_IOCTL_CFG80211

#include <tlw_wifi_regd.h>

static struct country_code_to_enum_rd allCountries[] = {
	{COUNTRY_CODE_USER, "RD"},
};

/* 
 * REG_RULE(freq start, freq end, bandwidth, max gain, eirp, reg_flags)
 */

/*
 *Only these channels all allow active
 *scan on all world regulatory domains
 */

/* 2G chan 01 - chan 11 */
#define TLW_2GHZ_CH01_11	\
	REG_RULE(2412-10, 2462+10, 40, 0, 20, 0)

/*
 *We enable active scan on these a case
 *by case basis by regulatory domain
 */

/* 2G chan 12 - chan 13, PASSIV SCAN */
#define TLW_2GHZ_CH12_13	\
	REG_RULE(2467-10, 2472+10, 40, 0, 20,	\
	NL80211_RRF_PASSIVE_SCAN)

/* 2G chan 14, PASSIVS SCAN, NO OFDM (B only) */
#define TLW_2GHZ_CH14	\
	REG_RULE(2484-10, 2484+10, 40, 0, 20,	\
	NL80211_RRF_PASSIVE_SCAN | NL80211_RRF_NO_OFDM)

/* 5G chan 36 - chan 64 */
#define TLW_5GHZ_5150_5350	\
	REG_RULE(5150-10, 5350+10, 40, 0, 30,	\
	NL80211_RRF_PASSIVE_SCAN | NL80211_RRF_NO_IBSS)

/* 5G chan 100 - chan 165 */
#define TLW_5GHZ_5470_5850	\
	REG_RULE(5470-10, 5850+10, 40, 0, 30, \
	NL80211_RRF_PASSIVE_SCAN | NL80211_RRF_NO_IBSS)

/* 5G chan 149 - chan 165 */
#define TLW_5GHZ_5725_5850	\
	REG_RULE(5725-10, 5850+10, 40, 0, 30, \
	NL80211_RRF_PASSIVE_SCAN | NL80211_RRF_NO_IBSS)

/* 5G chan 36 - chan 165 */
#define TLW_5GHZ_5150_5850	\
	REG_RULE(5150-10, 5850+10, 40, 0, 30,	\
	NL80211_RRF_PASSIVE_SCAN | NL80211_RRF_NO_IBSS)

static const struct ieee80211_regdomain tlw_regdom_rd = {
	.n_reg_rules = 3,
	.alpha2 = "99",
	.reg_rules = {
		      TLW_2GHZ_CH01_11,
		      TLW_2GHZ_CH12_13,
		      TLW_5GHZ_5150_5850,
		      }
};

static const struct ieee80211_regdomain tlw_regdom_11 = {
	.n_reg_rules = 1,
	.alpha2 = "99",
	.reg_rules = {
		      TLW_2GHZ_CH01_11,
		      }
};

static const struct ieee80211_regdomain tlw_regdom_12_13 = {
	.n_reg_rules = 2,
	.alpha2 = "99",
	.reg_rules = {
		      TLW_2GHZ_CH01_11,
		      TLW_2GHZ_CH12_13,
		      }
};

static const struct ieee80211_regdomain tlw_regdom_no_midband = {
	.n_reg_rules = 3,
	.alpha2 = "99",
	.reg_rules = {
		      TLW_2GHZ_CH01_11,
		      TLW_5GHZ_5150_5350,
		      TLW_5GHZ_5725_5850,
		      }
};

static const struct ieee80211_regdomain tlw_regdom_60_64 = {
	.n_reg_rules = 3,
	.alpha2 = "99",
	.reg_rules = {
		      TLW_2GHZ_CH01_11,
		      TLW_2GHZ_CH12_13,
		      TLW_5GHZ_5725_5850,
		      }
};

static const struct ieee80211_regdomain tlw_regdom_14_60_64 = {
	.n_reg_rules = 4,
	.alpha2 = "99",
	.reg_rules = {
		      TLW_2GHZ_CH01_11,
		      TLW_2GHZ_CH12_13,
		      TLW_2GHZ_CH14,
		      TLW_5GHZ_5725_5850,
		      }
};

static const struct ieee80211_regdomain tlw_regdom_14 = {
	.n_reg_rules = 3,
	.alpha2 = "99",
	.reg_rules = {
		      TLW_2GHZ_CH01_11,
		      TLW_2GHZ_CH12_13,
		      TLW_2GHZ_CH14,
		      }
};

#if 0
static struct tlw_regulatory *tlw_regd;
#endif

static bool _tlw_is_radar_freq(u16 center_freq)
{
	return (center_freq >= 5260 && center_freq <= 5700);
}

#if 0 // not_yet
static void _tlw_reg_apply_beaconing_flags(struct wiphy *wiphy,
					   enum nl80211_reg_initiator initiator)
{
	enum ieee80211_band band;
	struct ieee80211_supported_band *sband;
	const struct ieee80211_reg_rule *reg_rule;
	struct ieee80211_channel *ch;
	unsigned int i;
	u32 bandwidth = 0;
	int r;

	for (band = 0; band < IEEE80211_NUM_BANDS; band++) {

		if (!wiphy->bands[band])
			continue;

		sband = wiphy->bands[band];

		for (i = 0; i < sband->n_channels; i++) {
			ch = &sband->channels[i];
			if (_tlw_is_radar_freq(ch->center_freq) ||
			    (ch->flags & IEEE80211_CHAN_RADAR))
				continue;
			if (initiator == NL80211_REGDOM_SET_BY_COUNTRY_IE) {
				r = freq_reg_info(wiphy, ch->center_freq,
						  bandwidth, &reg_rule);
				if (r)
					continue;

				/*
				 *If 11d had a rule for this channel ensure
				 *we enable adhoc/beaconing if it allows us to
				 *use it. Note that we would have disabled it
				 *by applying our static world regdomain by
				 *default during init, prior to calling our
				 *regulatory_hint().
				 */

				if (!(reg_rule->flags & NL80211_RRF_NO_IBSS))
					ch->flags &= ~IEEE80211_CHAN_NO_IBSS;
				if (!
				    (reg_rule->flags &
				     NL80211_RRF_PASSIVE_SCAN))
					ch->flags &=
					    ~IEEE80211_CHAN_PASSIVE_SCAN;
			} else {
				if (ch->beacon_found)
					ch->flags &= ~(IEEE80211_CHAN_NO_IBSS |
						       IEEE80211_CHAN_PASSIVE_SCAN);
			}
		}
	}
}

/* Allows active scan scan on Ch 12 and 13 */
static void _tlw_reg_apply_active_scan_flags(struct wiphy *wiphy,
					     enum nl80211_reg_initiator
					     initiator)
{
	struct ieee80211_supported_band *sband;
	struct ieee80211_channel *ch;
	const struct ieee80211_reg_rule *reg_rule;
	u32 bandwidth = 0;
	int r;

	if (!wiphy->bands[IEEE80211_BAND_2GHZ])
		return;
	sband = wiphy->bands[IEEE80211_BAND_2GHZ];

	/*
	 * If no country IE has been received always enable active scan
	 * on these channels. This is only done for specific regulatory SKUs
	 */
	if (initiator != NL80211_REGDOM_SET_BY_COUNTRY_IE) {
		ch = &sband->channels[11];	/* CH 12 */
		if (ch->flags & IEEE80211_CHAN_PASSIVE_SCAN)
			ch->flags &= ~IEEE80211_CHAN_PASSIVE_SCAN;
		ch = &sband->channels[12];	/* CH 13 */
		if (ch->flags & IEEE80211_CHAN_PASSIVE_SCAN)
			ch->flags &= ~IEEE80211_CHAN_PASSIVE_SCAN;
		return;
	}

	/*
	 * If a country IE has been received check its rule for this
	 * channel first before enabling active scan. The passive scan
	 * would have been enforced by the initial processing of our
	 * custom regulatory domain.
	 */

	ch = &sband->channels[11];	/* CH 12 */
	r = freq_reg_info(wiphy, ch->center_freq, bandwidth, &reg_rule);
	if (!r) {
		if (!(reg_rule->flags & NL80211_RRF_PASSIVE_SCAN))
			if (ch->flags & IEEE80211_CHAN_PASSIVE_SCAN)
				ch->flags &= ~IEEE80211_CHAN_PASSIVE_SCAN;
	}

	ch = &sband->channels[12];	/* CH 13 */
	r = freq_reg_info(wiphy, ch->center_freq, bandwidth, &reg_rule);
	if (!r) {
		if (!(reg_rule->flags & NL80211_RRF_PASSIVE_SCAN))
			if (ch->flags & IEEE80211_CHAN_PASSIVE_SCAN)
				ch->flags &= ~IEEE80211_CHAN_PASSIVE_SCAN;
	}
}
#endif

/*
 * Always apply Radar/DFS rules on
 * freq range 5260 MHz - 5700 MHz
 */
static void _tlw_reg_apply_radar_flags(struct wiphy *wiphy)
{
	struct ieee80211_supported_band *sband;
	struct ieee80211_channel *ch;
	unsigned int i;

	if (!wiphy->bands[IEEE80211_BAND_5GHZ])
		return;

	sband = wiphy->bands[IEEE80211_BAND_5GHZ];

	for (i = 0; i < sband->n_channels; i++) {
		ch = &sband->channels[i];
		if (!_tlw_is_radar_freq(ch->center_freq))
			continue;
#ifdef CONFIG_DFS
		#if defined(CONFIG_DFS_MASTER) && (LINUX_VERSION_CODE >= KERNEL_VERSION(3, 14, 0))
		if (!(ch->flags & IEEE80211_CHAN_DISABLED)) {
			ch->flags |= IEEE80211_CHAN_RADAR;
			#if (LINUX_VERSION_CODE < KERNEL_VERSION(3,14,0))
			ch->flags |= (IEEE80211_CHAN_NO_IBSS|IEEE80211_CHAN_PASSIVE_SCAN);
			#else
			ch->flags |= IEEE80211_CHAN_NO_IR;
			#endif
		}
		#endif
#endif //CONFIG_DFS

#if 0
		/*
		 * We always enable radar detection/DFS on this
		 * frequency range. Additionally we also apply on
		 * this frequency range:
		 * - If STA mode does not yet have DFS supports disable
		 *  active scanning
		 * - If adhoc mode does not support DFS yet then disable
		 *  adhoc in the frequency.
		 * - If AP mode does not yet support radar detection/DFS
		 *  do not allow AP mode
		 */
		if (!(ch->flags & IEEE80211_CHAN_DISABLED))
			ch->flags |= IEEE80211_CHAN_RADAR |
			    IEEE80211_CHAN_NO_IBSS |
			    IEEE80211_CHAN_PASSIVE_SCAN;
#endif
	}
}

static void _tlw_reg_apply_flags(struct wiphy *wiphy)
{
#if 1				// by channel plan
	_adapter *padapter = wiphy_to_adapter(wiphy);
	u8 channel_plan = padapter->mlmepriv.ChannelPlan;
	struct mlme_ext_priv *pmlmeext = &padapter->mlmeextpriv;
	RT_CHANNEL_INFO *channel_set = pmlmeext->channel_set;
	u8 max_chan_nums = pmlmeext->max_chan_nums;

	struct ieee80211_supported_band *sband;
	struct ieee80211_channel *ch;
	unsigned int i, j;
	u16 channel;
	u32 freq;

	// all channels disable
	for (i = 0; i < IEEE80211_NUM_BANDS; i++) {
		sband = wiphy->bands[i];

		if (sband) {
			for (j = 0; j < sband->n_channels; j++) {
				ch = &sband->channels[j];

				if (ch)
					ch->flags = IEEE80211_CHAN_DISABLED;
			}
		}
	}

	// channels apply by channel plans.
	for (i = 0; i < max_chan_nums; i++) {
		channel = channel_set[i].ChannelNum;
		freq = tlw_ch2freq(channel);

		ch = ieee80211_get_channel(wiphy, freq);
		if (ch) {
			if (channel_set[i].ScanType == SCAN_PASSIVE) {
				#if defined(CONFIG_DFS_MASTER) && (LINUX_VERSION_CODE < KERNEL_VERSION(3, 14, 0))
				ch->flags = 0;
				#elif (LINUX_VERSION_CODE < KERNEL_VERSION(3, 14, 0))
				ch->flags = (IEEE80211_CHAN_NO_IBSS|IEEE80211_CHAN_PASSIVE_SCAN);
				#else
				ch->flags = IEEE80211_CHAN_NO_IR;
				#endif
			}
			else {
				ch->flags = 0;
			}
		}
	}

#else
	struct ieee80211_supported_band *sband;
	struct ieee80211_channel *ch;
	unsigned int i, j;
	u16 channels[37] =
	    { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 36, 40, 44, 48, 52, 56,
		60, 64, 100, 104, 108, 112, 116, 120, 124, 128, 132, 136, 140,
		149, 153,
		157, 161, 165
	};
	u16 channel;
	u32 freq;

	for (i = 0; i < IEEE80211_NUM_BANDS; i++) {
		sband = wiphy->bands[i];

		if (sband)
			for (j = 0; j < sband->n_channels; j++) {
				ch = &sband->channels[j];

				if (ch)
					ch->flags = IEEE80211_CHAN_DISABLED;
			}
	}

	for (i = 0; i < 37; i++) {
		channel = channels[i];
		freq = tlw_ch2freq(channel);

		ch = ieee80211_get_channel(wiphy, freq);
		if (ch) {
			if (channel <= 11)
				ch->flags = 0;
			else
				ch->flags = 0;	//IEEE80211_CHAN_PASSIVE_SCAN;
		}
		//printk("%s: freq %d(%d) flag 0x%02X \n", __func__, freq, channel, ch->flags);
	}
#endif
}

static void _tlw_reg_apply_world_flags(struct wiphy *wiphy,
				       enum nl80211_reg_initiator initiator,
				       struct tlw_regulatory *reg)
{
	//_tlw_reg_apply_beaconing_flags(wiphy, initiator);
	//_tlw_reg_apply_active_scan_flags(wiphy, initiator);
	return;
}

static int _tlw_reg_notifier_apply(struct wiphy *wiphy,
				   struct regulatory_request *request,
				   struct tlw_regulatory *reg)
{

	/* Hard code flags */
	_tlw_reg_apply_flags(wiphy);

	/* We always apply this */
	_tlw_reg_apply_radar_flags(wiphy);

	switch (request->initiator) {
	case NL80211_REGDOM_SET_BY_DRIVER:
		DBG_9081C("%s: %s\n", __func__, "NL80211_REGDOM_SET_BY_DRIVER");
		_tlw_reg_apply_world_flags(wiphy, NL80211_REGDOM_SET_BY_DRIVER,
					   reg);
		break;
	case NL80211_REGDOM_SET_BY_CORE:
		DBG_9081C("%s: %s\n", __func__,
			  "NL80211_REGDOM_SET_BY_CORE to DRV");
		_tlw_reg_apply_world_flags(wiphy, NL80211_REGDOM_SET_BY_DRIVER,
					   reg);
		break;
	case NL80211_REGDOM_SET_BY_USER:
		DBG_9081C("%s: %s\n", __func__,
			  "NL80211_REGDOM_SET_BY_USER to DRV");
		_tlw_reg_apply_world_flags(wiphy, NL80211_REGDOM_SET_BY_DRIVER,
					   reg);
		break;
	case NL80211_REGDOM_SET_BY_COUNTRY_IE:
		DBG_9081C("%s: %s\n", __func__,
			  "NL80211_REGDOM_SET_BY_COUNTRY_IE");
		_tlw_reg_apply_world_flags(wiphy, request->initiator, reg);
		break;
	}

	return 0;
}

static const struct ieee80211_regdomain *_tlw_regdomain_select(struct
							       tlw_regulatory
							       *reg)
{
#if 0
	switch (reg->country_code) {
	case COUNTRY_CODE_USER:
	default:
		return &tlw_regdom_rd;
	}
#else
	return &tlw_regdom_rd;
#endif
}

void _tlw_reg_notifier(struct wiphy *wiphy, struct regulatory_request *request)
{
	struct tlw_regulatory *reg = NULL;

	DBG_9081C("%s\n", __func__);

	_tlw_reg_notifier_apply(wiphy, request, reg);
}

#if (LINUX_VERSION_CODE < KERNEL_VERSION(3,9,0))
int tlw_reg_notifier(struct wiphy *wiphy, struct regulatory_request *request)
#else
void tlw_reg_notifier(struct wiphy *wiphy, struct regulatory_request *request)
#endif
{
	_tlw_reg_notifier(wiphy, request);
	#if (LINUX_VERSION_CODE < KERNEL_VERSION(3,9,0))
	return 0;
	#endif
}

void tlw_reg_notify_by_driver(_adapter *adapter)
{
	if ((adapter->tlw_wdev != NULL) && (adapter->tlw_wdev->wiphy)) {
		struct regulatory_request request;
		request.initiator = NL80211_REGDOM_SET_BY_DRIVER;
		tlw_reg_notifier(adapter->tlw_wdev->wiphy, &request);
	}
}

static void _tlw_regd_init_wiphy(struct tlw_regulatory *reg, struct wiphy *wiphy)
{
	const struct ieee80211_regdomain *regd;

	wiphy->reg_notifier = tlw_reg_notifier;

	#if (LINUX_VERSION_CODE < KERNEL_VERSION(3,14,0))
	wiphy->flags |= WIPHY_FLAG_CUSTOM_REGULATORY;
	wiphy->flags &= ~WIPHY_FLAG_STRICT_REGULATORY;
	wiphy->flags &= ~WIPHY_FLAG_DISABLE_BEACON_HINTS;
	#else
	wiphy->regulatory_flags |= REGULATORY_CUSTOM_REG;
	wiphy->regulatory_flags &= ~REGULATORY_STRICT_REG;
	wiphy->regulatory_flags &= ~REGULATORY_DISABLE_BEACON_HINTS;
	#endif
	
	regd = _tlw_regdomain_select(reg);
	wiphy_apply_custom_regulatory(wiphy, regd);

	/* Hard code flags */
	_tlw_reg_apply_flags(wiphy);
	_tlw_reg_apply_radar_flags(wiphy);
	_tlw_reg_apply_world_flags(wiphy, NL80211_REGDOM_SET_BY_DRIVER, reg);
}

static struct country_code_to_enum_rd *_tlw_regd_find_country(u16 countrycode)
{
	int i;

	for (i = 0; i < ARRAY_SIZE(allCountries); i++) {
		if (allCountries[i].countrycode == countrycode)
			return &allCountries[i];
	}
	return NULL;
}

int tlw_regd_init(_adapter * padapter)
{
	struct wiphy *wiphy = padapter->tlw_wdev->wiphy;

#if 0
	if (tlw_regd == NULL) {
		tlw_regd = (struct tlw_regulatory *)
		    tlw_malloc(sizeof(struct tlw_regulatory));

		tlw_regd->alpha2[0] = '9';
		tlw_regd->alpha2[1] = '9';

		tlw_regd->country_code = COUNTRY_CODE_USER;
	}

	DBG_9081C("%s: Country alpha2 being used: %c%c\n",
		  __func__, tlw_regd->alpha2[0], tlw_regd->alpha2[1]);
#endif

	_tlw_regd_init_wiphy(NULL, wiphy);

	return 0;
}
#endif //CONFIG_IOCTL_CFG80211

