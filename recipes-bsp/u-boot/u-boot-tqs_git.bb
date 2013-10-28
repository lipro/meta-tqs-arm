require recipes-bsp/u-boot/u-boot.inc

LICENSE = "GPLv2+"
LIC_FILES_CHKSUM = "file://COPYING;md5=4c6cde5df68eff615d36789dc18edd3b"
COMPATIBLE_MACHINE = "(tqma35)"

PROVIDES += "u-boot"

PV = "v2010.06+git${SRCPV}"

SRCREV = "4faae1c148db9a9d3d64e0104b627095c385f126"
SRC_URI = "git://github.com/lipro/u-boot-tqs.git;branch=tqma35"

S = "${WORKDIR}/git"

PACKAGE_ARCH = "${MACHINE_ARCH}"
