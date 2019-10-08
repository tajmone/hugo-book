#!/bin/bash

# "docs_src/build.sh"                                      | v0.0.1 | 2019/10/08
# ------------------------------------------------------------------------------
# By Tristano Ajmone, released into the public domain via the Unlicense.
# ------------------------------------------------------------------------------
# This script requires installation of the following applications:
#
#     Asciidoctor (Ruby gem):
#     https://asciidoctor.org
#
#     Highlight >= 3.51:
#     http://www.andre-simon.de
# ------------------------------------------------------------------------------
source=hugo-book.asciidoc
output=hugo-book.html

# Highlight Set-up
# ================
# We need to override Highlight default settings and langDefs with our custom
# versions, and make visible any other custom scripts inside ../assets/hl/.
export HIGHLIGHT_DATADIR="$(pwd)/../assets/hl"

. ../assets/sh/_print-funcs.sh

printBanner "Hugo Book: Final HTML Document"
echo -e "Converting to standalone HTML document (\e[93m$output\e[0m):"
echo -e "\e[91m *\e[0m TOC levels: 1."
echo -e "\e[91m *\e[0m Single document."
echo -e "\e[91m *\e[0m Custom Haml HTML5 templates."
echo -e "\e[91m *\e[0m Syntax highlighting via Highlight (no JS dependencies)."

asciidoctor \
  --verbose \
  --safe-mode unsafe \
  -a data-uri \
  -a experimental \
  -a icons=font \
  -a sectanchors \
  -a toc=left \
  -a toclevels=1 \
  -a reproducible \
  -a docinfo=shared-head \
  -a source-highlighter=highlight \
  --require      ../assets/adoc/highlight-treeprocessor_mod.rb \
  --template-dir ../assets/adoc/haml \
  -o  $output \
      $source

# EOF #
