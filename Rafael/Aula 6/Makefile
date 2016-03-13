CC = gcc
CFLAGS = -Wall
LEX = flex

all:	afd1 afd2 mealy

afd1:	AFD.l
	flex -oAFD.c AFD.l
	gcc -o $@ AFD.c
	rm -f AFD.c

afd2:	AFD-main.c AFD-M.l AFD-M.h
	flex -oAFD-M.c AFD-M.l
	gcc -o $@ AFD-main.c AFD-M.c
	rm -f AFD-M.c

mealy:	MM-main.c MM-mealy.l MM-mealy.h
	flex -oMM-mealy.c MM-mealy.l
	gcc -o $@ MM-main.c MM-mealy.c
	rm -f MM-mealy.c

cleanall:
	rm -f afd1 afd2 mealy

# $@ parte do lado esquerdo do :
# $^ depois dos :
# $< 1º ficheiro das dependencias