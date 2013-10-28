# Adapted from linux-imx.inc, copyright (C) 2013 Alere Technologies GmbH
# Released under the MIT license (see COPYING.MIT for the terms)

require recipes-kernel/linux/linux-imx.inc

DESCRIPTION = "Linux kernel for TQ System Embedded modules"
COMPATIBLE_MACHINE = "(qemuarm|tqma35)"

PV = "2.6.34.14+git${SRCPV}"
PR = "${INC_PR}.1"

SRCREV = "6b4ea726b39f32041ac4d2dd03cf056c57b638ac"
SRC_URI = "git://github.com/lipro/linux-tqs.git;branch=tqma35 \
           file://0001-ARM-6329-1-wire-up-sys_accept4-on-ARM.patch \
           file://linux-2.6.34-armv6-armv7-for-versatilepb.patch \
           file://defconfig"

LOCALVERSION = "-tqma35-0104"

# Avoid imx-test installation hacks
IMX_TEST_SUPPORT = "n"
