CC = gcc
CFLAGS = -Wall

all:	mealy

mealy:	main.c mealy.c
	$(CC) $(CFLAGS) -o $@ $^

mealy.o:	mealy.h

cleanall:
	rm -f mealy
