# Makefile

CC := gcc
CFLAGS := -Wall -Wextra -std=c11

.PHONY: all clean

all: e1 e2

e1: e1.c
	$(CC) $(CFLAGS) $< -o $@

e2: e2.o glist.o
	$(CC) $(CFLAGS) $^ -o $@

e2.o: e2.c glist.h
	$(CC) $(CFLAGS) -c $< -o $@

glist.o: glist.c glist.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o e1 e2