#
#  Makefile for Solutions, Chapter 2
#

all: 2-1 2-2 2-3



display.o: display.c common.h
	gcc -c display.c

fill.o: fill.c common.h
	gcc -c fill.c

largest.o: largest.c common.h
	gcc -c largest.c

2-1: 2-1.c common.h display.o fill.o largest.o
	gcc -o 2-1 2-1.c display.o fill.o largest.o



getandput.o: getandput.c
	gcc -c getandput.c

2-2: 2-2.c getandput.o
	gcc -o 2-2 2-2.c getandput.o

2-3: 2-3.c getandput.o
	gcc -o 2-3 2-3.c getandput.o

clean: 
	rm 2-1 2-2 2-3 *.o
