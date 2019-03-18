# (c) Copyright 2019 Bartosz Mierzynski

CC=cc
CFLAGS=-Wall -pedantic -ansi -O2

all:
	@$(CC) $(CFLAGS) asciitable.c -o asciitable
	
clean:
	@rm asciitable
