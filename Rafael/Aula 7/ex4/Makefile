CC = gcc
CFLAGS = -Wall
YACC = bison

ALL = ex-4	ex-4_2

all:    $(ALL)

$(ALL):   %:	%.y
	$(YACC) $^ -o $@.c
	$(CC) -c $(CFLAGS) $@.c -o $@.o
	$(CC) $@.o -o $@
	rm -f $@.c $@.o