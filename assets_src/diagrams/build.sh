#!/bin/bash

# "assets_src/diagrams/build.sh"                           | v0.0.1 | 2019/10/10
# ------------------------------------------------------------------------------
# By Tristano Ajmone, released into the public domain via the Unlicense.
# ------------------------------------------------------------------------------
# This script requires installation of the following applications:
#
#     Dia Diagram Editor:
#     http://dia-installer.de
# ------------------------------------------------------------------------------

. ../../assets/sh/_print-funcs.sh

printBanner "Building SVG Diagrams from Dia Sources"

for f in *.dia ; do
	dia -n -t svg $f
done

printFinished

# EOF #
