#!/bin/bash

# ====================================
# Create "tokens-list.hug" sample file
# ====================================
# Strip away from "syntax_test_all-tokens.hug" all
# test lines and save output to "tokens-list.hug".

grep -xvE "^ *! *(\^|<).*$" syntax_test_all-tokens.hug > tokens-list.hug

# ===========================================
# Highlight to HTML and test all Hugo sources
# ===========================================
# If any errors occurs, an "errors.log" file will be created.

rm ./errors.log >/dev/null 2>&1
highlight\
	--batch-recursive=*.{hug,h}\
	--validate-input\
	--isolate\
	--encoding=ISO-8859-1\
	--config-file=./langDefs/hugo.lang\
	--config-file=./base16_eighties.theme\
	--font=consolas\
	--font-size=12\
	2>>errors.log && rm ./errors.log >/dev/null 2>&1
