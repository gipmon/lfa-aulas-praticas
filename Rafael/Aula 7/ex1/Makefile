CC = gcc
CFLAGS = -Wall
YACC = bison

all:    ex-1 ex-2

ex-1:   ex-1.y
	$(YACC) $^ -o $@.c
	$(CC) -c $(CFLAGS) $@.c -o $@.o
	$(CC) $@.o -o $@
	rm -f $@.c $@.o