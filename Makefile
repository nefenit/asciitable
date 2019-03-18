# (c) Copyright 2019 Bartosz Mierzynski

CC=cc
CFLAGS=-Wall -pedantic -ansi -O2 -g

all:
	@$(CC) $(CFLAGS) asciitable.c -o asciitable

.PHONY: clean
	
clean:
	@rm asciitable
