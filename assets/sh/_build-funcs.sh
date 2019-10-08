#!/bin/bash
# ------------------------------------------------------------------------------
# Various build functions and helpers shared by all subprojects.
# By Tristano Ajmone, MIT License.
# ------------------------------------------------------------------------------

function normalizeEOL {
  # ============================================================================
  # if OS is Windows normalize EOL to CRLF (because sed uses LF)
  # ----------------------------------------------------------------------------
  # Parameters:
  # - $1: the file to normalize.
  # ============================================================================
  if [[ $(uname -s) == MINGW* ]];then
    echo -e "\e[90mUNIX2DOS: \e[94m$1"
    unix2dos -q $1
  fi
}

# EOF #
