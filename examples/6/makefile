#
#  Makefile for Examples, Chapter 6
#

all: malloc-demo envptr pointer-array print-args funs mainsort surrogatemain

malloc-demo: malloc-demo.c
	gcc -o malloc-demo malloc-demo.c
	
envptr: envptr.c
	gcc -o envptr envptr.c	
	
pointer-array: pointer-array.c
	gcc -o pointer-array pointer-array.c	

print-args: print-args.c
	gcc -o print-args print-args.c
	
funs: funs.c
	gcc -o funs funs.c

mainsort: mainsort.c sort.c sort.h
	gcc -c sort.c
	gcc -o mainsort mainsort.c sort.o

surrogatemain: surrogatemain.c surrogate.c surrogate.h
	gcc -c surrogate.c
	gcc -o surrogatemain surrogatemain.c surrogate.o
	
clean: 
	rm malloc-demo envptr print-args funs pointer-array mainsort surrogatemain surrogate.o
