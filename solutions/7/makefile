#
#  Makefile for Solutions, Chapter 7
#

all: 7-1.o 7-2.o 7-3

7-1.o: 7-1.c employee.h
	gcc -c 7-1.c

7-2.o: 7-2.c employee.h
	gcc -c 7-2.c

7-3: 7-3.c
	gcc -o 7-3 7-3.c

clean: 
	rm *.o 7-3
