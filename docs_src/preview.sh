#!/bin/bash
# ------------------------------------------------------------------------------
source=hugo_book.asciidoc

echo -e "\n\e[94m###########################"
echo -e "#\e[93m Hugo Book: HTML Preview \e[94m#"
echo -e "###########################\e[0m"
echo -e "Building a quick HTML preview: single doc, default template, no syntax highlighting."

asciidoctor \
  --verbose \
  --safe-mode unsafe \
  -a reproducible \
  $source

# EOF #
