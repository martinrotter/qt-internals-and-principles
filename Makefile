all: start guide finish

start:
	echo "Makefile has started its work."

guide:	qt-internals-and-principles.tex
	pdflatex qt-internals-and-principles
	pdflatex qt-internals-and-principles
	makeindex qt-internals-and-principles.idx
	makeglossaries qt-internals-and-principles
	biber qt-internals-and-principles
	pdflatex qt-internals-and-principles
	pdflatex qt-internals-and-principles

finish:
	echo "Makefile has finished its work."

clean:
	rm -f *.lo* *.aux *.ind *.idx *.ilg *.toc
