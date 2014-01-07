# TQ Systems BSP default image content

IMAGE_FEATURES += "ssh-server-openssh"
IMAGE_INSTALL += "openssh-sftp-server"

IMAGE_INSTALL += "${@base_contains('MACHINE_FEATURES', 'touchscreen', 'tslib-conf tslib-calibrate', '', d)}"
IMAGE_INSTALL += "${@base_contains('MACHINE_FEATURES', 'flash', 'mtd-utils mtd-utils-jffs2', '', d)}"
