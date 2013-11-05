SUMMARY = "/dev/ and hotplug management daemon"
DESCRIPTION = "udev is a daemon which dynamically creates and removes device nodes from \
/dev/, handles hotplug events and loads drivers at boot time."
HOMEPAGE = "http://www.kernel.org/pub/linux/utils/kernel/hotplug/udev/udev.html"
LICENSE = "GPLv2.0+ & LGPLv2.1+"
LICENSE_${PN} = "GPLv2.0+"
LICENSE_libudev = "LGPLv2.1+"
LICENSE_libgudev = "LGPLv2.1+"
LIC_FILES_CHKSUM = "file://COPYING;md5=751419260aa954499f7abaabaa882bbe \
                    file://libudev/COPYING;md5=a6f89e2100d9b6cdffcea4f398e37343 \
                    file://extras/gudev/COPYING;md5=a6f89e2100d9b6cdffcea4f398e37343"

DEPENDS = "acl glib-2.0 libusb usbutils pciutils gperf-native libxslt-native util-linux"
RPROVIDES_${PN} = "hotplug"
RRECOMMENDS_${PN} += "udev-extraconf usbutils-ids pciutils-ids"
RDEPENDS_libudev = "${PN} (= ${EXTENDPKGV})"

# Needs blkid from this particular package. The one in e2fsprogs is
# old and incompatible.
RDEPENDS_${PN} += "util-linux-blkid"

# http://pkgs.fedoraproject.org/lookaside/pkgs/udev/udev-${PV}.tar.bz2/${SRC_URI[md5sum]}/udev-${PV}.tar.bz2
SRC_URI = "http://ftp.sunet.se/pub/Linux/kernel.org/linux/utils/kernel/hotplug/udev-${PV}.tar.bz2 \
           file://run.rules \
           file://udev.rules \
           file://devfs-udev.rules \
           file://links.conf \
           file://permissions.rules \
           file://local.rules \
           file://udev-cache \
           file://udev-cache.default \
           file://init \
           file://volatiles"

inherit autotools pkgconfig update-rc.d

libexecdir = "${base_libdir}"
EXTRA_OECONF = "--disable-introspection \
                --with-rootlibdir=${base_libdir} \
                --with-pci-ids-path=${datadir}/pci.ids \
                ac_cv_file__usr_share_pci_ids=no \
                ac_cv_file__usr_share_hwdata_pci_ids=no \
                ac_cv_file__usr_share_misc_pci_ids=yes \
                --sbindir=${base_sbindir} \
                --libexecdir=${nonarch_base_libdir}/udev \
                --with-rootlibdir=${base_libdir} \
                --without-systemdsystemunitdir \
               "

PACKAGES =+ "udev-utils udev-cache"
PACKAGES =+ "libudev libudev-dev libudev-dbg"
PACKAGES =+ "libgudev libgudev-dev libgudev-dbg"

INITSCRIPT_PACKAGES = "udev udev-cache"
INITSCRIPT_NAME_udev = "udev"
INITSCRIPT_PARAMS_udev = "start 03 S ."
INITSCRIPT_NAME_udev-cache = "udev-cache"
INITSCRIPT_PARAMS_udev-cache = "start 36 S ."

FILES_${PN} += "${libexecdir} ${libdir}/ConsoleKit ${nonarch_base_libdir}/udev"
RRECOMMENDS_${PN} += "udev-utils"

FILES_${PN}-dbg += "${libexecdir}/.debug"
FILES_${PN}-dbg += "${base_libdir}/udev/.debug/"
FILES_${PN}-dbg += "${base_libdir}/udev/.debug/*"
FILES_${PN}-dbg += "${nonarch_base_libdir}/udev/.debug/*"
FILES_${PN}-dev = "${datadir}/pkgconfig/udev.pc"
FILES_libudev = "${base_libdir}/libudev.so.*"
FILES_libudev-dbg = "${base_libdir}/.debug/libudev.so.*"
FILES_libudev-dev = "${includedir}/libudev.h ${libdir}/libudev.so ${libdir}/libudev.la \
                     ${libdir}/libudev.a ${libdir}/pkgconfig/libudev.pc"
FILES_libgudev = "${base_libdir}/libgudev*.so.* ${libdir}/libgudev*.so.*"
FILES_libgudev-dbg = "${base_libdir}/.debug/libgudev*.so.* ${libdir}/.debug/libgudev*.so.*"
FILES_libgudev-dev = "${includedir}/gudev* ${libdir}/libgudev*.so ${libdir}/libgudev*.la \
                     ${libdir}/libgudev*.a ${libdir}/pkgconfig/gudev*.pc"
FILES_udev-cache = "${sysconfdir}/init.d/udev-cache ${sysconfdir}/default/udev-cache"

FILES_udev-utils = "${bindir}/udevadm"

do_install_append () {
	install -d ${D}${sysconfdir}/init.d
	install -m 0755 ${WORKDIR}/init ${D}${sysconfdir}/init.d/udev
	install -m 0755 ${WORKDIR}/udev-cache ${D}${sysconfdir}/init.d/udev-cache
	sed -i s%@UDEVD@%${base_sbindir}/udevd% ${D}${sysconfdir}/init.d/udev
	sed -i s%@UDEVD@%${base_sbindir}/udevd% ${D}${sysconfdir}/init.d/udev-cache

	install -d ${D}${sysconfdir}/default
	install -m 0755 ${WORKDIR}/udev-cache.default ${D}${sysconfdir}/default/udev-cache

	install -d ${D}${sysconfdir}/default/volatiles
	install -m 0644 ${WORKDIR}/volatiles ${D}${sysconfdir}/default/volatiles/00_udev

	touch ${D}${sysconfdir}/udev/cache.data

	install -d ${D}${sysconfdir}/udev/rules.d/

	install -m 0644 ${WORKDIR}/local.rules         ${D}${sysconfdir}/udev/rules.d/local.rules

	# hid2hci has moved to bluez4. removed in udev as of version 169
	rm -f ${D}${base_libdir}/udev/hid2hci

	echo 'udev_run="/var/run/udev"' >> ${D}${sysconfdir}/udev/udev.conf
}

# As systemd also builds udev, skip this package if we're doing a systemd build.
python () {
    if oe.utils.contains ('DISTRO_FEATURES', 'systemd', True, False, d):
        raise bb.parse.SkipPackage("'systemd' in DISTRO_FEATURES")
}
