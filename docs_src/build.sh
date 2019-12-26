#!/bin/bash

# "docs_src/build.sh"                                      | v0.3.0 | 2019/12/26
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

HTML_output=hugo-book.html
HTML_outDir=../docs
HTML_TOCLev=1

ADoc_output=../hugo-book.asciidoc

# Highlight Set-up
# ================
# We need to override Highlight default settings and langDefs with our custom
# versions, and make visible any other custom scripts inside ../assets/hl/.
export HIGHLIGHT_DATADIR="$(pwd)/../assets/hl"

. ../assets/sh/_print-funcs.sh

# Show Build Banner and Info
# ==========================
printBanner "Building The Hugo Book"

# Get Dependencies Version Info
# -----------------------------
vHighlight=$(highlight --version | grep -o -m1 -E '[0-9]\.[0-9][0-9]')
vAsciidoctor=$(asciidoctor --version | grep -o -m1 -E '[0-9]\.[0-9]+\.[0-9]+')
vRuby=$(ruby --version | grep -o -m1 -E '[0-9]\.[0-9]+\.[0-9]+')

echo -e "\n\033[37;1mDependencies version info:"
echo -e "\033[31;1m *\033[35m Ruby v$vRuby"
echo -e "\033[31;1m *\033[35m Asciidoctor v$vAsciidoctor"
echo -e "\033[31;1m *\033[35m Highlight v$vHighlight"

# 1. Build HTML Document
# ======================
printHeading1 "Hugo Book: Build HTML Document"
echo -e "\033[37;1mConverting to standalone HTML document: \033[33;1m$HTML_outDir/$HTML_output\033[0m"
echo -e "\033[31;1m *\033[0m TOC levels: $HTML_TOCLev."
echo -e "\033[31;1m *\033[0m Single document."
echo -e "\033[31;1m *\033[0m Graphics embedded via data-URI."
echo -e "\033[31;1m *\033[0m Custom Haml HTML5 templates."
echo -e "\033[31;1m *\033[0m Syntax highlighting via Highlight (no JS dependencies)."

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
	-a toclevels=$HTML_TOCLev \
	-a reproducible \
	-a docinfo=shared-head \
	-a source-highlighter=highlight \
	--require      ../assets/adoc/highlight-treeprocessor_mod.rb \
	--template-dir ../assets/adoc/haml \
	--destination-dir $HTML_outDir \
	-o  $HTML_output \
		$source || {
			printBuildFailed;
			exit 1;
			}
printBuildPassed

# 2. Build AsciiDoc Preprocessed Document
# =======================================
printHeading1 "Hugo Book: Build Standalone AsciiDoc Document"
echo -e "\033[37;1mPreprocessing to single-file AsciiDoc document: \033[33;1m$ADoc_output\033[0m"

# (pipe coalescer output to SED to strip "// EOF //" lines)
coalescerLog=$(mktemp)
ruby ../assets/adoc/asciidoc-coalescer.rb \
	-a coalescer \
	$source 2> $coalescerLog | sed -e '/^\/\/ EOF \/\/$/d' > $ADoc_output
result=$(<$coalescerLog)
if [ -n "$result" ]
	then # if $result contains any text conversion failed:
		printSeparator
		echo -en "\033[31;1m"
		cat $coalescerLog
		printBuildFailed;
		rm $coalescerLog
		exit 1
fi
printBuildPassed
rm $coalescerLog

# Post-Processing Fixes
# ---------------------
# Restore final "// EOF //" & guarantee empty line for EditorConfig compliance:
echo -e "\n// EOF //" >> $ADoc_output

# If running under Windows OS normalize EOLs to CRLF:
if [[ $(uname -s) == MINGW* ]];then
	unix2dos $ADoc_output
fi

exit

# EOF #
