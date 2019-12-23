#!/bin/bash

# "docs_src/build.sh"                                      | v0.2.0 | 2019/12/23
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
outDir=../docs

# Highlight Set-up
# ================
# We need to override Highlight default settings and langDefs with our custom
# versions, and make visible any other custom scripts inside ../assets/hl/.
export HIGHLIGHT_DATADIR="$(pwd)/../assets/hl"

. ../assets/sh/_print-funcs.sh


printBanner "Hugo Book: Build HTML Document"
echo -e "\033[37;1mConverting to standalone HTML document (\033[33;1m$outDir/$output\033[0m):"
echo -e "\033[31;1m *\033[0m TOC levels: 1."
echo -e "\033[31;1m *\033[0m Single document."
echo -e "\033[31;1m *\033[0m Graphics embedded via data-URI."
echo -e "\033[31;1m *\033[0m Custom Haml HTML5 templates."
echo -e "\033[31;1m *\033[0m Syntax highlighting via Highlight (no JS dependencies)."

# Get Dependencies Version Info
# =============================
vHighlight=$(highlight --version | grep -o -m1 -E '[0-9]\.[0-9][0-9]')
vAsciidoctor=$(asciidoctor --version | grep -o -m1 -E '[0-9]\.[0-9]+\.[0-9]+')
vRuby=$(ruby --version | grep -o -m1 -E '[0-9]\.[0-9]+\.[0-9]+')

echo -e "\n\033[37;1mUsing:"
echo -e "\033[31;1m *\033[35m Ruby v$vRuby"
echo -e "\033[31;1m *\033[35m Asciidoctor v$vAsciidoctor"
echo -e "\033[31;1m *\033[35m Highlight v$vHighlight"

printSeparator
echo -e "\033[30;1m\c"
asciidoctor \
	--failure-level WARN \
	--timings \
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
	--destination-dir $outDir \
	-o  $output \
		$source || {
			printBuildFailed;
			exit 1;
			}
printBuildPassed
exit

# EOF #
