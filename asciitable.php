#!/usr/bin/env php
<?php
/* asciitable.c - prints ASCII table
 * (c) Copyright 2019 Bartosz Mierzynski
 */

$abbr = array(
	"NUL", "SOH", "STX", "ETX",
	"EOT", "ENQ", "ACK", "BEL",
	"BS", "HT", "LF", "VT",
	"FF", "CR", "SO", "SI",
	"DLE", "DC1", "DC2", "DC3",
	"DC4", "NAK", "SYN", "ETB",
	"CAN", "EM", "SUB", "ESC",
	"FS", "GS", "RS", "US",
	"DEL"
);

function column_format() {

	echo " xx |";
	for($i = 0; $i < 0x10; ++$i) {
		printf( "  +%X", $i);
	}
	echo "\n";

	for($i = 0; $i < 0x10*4+5; ++$i) {
		echo '-';
	}
	echo "\n";
	
	for($i = 0; $i <= 0x70; $i += 0x10) {
		printf(" %02X |", $i);
		for($j = 0; $j < 0x10; ++$j)
			if($i < 0x20)
				printf("%4s", $GLOBALS['abbr'][$i+$j]);
			else
				if($i + $j == 0x7F)
					printf("%4s", $GLOBALS['abbr'][count($GLOBALS['abbr']) - 1]);
				else
					printf("%4s", chr($i+$j));
		echo "\n";
	}
}

column_format();
?>
