# (c) Copyright 2019 Bartosz Mierzynski

CC=cc
CFLAGS=-Wall -pedantic -ansi

all:
	@$(CC) $(CFLAGS) asciitable.c -o asciitable
	
clean:
	@rm asciitable
