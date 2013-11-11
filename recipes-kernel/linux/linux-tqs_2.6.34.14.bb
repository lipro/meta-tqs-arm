# Adapted from linux-imx.inc, copyright (C) 2013 Li-Pro.Net
# Released under the MIT license (see COPYING.MIT for the terms)

require linux-tqs.inc

COMPATIBLE_MACHINE = "(qemuarm|tqma35)"

PR = "${INC_PR}.1"

# Kernel version and SRCREV correspond to:
# github.com/lipro v2.6.34.14-tqma35-0104 tag
LINUX_VERSION = "2.6.34.14"
LINUX_VERSION_EXTENSION = "-tqma35-0104"
SRCREV = "6b4ea726b39f32041ac4d2dd03cf056c57b638ac"
