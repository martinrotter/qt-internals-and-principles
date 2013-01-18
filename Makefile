all: start guide finish

start:
	echo "Makefile has started its work."

guide:	qt-internals-and-principles.tex
	pdflatex qt-internals-and-principles
	pdflatex qt-internals-and-principles
	makeindex qt-internals-and-principles.idx -s index.ist
	makeglossaries qt-internals-and-principles
	bibtex qt-internals-and-principles
	pdflatex qt-internals-and-principles
	pdflatex qt-internals-and-principles

finish:
	echo "Makefile has finished its work."

clean:
	rm -f *.lo* *.aux *.ind *.idx *.ilg *.toc
