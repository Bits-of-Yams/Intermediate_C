#
#  Makefile for Examples, Chapter 2 
#

all: starter prog

starter: starter.c
	gcc -o starter starter.c

fun1.o: fun1.c
	gcc -c fun1.c

fun2.o: fun2.c
	gcc -c fun2.c

prog: prog.c fun1.o fun2.o
	gcc -o prog prog.c fun1.o fun2.o

clean: 
	rm starter prog *.o

