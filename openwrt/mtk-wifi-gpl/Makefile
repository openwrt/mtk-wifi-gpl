# All rights reserved.
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.

include $(TOPDIR)/rules.mk
include $(INCLUDE_DIR)/kernel.mk

PKG_NAME:=mtk-wifi-gpl
PKG_VERSION:=2014-09-26

PKG_BUILD_PARALLEL:=1

include $(INCLUDE_DIR)/package.mk

define KernelPackage/mtk-wifi-gpl
  SECTION:=kernel
  CATEGORY:=Kernel modules
  TITLE:=Mediatek MT76x2 802.11ac device driver
  DEPENDS:=+kmod-cfg80211
  FILES:=$(PKG_BUILD_DIR)/os/linux/mt76x2.ko
  AUTOLOAD:=$(call AutoLoad,91,MT76x2_ap)
  SUBMENU:=Wireless Drivers
endef

define Build/Prepare
	mkdir -p $(PKG_BUILD_DIR)
	ln -s $(CURDIR)/../../.git $(PKG_BUILD_DIR)
	(cd $(PKG_BUILD_DIR); git checkout .)
endef

define Build/Compile
	+$(MAKE) $(PKG_JOBS) -C "$(LINUX_DIR)" \
		CROSS_COMPILE="$(TARGET_CROSS)" \
		ARCH="$(LINUX_KARCH)" \
		SUBDIRS="$(PKG_BUILD_DIR)/os/linux/" \
		RT28xx_DIR="$(PKG_BUILD_DIR)" \
		NOSTDINC_FLAGS="-I$(STAGING_DIR)/usr/include/mac80211-backport/uapi -I$(STAGING_DIR)/usr/include/mac80211-backport \
			-I$(STAGING_DIR)/usr/include/mac80211/uapi -I$(STAGING_DIR)/usr/include/mac80211 \
			-include backport/backport.h \
			-Wno-unused-variable -Wno-unused-function \
			-Wno-return-type" \
		modules
endef

define KernelPackage/mtk-wifi-gpl/install
	$(INSTALL_DIR) $(1)/etc/Wireless/RT2860AP
	$(CP) $(PKG_BUILD_DIR)/conf/RT2860AP.dat_ac $(1)/etc/Wireless/RT2860AP/RT2860AP.dat
endef

$(eval $(call KernelPackage,mtk-wifi-gpl))
