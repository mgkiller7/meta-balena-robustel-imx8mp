# Remove unneeded package installed by the Robsutel BSP (since we use the kernel image with the initramfs embedded instead) 
#   which also makes the balena-image target unbuildable
IMAGE_INSTALL:remove = " kernel-image"

# Increase the rootfs partition size
IMAGE_ROOTFS_SIZE="430080"

DEPENDS += "imx-boot"

# Flash signed bootloader to raw image
IMAGE_CMD:balenaos-img:append () {
    dd if=${DEPLOY_DIR_IMAGE}/imx-boot-${MACHINE}-sd.bin-flash_evk of=${BALENA_RAW_IMG} conv=notrunc seek=32 bs=1K
}

# Add hw-watchdog/dtb-overlay service
IMAGE_INSTALL:append = " \
	hwwatchdog \
	dtboverlay \
"

# Add the following packages to rootfs in order to get bt and wifi work
IMAGE_INSTALL:append = " \
	sd8997-utils \
	linux-firmware-imx-sdma-imx7d \
	modem \
	udev-rules \
	system-connections \
"

# This BSP sets this variable in the machine conf so let's unset it since this makes our build fail
unset ROOTFS_SIZE

TEMPORARILY_ALLOWED_PACKAGES ?= " \
    linux-firmware-rtl8192su \
    linux-firmware-rtl8723b-bt \
    linux-firmware-wl12xx \
    linux-firmware-wl18xx \
    linux-firmware-wlcommon \
"

BALENA_ALLOWED_FIRMWARE_PACKAGES:append = " ${TEMPORARILY_ALLOWED_PACKAGES} "

# This is linux-ffirmware that will be removed
# in the next major balenaOS release
IMAGE_INSTALL:append = " ${TEMPORARILY_ALLOWED_PACKAGES} "

