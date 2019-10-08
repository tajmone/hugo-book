#!/bin/bash
# ------------------------------------------------------------------------------
# By Tristano Ajmone, released into the public domain via the Unlicense.
# ------------------------------------------------------------------------------
# This script requires Dart Sass to be installed on the system:
#     https://github.com/sass/dart-sass
#
# Under Windows you can use Chocolatey to install Dart Sass and keep it updated:
#     https://chocolatey.org/packages/sass
# ------------------------------------------------------------------------------
source ../../assets/sh/_print-funcs.sh
source ../../assets/sh/_build-funcs.sh
shopt -s nullglob # Set nullglob to avoid patterns matching null files

function buildSass {
  printHeading2 "Compile Sass/SCSS to CSS"
  echo -e "\e[90mSASS INPUT: \e[93m$1\e[0m"
  echo -e "\e[90mCSS OUTPUT: \e[93m$2\e[0m"
  sass $1 $2
  normalizeEOL $2
}

function docinfoInject {
  # ============================================================================
  # Create ad hoc "docinfo.html" file by injecting a CSS file into it.
  # ----------------------------------------------------------------------------
  # Parameters:
  # - $1: source CSS file.
  # - $2: destination docinfo file.
  # ============================================================================
  sourceCSS=$1
  destDocinfo=$2
  printHeading2 "Inject CSS stylesheet in docinfo File"
  echo -e "\e[90mCSS INPUT FILE: \e[93m$sourceCSS\e[0m"
  echo -e "\e[90mDOCINFO OUTPUT: \e[93m$destDocinfo\e[0m"

  echo "<style>"   > $destDocinfo
  cat $sourceCSS  >> $destDocinfo
  echo "</style>" >> $destDocinfo
  normalizeEOL $destDocinfo
}

printBanner "Build Hugo Book CSS Stylesheet from Sass/SCSS"
#*******************************************************************************
printHeading1 "Compile SCSS Stylesheet"
#*******************************************************************************
css=hugo-book.css
docinfo=../../docs_src/docinfo.html
buildSass hugo-book.scss $css
#*******************************************************************************
printHeading1 "Create docinfo File"
#*******************************************************************************
docinfoInject $css $docinfo
# ------------------------------------------------------------------------------
printFinished
exit
# ==============================================================================
#                                 The Unlicense
# ==============================================================================
# This is free and unencumbered software released into the public domain.
#
# Anyone is free to copy, modify, publish, use, compile, sell, or
# distribute this software, either in source code form or as a compiled
# binary, for any purpose, commercial or non-commercial, and by any
# means.
#
# In jurisdictions that recognize copyright laws, the author or authors
# of this software dedicate any and all copyright interest in the
# software to the public domain. We make this dedication for the benefit
# of the public at large and to the detriment of our heirs and
# successors. We intend this dedication to be an overt act of
# relinquishment in perpetuity of all present and future rights to this
# software under copyright law.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
# EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
# MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
# IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
# OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
# ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
# OTHER DEALINGS IN THE SOFTWARE.
#
# For more information, please refer to <http://unlicense.org>
# ------------------------------------------------------------------------------
# EOF #
