#!/usr/bin/python3
'''
asciitable.c - prints ASCII table
(c) Copyright 2019 Bartosz Mierzynski
'''

from sys import exit, stdout

abbr = [
    "NUL", "SOH", "STX", "ETX",
    "EOT", "ENQ", "ACK", "BEL",
    "BS", "HT", "LF", "VT",
    "FF", "CR", "SO", "SI",
    "DLE", "DC1", "DC2", "DC3",
    "DC4", "NAK", "SYN", "ETB",
    "CAN", "EM", "SUB", "ESC",
    "FS", "GS", "RS", "US",
    "DEL"
]

def column_format():
    stdout.write(" xx |");
    for i in range(0x10):
        stdout.write("  +{:X}".format(i))
    stdout.write('\n');

    for i in range(0x10*4+5):
        stdout.write('-');
    stdout.write('\n');
	
    for i in range(0, 0x71, 0x10):
        stdout.write(" {:02X} |".format(i))
        for j in range(0x10):
            if(i < 0x20):
                stdout.write("{0:>4s}".format(abbr[i+j]))
            else:
                if(i + j == 0x7F):
                    stdout.write("{0:>4s}".format(abbr[-1]));
                else:
                    stdout.write("{:4c}".format(i+j))
        stdout.write('\n');

def main():
    column_format()
    return 0

if __name__ == "__main__":
    exit(main())
