require recipes-kernel/linux-libc-headers/linux-libc-headers.inc

COMPATIBLE_MACHINE = "(qemuarm|tqma35)"

PR = "r0"

PROVIDES = "linux-libc-headers"
RPROVIDES_${PN}-dev = "linux-libc-headers-dev"
RPROVIDES_${PN}-dbg = "linux-libc-headers-dbg"

SRCREV = "6b4ea726b39f32041ac4d2dd03cf056c57b638ac"
SRC_URI = "git://github.com/lipro/linux-tqs.git;protocol=git;branch=tqma35 \
           file://0001-ARM-6329-1-wire-up-sys_accept4-on-ARM.patch \
           file://linux-2.6.34-armv6-armv7-for-versatilepb.patch \
          "
# R: linux-tqs
# B: mach-versatile
SRC_URI_append_qemuall += " \
	file://0001-ARM-versatile-fix-endianess-in-panel-setup-RGB-BGR.patch \
"

S = "${WORKDIR}/git"

FILESEXTRAPATHS_prepend := "${THISDIR}/linux-tqs:"
