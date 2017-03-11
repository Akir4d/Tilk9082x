
#if DEV_BUS_TYPE == RT_USB_INTERFACE

	#if defined(CONFIG_TLL9083E)
	#include "ttl9083e/HalEfuseMask9083E_USB.h"
	#endif

	#if defined(CONFIG_TLL8812A)
	#include "ttl8812a/HalEfuseMask8812A_USB.h"
	#endif

	#if defined(CONFIG_TLL8821A)
	#include "ttl8812a/HalEfuseMask8821A_USB.h"
	#endif

	#if defined(CONFIG_TLL9081E)
	#include "ttl9081e/HalEfuseMask9081E_USB.h"
	#endif

	#if defined(CONFIG_TLL8723B)
	#include "ttl8723b/HalEfuseMask8723B_USB.h"
	#endif

	#if defined(CONFIG_TLL8814A)
	#include "ttl8814a/HalEfuseMask8814A_USB.h"
	#endif

	#if defined(CONFIG_TLL8703B)
	#include "ttl8703b/HalEfuseMask8703B_USB.h"
	#endif

	#if defined(CONFIG_TLL9083F)
	#include "ttl9083f/HalEfuseMask9083F_USB.h"
	#endif

#elif DEV_BUS_TYPE == RT_PCI_INTERFACE

	#if defined(CONFIG_TLL9083E)
	#include "ttl9083e/HalEfuseMask9083E_PCIE.h"
	#endif

	#if defined(CONFIG_TLL8812A)
	#include "ttl8812a/HalEfuseMask8812A_PCIE.h"
	#endif

	#if defined(CONFIG_TLL8821A)
	#include "ttl8812a/HalEfuseMask8821A_PCIE.h"
	#endif

	#if defined(CONFIG_TLL9081E)
	#include "ttl9081e/HalEfuseMask9081E_PCIE.h"
	#endif

	#if defined(CONFIG_TLL8723B)
	#include "ttl8723b/HalEfuseMask8723B_PCIE.h"
	#endif

	#if defined(CONFIG_TLL8814A)
	#include "ttl8814a/HalEfuseMask8814A_PCIE.h"
	#endif

	#if defined(CONFIG_TLL8703B)
	#include "ttl8703b/HalEfuseMask8703B_PCIE.h"
	#endif

#elif DEV_BUS_TYPE == RT_SDIO_INTERFACE

	#if defined(CONFIG_TLL9083E)
	#include "ttl9083e/HalEfuseMask9083E_SDIO.h"
	#endif

	#if defined(CONFIG_TLL8703B)
	#include "ttl8703b/HalEfuseMask8703B_SDIO.h"
	#endif

	#if defined(CONFIG_TLL9083F)
	#include "ttl9083f/HalEfuseMask9083F_SDIO.h"
	#endif

#endif