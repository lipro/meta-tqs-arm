# Adapted from linux-imx.inc, copyright (C) 2013 Li-Pro.Net
# Released under the MIT license (see COPYING.MIT for the terms)

require recipes-bsp/u-boot/u-boot.inc

DESCRIPTION = "TQ Systems Community mainline based U-Boot"
LICENSE = "GPLv2+"

LIC_FILES_CHKSUM = "file://COPYING;md5=4c6cde5df68eff615d36789dc18edd3b"

PROVIDES += "u-boot"

# This version extension should match CONFIG_IDENT_STRING in config header
UBOOT_VERSION_EXTENSION ?= "-tqs"
PV = "${UBOOT_VERSION}${UBOOT_VERSION_EXTENSION}+git${SRCREV}"
PR = "r1"

SRC_URI = "git://github.com/lipro/u-boot-tqs.git;protocol=git"

S = "${WORKDIR}/git"
PACKAGE_ARCH = "${MACHINE_ARCH}"
