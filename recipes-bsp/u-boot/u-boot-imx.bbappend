FILESEXTRAPATHS:prepend := "${THISDIR}/files:"

inherit resin-u-boot

SRC_URI:append = " \
	file://0001-adapts-to-robustel-eg5120-hardware-and-adds-support-.patch \
	file://0002-add-boot-from-usb-stick-support.patch \
"
