RT28xx_MODE := AP
CHIPSET := mt7612e

WFLAGS := -g -DAGGREGATION_SUPPORT -DPIGGYBACK_SUPPORT -DWMM_SUPPORT  -DLINUX -Wall -Wstrict-prototypes -Wno-trigraphs -DENHANCED_STAT_DISPLAY
WFLAGS += -DSYSTEM_LOG_SUPPORT -DRT28xx_MODE=$(RT28xx_MODE) -DCHIPSET=$(MODULE) -DRESOURCE_PRE_ALLOC -DDBG_DIAGNOSE -DDBG_RX_MCS -DDBG_TX_MCS
WFLAGS += -DCONFIG_RA_NAT_NONE
WFLAGS += -DDOT11_VHT_AC
WFLAGS += -DCAL_FREE_IC_SUPPORT
WFLAGS += -DDOT11_N_SUPPORT
WFLAGS += -DNEW_RATE_ADAPT_SUPPORT
WFLAGS += -DAGS_SUPPORT
WFLAGS += -DRT_CFG80211_SUPPORT -DEXT_BUILD_CHANNEL_LIST -DWPA_SUPPLICANT_SUPPORT
WFLAGS += -DCONFIG_AP_SUPPORT -DUAPSD_SUPPORT -DMBSS_SUPPORT -DAP_SCAN_SUPPORT
WFLAGS += -DNEW_RATE_ADAPT_SUPPORT
WFLAGS += -DCONFIG_STA_SUPPORT -DAP_SCAN_SUPPORT
WFLAGS += -DMT76x2 -DRT65xx -DRLT_MAC -DRLT_BBP -DMT_RF -DRTMP_MAC_PCI -DRTMP_PCI_SUPPORT -DA_BAND_SUPPORT -DRX_DMA_SCATTER -DNEW_MBSSID_MODE -DRTMP_EFUSE_SUPPORT -DCONFIG_ANDES_SUPPORT -DENHANCE_NEW_MBSSID_MODE -DRTMP_RF_RW_SUPPORT -DDYNAMIC_VGA_SUPPORT
WFLAGS += -DFIFO_EXT_SUPPORT
WFLAGS += -DMT7612
WFLAGS += -DMT7632
WFLAGS += -DMT7662
WFLAGS += -DMULTI_INF_SUPPORT
WFLAGS += -I$(RT28xx_DIR)/include
WFLAGS += -DCONFIG_RT_SECOND_IF_RF_OFFSET=0
WFLAGS += -DSCAN_SUPPORT
ifdef CONFIG_CPU_BIG_ENDIAN
WFLAGS += -DRT_BIG_ENDIAN
endif
WFLAGS += -DDBG

WFLAGS += -Wno-declaration-after-statement

MOD_NAME = mt76x2

EXTRA_CFLAGS += $(WFLAGS)

obj_ap :=
obj_sta :=
obj_p2p :=
obj_wsc :=
obj_vht :=
obj_cmm := \
        ../../common/crypt_md5.o\
        ../../common/crypt_sha2.o\
        ../../common/crypt_hmac.o\
        ../../common/crypt_aes.o\
        ../../common/crypt_arc4.o\
        ../../common/mlme.o\
        ../../common/cmm_wep.o\
        ../../common/action.o\
        ../../common/cmm_data.o\
        ../../common/rtmp_init.o\
        ../../common/rtmp_init_inf.o\
        ../../common/cmm_tkip.o\
        ../../common/cmm_aes.o\
        ../../common/cmm_sync.o\
        ../../common/eeprom.o\
        ../../common/cmm_sanity.o\
        ../../common/cmm_info.o\
        ../../common/cmm_cfg.o\
        ../../common/cmm_wpa.o\
        ../../common/cmm_radar.o\
        ../../common/spectrum.o\
        ../../common/rtmp_timer.o\
        ../../common/rt_channel.o\
        ../../common/cmm_profile.o\
        ../../common/cmm_asic.o\
        ../../common/scan.o\
        ../../common/cmm_cmd.o\
	    ../../common/uapsd.o\
	    ../../common/ps.o\
	    ../../common/sys_log.o\
	    ../../common/txpower.o\
        ../../rate_ctrl/ra_ctrl.o\
        ../../rate_ctrl/alg_legacy.o\
        ../../rate_ctrl/alg_ags.o\
        ../../chips/rtmp_chip.o\
        ../../mgmt/mgmt_hw.o\
        ../../mgmt/mgmt_entrytb.o\
	    ../../tx_rx/wdev_tx.o \
	    ../../os/linux/rt_profile.o


obj_phy := ../../phy/phy.o	\
		   ../../phy/rf.o

obj_mac := ../../mac/rtmp_mac.o

obj_phy += ../../phy/rtmp_phy.o
obj_phy += ../../phy/rlt_phy.o
obj_phy += ../../phy/rlt_rf.o

ifeq ($(HAS_MT76XX_BT_COEXISTENCE_SUPPORT),y)
obj_cmm += ../../mcu/bt_coex.o
endif

obj_mac += ../../mac/ral_nmac.o

ifeq ($(HAS_RTMP_MAC),y)
obj_mac += ../../mac/ral_omac.o
endif

obj_cmm += $(obj_phy) $(obj_mac)

ifeq ($(HAS_BLOCK_NET_IF),y)
obj_cmm += ../../common/netif_block.o
endif

obj_cmm += ../../rate_ctrl/alg_grp.o
obj_cmm += ../../rate_ctrl/alg_ags.o

ifeq ($(HAS_DFS_SUPPORT),y)
obj_cmm += ../../common/cmm_dfs.o
endif

ifeq ($(HAS_CS_SUPPORT),y)
obj_cmm += ../../common/cmm_cs.o
endif

#ifdef LED_CONTROL_SUPPORT
ifeq ($(HAS_LED_CONTROL_SUPPORT),y)
obj_cmm += ../../common/rt_led.o
endif
#endif // LED_CONTROL_SUPPORT //


#ifdef DOT11W_PMF_SUPPORT
ifeq ($(HAS_DOT11W_PMF_SUPPORT),y)
obj_cmm += ../../common/pmf.o
endif
#endif // DOT11W_PMF_SUPPORT //


obj_cmm += \
        ../../common/ba_action.o\
        ../../mgmt/mgmt_ht.o

obj_vht += ../../mgmt/mgmt_vht.o\
	../../common/vht.o







###############################################################################
#
# config for AP mode
#
###############################################################################

#ifdef CONFIG_AP_SUPPORT
obj_ap += \
	../../ap/ap_mbss.o\
	../../ap/ap.o\
	../../ap/ap_assoc.o\
	../../ap/ap_auth.o\
	../../ap/ap_connect.o\
	../../ap/ap_mlme.o\
	../../ap/ap_sanity.o\
	../../ap/ap_sync.o\
	../../ap/ap_wpa.o\
	../../ap/ap_data.o\
	../../ap/ap_autoChSel.o\
	../../ap/ap_qload.o\
	../../ap/ap_cfg.o

ifeq ($(HAS_QOS_DLS_SUPPORT),y)
obj_ap += ../../ap/ap_dls.o
endif

ifeq ($(HAS_IDS_SUPPORT),y)
obj_ap += ../../ap/ap_ids.o
endif

ifeq ($(HAS_WSC),y)
obj_ap += ../../common/wsc_ufd.o
endif



ifeq ($(HAS_WDS),y)
obj_ap += ../../ap/ap_wds.o

ifeq ($(OSABL),NO)
obj_ap += ../../ap/ap_wds_inf.o
endif
endif

obj_ap += \
    ../../ap/ap_mbss_inf.o\
	../../os/linux/ap_ioctl.o



ifeq ($(HAS_CLIENT_WDS_SUPPORT),y)
$(MOD_NAME)-objs += \
	../../common/client_wds.o
endif

ifeq ($(HAS_IGMP_SNOOP_SUPPORT),y)
obj_ap += ../../common/igmp_snoop.o
endif

#endif // CONFIG_AP_SUPPORT //


###############################################################################
#
# config for STA mode
#
###############################################################################



###############################################################################
#
# config for AP/STA mixed mode
#
###############################################################################



###############################################################################
#
# Module Base
#
###############################################################################

obj-m := $(MOD_NAME).o

#ifdef CONFIG_AP_SUPPORT
ifeq ($(RT28xx_MODE),AP)

$(MOD_NAME)-objs := \
	$(obj_ap)\
	$(obj_vht)\
	$(obj_cmm)\
	$(obj_wsc)\
	$(obj_phy)

ifeq ($(HAS_ATE),y)
$(MOD_NAME)-objs += ../../ate/common/rt_ate.o
endif

ifeq ($(HAS_QA_SUPPORT),y)
$(MOD_NAME)-objs += ../../ate/common/rt_qa.o
endif

#ifdef MULTI_INF_SUPPORT
$(MOD_NAME)-objs += ../../os/linux/multi_main_dev.o
#endif // MULTI_INF_SUPPORT //

#ifdef BG_FT_SUPPORT
ifeq ($(OSABL),NO)
ifeq ($(HAS_BGFP_SUPPORT),y)
$(MOD_NAME)-objs += \
	../../os/linux/br_ftph.o
endif
endif
#endif // BG_FT_SUPPORT //

$(MOD_NAME)-objs += \
	../../common/rt_os_util.o\
	../../os/linux/rt_linux.o\
	../../os/linux/rt_main_dev.o

ifeq ($(HAS_SNIFFER_SUPPORT),y)
$(MOD_NAME)-objs += \
	../../sniffer/sniffer_prism.o	\
	../../sniffer/sniffer_radiotap.o
endif

#ifdef CRDA_SUPPORT
$(MOD_NAME)-objs += \
	../../os/linux/cfg80211/cfg80211.o\
	../../os/linux/cfg80211/cfg80211_util.o\
	../../os/linux/cfg80211/cfg80211_scan.o\
	../../os/linux/cfg80211/cfg80211_rx.o\
	../../os/linux/cfg80211/cfg80211_tx.o\
	../../os/linux/cfg80211/cfg80211_inf.o\
	../../os/linux/cfg80211/cfg80211_p2p.o\
	../../os/linux/cfg80211/cfg80211_ap.o\
	../../os/linux/cfg80211/cfg80211drv.o

#endif // CRDA_SUPPORT //

ifeq ($(HAS_RT2880_RT2860_COEXIST),y)	
RT28XX_AP_OBJ += \
	../../os/linux/rt_pci_rbus.o\
	../../os/linux/rt_rbus_pci_util.o\
	../../os/linux/pci_main_dev.o\
	../../common/dfs.o
endif


endif
#endif // CONFIG_AP_SUPPORT //




#chip releated
















#ifdef RTMP_MAC_PCI
#endif // RTMP_MAC_PCI //






#ifdef RT6592
ifneq ($(findstring rt6592,$(CHIPSET)),)
$(MOD_NAME)-objs += \
        ../../common/cmm_mac_pci.o\
        ../../common/cmm_data_pci.o\
        ../../os/linux/rt_rbus_pci_drv.o\
        ../../mcu/mcu.o\
		../../mcu/rtmp_M51.o\
        ../../common/ee_prom.o\
        ../../common/ee_efuse.o\
        ../../common/rt_rf.o\
        ../../chips/rt6592.o

ifeq ($(OSABL),NO)
$(MOD_NAME)-objs += \
        ../../os/linux/rt_pci_rbus.o\
        ../../os/linux/rt_rbus_pci_util.o\
        ../../os/linux/pci_main_dev.o
endif
endif
#endif // RT6592 //



#ifdef RTMP_MAC_PCI
#endif //RTMP_MAC_PCI//




#ifdef MT76x2
$(MOD_NAME)-objs += \
                ../../common/cmm_mac_pci.o\
                ../../common/cmm_data_pci.o\
                ../../os/linux/rt_rbus_pci_drv.o\
				../../common/ee_efuse.o\
                ../../common/ee_prom.o\
				../../chips/rt65xx.o\
                ../../chips/mt76x2.o\
				../../mac/ral_nmac.o\
				../../mcu/mcu.o\
				../../mcu/mcu_and.o\
				../../phy/rt_rf.o\
				../../phy/mt_rf.o

ifeq ($(HAS_RTMP_FLASH_SUPPORT),y)
$(MOD_NAME)-objs += \
        ../../common/ee_flash.o
endif

$(MOD_NAME)-objs += \
                ../../os/linux/rt_pci_rbus.o\
                ../../os/linux/rt_rbus_pci_util.o\
                ../../os/linux/pci_main_dev.o

$(MOD_NAME)-objs += \
        ../../common/frq_cal.o


ifneq ($(or $(findstring mt7662u,$(CHIPSET)),$(findstring mt7612u,$(CHIPSET))),)
$(MOD_NAME)-objs += \
                ../../common/cmm_mac_usb.o\
                ../../common/cmm_data_usb.o\
				../../common/rtusb_io.o\
				../../common/rtusb_data.o\
				../../common/rtusb_bulk.o\
                ../../os/linux/rt_usb.o\
                ../../common/ee_prom.o\
				../../common/ee_efuse.o\
				../../chips/rt65xx.o\
                ../../chips/mt76x2.o\
                ../../mac/ral_nmac.o\
				../../mcu/mcu.o\
                ../../mcu/mcu_and.o\
				../../phy/rt_rf.o\
				../../phy/mt_rf.o

ifeq ($(HAS_RTMP_FLASH_SUPPORT),y)
$(MOD_NAME)-objs += \
        		../../common/ee_flash.o
endif

ifeq ($(HAS_ATE),y)
$(MOD_NAME)-objs += \
        ../../ate/chips/mt76x2_ate.o\
        ../../ate/common/ate_usb.o
endif

ifeq ($(HAS_TSO_SUPPORT),y)
$(MOD_NAME)-objs += \
				../../naf/net_acc.o\
				../../naf/cso.o
endif

ifeq ($(HAS_CSO_SUPPORT), y)
$(MOD_NAME)-objs += \
				../../naf/net_acc.o\
				../../naf/cso.o
endif

ifeq ($(OSABL),NO)
$(MOD_NAME)-objs += \
                ../../os/linux/rt_usb.o\
                ../../os/linux/rt_usb_util.o\
                ../../os/linux/usb_main_dev.o\
				../../common/rtusb_dev_id.o
endif

ifneq ($(findstring $(RT28xx_MODE),STA APSTA),)
$(MOD_NAME)-objs += \
        ../../common/frq_cal.o
endif

endif
#endif // MT76x2 //

#ifdef RT8592
ifneq ($(findstring rt8592,$(CHIPSET)),)
$(MOD_NAME)-objs += \
                ../../common/cmm_mac_pci.o\
                ../../common/cmm_data_pci.o\
                ../../os/linux/rt_rbus_pci_drv.o\
                ../../common/ee_prom.o\
                ../../common/rtmp_mcu.o\
                ../../common/rt_rf.o\
		../../chips/rt65xx.o\
                ../../chips/rt85592.o\
                ../../mac/ral_nmac.o\
				../../mcu/mcu.o\
                ../../mcu/mcu_and.o

ifeq ($(HAS_RTMP_FLASH_SUPPORT),y)
$(MOD_NAME)-objs += \
        ../../common/ee_flash.o
endif

ifeq ($(HAS_ATE),y)
$(MOD_NAME)-objs += \
			../../ate/common/ate_pci.o\
			../../ate/chips/rt85592_ate.o
endif

ifeq ($(OSABL),NO)
$(MOD_NAME)-objs += \
                ../../os/linux/rt_pci_rbus.o\
                ../../os/linux/rt_rbus_pci_util.o\
                ../../os/linux/pci_main_dev.o
endif

ifneq ($(findstring $(RT28xx_MODE),STA APSTA),)
$(MOD_NAME)-objs += \
        ../../common/frq_cal.o
endif

endif
#endif // RT8592 //

