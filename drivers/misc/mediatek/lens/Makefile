#
# Makefile for misc devices that really don't fit anywhere else.
#

MTK_PLATFORM := $(subst ",,$(CONFIG_MTK_PLATFORM))
ARCH_MTK_PROJECT := $(subst ",,$(CONFIG_ARCH_MTK_PROJECT))

MTK_CUSTOM_PATH  := $(srctree)/drivers/misc/mediatek

ifneq ($(CONFIG_ARM64), y)
# For arm32, mach folder
MTK_PLATFORM_PATH_ROOT := $(srctree)/arch/arm/mach-$(MTK_PLATFORM)
MTK_PROJECT_PATH_ROOT := $(srctree)/arch/arm/mach-$(MTK_PLATFORM)/$(ARCH_MTK_PROJECT)
  ifneq ($(filter y,$(CONFIG_ARCH_MT6752) $(CONFIG_ARCH_MT6732) $(CONFIG_ARCH_MT6595) $(CONFIG_ARCH_MT6795) $(CONFIG_ARCH_MT6735) $(CONFIG_ARCH_MT6735M) $(CONFIG_ARCH_MT6753) $(CONFIG_ARCH_MT6580)),)
    # For armv8 32bit
    MTK_PLATFORM_PATH_ROOT := $(srctree)/drivers/misc/mediatek/mach/$(MTK_PLATFORM)
    MTK_PROJECT_PATH_ROOT := $(srctree)/drivers/misc/mediatek/mach/$(MTK_PLATFORM)/$(ARCH_MTK_PROJECT)
  endif
else
# For arm64, no mach-xxx folder
MTK_PLATFORM_PATH_ROOT := $(srctree)/drivers/misc/mediatek/mach/$(MTK_PLATFORM)
MTK_PROJECT_PATH_ROOT := $(srctree)/drivers/misc/mediatek/mach/$(MTK_PLATFORM)/$(ARCH_MTK_PROJECT)
endif



subdir-ccflags-y += -I$(MTK_CUSTOM_PATH)/lens/inc
subdir-ccflags-$(CONFIG_MTK_LENS_LC898212XDAF_SUPPORT) += -I$(MTK_CUSTOM_PATH)/lens/common/lc898212xdaf/inc
subdir-ccflags-$(CONFIG_MTK_LENS_BU63165AF_SUPPORT) += -I$(MTK_CUSTOM_PATH)/lens/common/bu63165af/inc

obj-y      += main_lens.o
obj-y      += sub_lens.o


#sanford.lin 20150205 add for aeon
-include $(srctree)/../$(MTK_TARGET_PROJECT_FOLDER)/eastaeon.mk
ifeq ($(AEON_SUPPORT),yes)

ifneq ($(CUSTOM_KERNEL_LENS), )
LENS_LISTS := $(subst ",,$(CUSTOM_KERNEL_LENS))
obj-y += $(foreach LENS,$(LENS_LISTS),common/$(LENS)/)
LENS_DEFINES := $(shell echo $(CUSTOM_KERNEL_LENS) | tr a-z A-Z)
DEFINES += $(foreach LENS,$(LENS_DEFINES),MTK_LENS_$(LENS)_SUPPORT)
ccflags-y += $(addprefix -D, $(DEFINES))
endif

else

obj-$(CONFIG_MTK_LENS_FM50AF_SUPPORT)      += common/fm50af/
obj-$(CONFIG_MTK_LENS_BU6424AF_SUPPORT)    += common/bu6424af/
obj-$(CONFIG_MTK_LENS_BU6429AF_SUPPORT)    += common/bu6429af/
obj-$(CONFIG_MTK_LENS_BU63165AF_SUPPORT)  += common/bu63165af/
obj-$(CONFIG_MTK_LENS_DW9714AF_SUPPORT)    += common/dw9714af/
obj-$(CONFIG_MTK_LENS_DW9761AF_SUPPORT)    += common/dw9761af/
obj-$(CONFIG_MTK_LENS_DW9814AF_SUPPORT)    += common/dw9814af/
obj-$(CONFIG_MTK_LENS_DW9718AF_SUPPORT)    += common/dw9718af/
obj-$(CONFIG_MTK_LENS_LC898212AF_SUPPORT)  += common/lc898212af/
obj-$(CONFIG_MTK_LENS_LC898212XDAF_SUPPORT)  += common/lc898212xdaf/
obj-$(CONFIG_MTK_LENS_LC898122AF_SUPPORT)  += common/lc898122af/
obj-$(CONFIG_MTK_LENS_AD5820AF_SUPPORT)    += common/ad5820af/
obj-$(CONFIG_MTK_LENS_DW9763AF_SUPPORT)    += common/dw9763af/
obj-$(CONFIG_MTK_LENS_OV13850AF_SUPPORT) += common/ov13850af/

endif
#sanford.lin 20150205 end

