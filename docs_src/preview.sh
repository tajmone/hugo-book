#!/bin/bash

# "docs_src/preview.sh"                                    | v0.0.3 | 2019/10/10
# ------------------------------------------------------------------------------
# By Tristano Ajmone, released into the public domain via the Unlicense.
# ------------------------------------------------------------------------------
# This script requires installation of the following applications:
#
#     Asciidoctor (Ruby gem):
#     https://asciidoctor.org
# ------------------------------------------------------------------------------
source=hugo-book.asciidoc
output=preview.html

. ../assets/sh/_print-funcs.sh

printBanner "Hugo Book: HTML Preview"
echo -e "Building a quick HTML preview (\e[93m$output\e[0m):"
echo -e "\e[91m *\e[0m TOC levels: 1."
echo -e "\e[91m *\e[0m Single document."
echo -e "\e[91m *\e[0m Default template."
echo -e "\e[91m *\e[0m No graphics embedding."
echo -e "\e[91m *\e[0m No syntax highlighting."

asciidoctor \
	--verbose \
	--safe-mode unsafe \
	-a experimental \
	-a icons=font \
	-a sectanchors \
	-a toc=left \
	-a toclevels=1 \
	-a reproducible \
	-o  $output \
			$source

# EOF #
