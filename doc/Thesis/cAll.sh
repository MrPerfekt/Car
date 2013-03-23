#!/bin/sh

compileFull(){
	name="${1%.tex}"
	echo ""
	echo "====== $name ======"
	echo ""
	texFile="$name.tex"
	auxFile="$name.aux"
	echo "$name.tex" | pdflatex
	bibtex "$auxFile"
	echo "$name.tex" | pdflatex
}

# ./cpdflatex.sh pathCalculationPaper
# ./cpdflatex.sh environmentPaper
# ./cpdflatex.sh sensorsPaper
# ./cpdflatex.sh thesis
# ./cpdflatex.sh presentation

compileFull pathCalculationPaper
compileFull environmentPaper
compileFull sensorsPaper
compileFull thesis
compileFull presentation

#./clean.sh
