/* asciitable.c - prints ASCII table
 * (c) Copyright 2019 Bartosz Mierzynski
 * Written in ANSI C (C89)
 */

#include <stdio.h>

enum {CTRL_CHARS = 33};

const char *abbr[CTRL_CHARS] = {
	"NUL", "SOH", "STX", "ETX",
	"EOT", "ENQ", "ACK", "BEL",
	"BS", "HT", "LF", "VT",
	"FF", "CR", "SO", "SI",
	"DLE", "DC1", "DC2", "DC3",
	"DC4", "NAK", "SYN", "ETB",
	"CAN", "EM", "SUB", "ESC",
	"FS", "GS", "RS", "US",
	"DEL"
};

void column_format(void) {
	int i, j;
	
	printf(" xx |");
	for(i = 0; i < 0x10; i++)
		printf("  +%X", i);
	putchar('\n');

	for(i = 0; i < 0x10*4+5; i++)
		putchar('-');
	putchar('\n');
	
	for(i = 0; i <= 0x70; i += 0x10) {
		printf(" %02X |", i);
		for(j = 0; j < 0x10; j++)
			if(i < 0x20)
				printf("%4s", abbr[i+j]);
			else
				if(i+j == 0x7F)
					printf("%4s", abbr[CTRL_CHARS-1]);
				else
					printf("%4c", i+j);
		putchar('\n');
	}
}

int main(void) {
	column_format();
	return 0;
}
