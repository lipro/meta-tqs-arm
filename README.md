OpenEmbedded/Yocto BSP layer for TQ System's ARM based platforms
================================================================

This layer provides support for TQ System's ARM based platforms for
use with OpenEmbedded and/or Yocto Freescale's BSP layer.

This layer depends on:

- URI: git://git.yoctoproject.org/meta-fsl-arm
    - branch: dylan
    - revision: HEAD

Contributing
------------

To contribute to this layer you should submit the patches for review
to the authors mailing address (rexut95@gmail.com).

Issue tracker:

    https://github.com/lipro/meta-tqs-arm/issues

Source code:

    https://github.com/lipro/meta-tqs-arm

When creating a patch of the last commit, use:

    git format-patch -s --subject-prefix='meta-tqs-arm][PATCH' -1

To send it to the community, use:

    git send-email --to rexut95@gmail.com <generated patch>
