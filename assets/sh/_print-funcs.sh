#!/bin/bash

# _print-funcs.sh         v1.3.0 | 2019/05/05 | by Tristano Ajmone, MIT License.
################################################################################
#                                                                              #
#                          ORNAMENTAL PRINT FUNCTIONS                          #
#                                                                              #
################################################################################
# Defines some ornamental functions shared by all scripts, to provide some nice
# color and formatting to text output in a consistent way across scripts.
#
# Formatting functions assume a max-width of 78 columns.
#
# +----------------+--------+-------------------------------------+
# | function name  | params | description                         |
# +----------------+--------+-------------------------------------+
# | printBanner    | text   | Frame text                          |
# | printHeading1  | text   | Frame text                          |
# | printHeading2  | text   | Frame text                          |
# | printHeading3  | text   | Frame text                          |
# | printSeparator |        | Print horizontal ruler              |
# | printErrMsg    |        | Frame text as error message         |
# | printAborting  |        | Print end of script failure message |
# | printFinished  |        | Print end of script success message |
# +----------------+--------+-------------------------------------+


function printBanner {
  # ============================================================================
  # Print the script banner: create a blue frame around the centered text of $1.
  # ----------------------------------------------------------------------------
  # Parameters:
  # - $1: the banner title string.
  # ============================================================================
  printf -v padding "%*s" $(((76 - ${#1})/2))
  centeredText="$padding$1$padding"
  [[ $(( (76 - ${#1}) % 2 )) -ne 0 ]] && centeredText="$centeredText "
  echo -e "\e[94m******************************************************************************"
  echo -e "*                                                                            *"
  echo -e "*\e[93m$centeredText\e[94m*"
  echo -e "*                                                                            *"
  echo -e "******************************************************************************\e[97m"
}

function printHeading1 {
  # ============================================================================
  # Print a yellow frame around centered blue text of $1. Width 78.
  # ----------------------------------------------------------------------------
  # Parameters:
  # - $1: the heading string (title).
  # ============================================================================
  echo -e "\n\e[93m******************************************************************************"
  printf  "\e[94m%*s\n" $(((${#1}+78)/2)) "$1"
  echo -e "\e[93m******************************************************************************\e[97m"
}

function printHeading2 {
  # ============================================================================
  # Print a blue frame around magenta text of $1.
  # ----------------------------------------------------------------------------
  # Parameters:
  # - $1: the heading string (title).
  # ============================================================================
  echo -e "\e[94m=============================================================================="
  echo -e "\e[95m$1"
  echo -e "\e[94m==============================================================================\e[97m"
}

function printHeading3 {
  # ============================================================================
  # Print a magenta frame around blue text of $1.
  # ----------------------------------------------------------------------------
  # Parameters:
  # - $1: the heading string (title).
  # ============================================================================
  echo -e "\e[95m~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
  echo -e "\e[94m$1"
  echo -e "\e[95m~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\e[97m"
}

function printSeparator {
  # ============================================================================
  # Print a dark grey horizontal ruler. Width 78.
  # ============================================================================
  echo -e "\e[90m------------------------------------------------------------------------------\e[97m"
}

function printErrMsg {
  # ============================================================================
  # Print the message of $1 in red, framed and preceded by "** ERROR! **".
  # ============================================================================
  echo -e "\n\e[91m" \
    "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" \
    "** ERROR! ** $1\n" \
    "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\e[0m"
}

function printAborting {
  # ============================================================================
  # Print red message for aborting script failure.
  # ============================================================================
  echo -e "\n\e[91m/// Aborting ... ///\e[0m"
}

function printFinished {
  # ============================================================================
  # Print green message for successful end of script.
  # ============================================================================
  printSeparator
  echo -e "\e[92m/// Finished ///\e[0m"
}

# ------------------------------------------------------------------------------
# The MIT License
#
# Copyright (c) 2019 Tristano Ajmone: <tajmone@gmail.com>
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.
# ------------------------------------------------------------------------------
# EOF #
