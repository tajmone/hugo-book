#!/bin/bash
# ------------------------------------------------------------------------------
source=hugo_book.asciidoc

echo -e "\n\e[94m###########################"
echo -e "#\e[93m Hugo Book: HTML Preview \e[94m#"
echo -e "###########################\e[0m"
echo -e "Building a quick HTML preview:"
echo -e "\e[91m *\e[0m TOC levels: 1."
echo -e "\e[91m *\e[0m Single document."
echo -e "\e[91m *\e[0m Default template."
echo -e "\e[91m *\e[0m No syntax highlighting."

asciidoctor \
  --verbose \
  --safe-mode unsafe \
  -a toclevels=1 \
  -a reproducible \
  $source

# EOF #
