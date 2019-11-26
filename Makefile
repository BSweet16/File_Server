# Makefile for Project5
CC=gcc
CFLAGS=-I.
DEPS = csapp.h fileserver.h
OBJ = filed.c csapp.c fileserver.c

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

filed: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)