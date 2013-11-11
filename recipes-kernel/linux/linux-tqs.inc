# Copyright (C) 2012-2013 O.S. Systems Software LTDA.
# Released under the MIT license (see COPYING.MIT for the terms)

DESCRIPTION = "TQ Systems Community stable based Linux kernel"
LICENSE = "GPLv2"

LIC_FILES_CHKSUM = "file://COPYING;md5=d7810fab7487fb0aad327b76f1be7cd7"

DEPENDS += "lzop-native"
PROVIDES = "virtual/kernel linux-stable"

inherit kernel

require recipes-kernel/linux/linux-imx.inc
require recipes-kernel/linux/linux-dtb.inc

# Avoid imx-test installation hacks
IMX_TEST_SUPPORT = "n"

# This version extension should match CONFIG_LOCALVERSION in defconfig
LINUX_VERSION_EXTENSION ?= "-tqs"
LOCALVERSION = "${LINUX_VERSION_EXTENSION}"
PV = "${LINUX_VERSION}${LINUX_VERSION_EXTENSION}+git${SRCREV}"

SRC_URI = "git://github.com/lipro/linux-tqs.git;protocol=git;branch=tqma35 \
           file://0001-ARM-6329-1-wire-up-sys_accept4-on-ARM.patch \
           file://linux-2.6.34-armv6-armv7-for-versatilepb.patch \
           file://defconfig"
