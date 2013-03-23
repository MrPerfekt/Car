#!/bin/sh
name=${1%.tex}
path="$name.tex"

echo $name.tex | pdflatex &&
echo Successful &&
exit 0
exit 1
