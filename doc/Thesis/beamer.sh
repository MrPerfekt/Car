#!/bin/sh

#
#deprecated
#

name=${1%.tex}
texFile="$name.tex"
dviFile="$name.dvi"
psFile="$name.ps"

echo "$texFile" | latex &&
dvips "$dviFile" &&
ps2pdf "$psFile" &&
echo Successful &&
exit 0
exit 1
