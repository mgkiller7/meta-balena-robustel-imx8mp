include balena-image.inc

BALENA_BOOT_PARTITION_FILES:append = " \
	${DEPLOY_DIR_IMAGE}/imx-boot-${MACHINE}-sd.bin-flash_evk:/imx-boot.bin \
"

BALENA_BOOT_PARTITION_FILES:append = " \
    system-connections/eth1.nmconnection:/system-connections/eth1.nmconnection \
"
