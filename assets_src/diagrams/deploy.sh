#!/bin/bash

# "assets_src/diagrams/deploy.sh"                          | v0.0.1 | 2019/10/10
# ------------------------------------------------------------------------------
# By Tristano Ajmone, released into the public domain via the Unlicense.
# ------------------------------------------------------------------------------
destDir=../../docs_src/

. ../../assets/sh/_print-funcs.sh

printBanner "Copying Built SVG diagrams to Hugo Book Source Folder"
echo -e "Destination folder: \e[93m$destDir\e[0m"
printSeparator

cp -v *.svg $destDir

printFinished

# EOF #
