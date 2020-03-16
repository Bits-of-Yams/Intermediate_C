all: demo quicksort prog1 prog2 varargs static

demo: demo.c
#  Supress warning because we intentionally left out 
#  the include for stdlib.h, so that there would be 
#  no function prototype for atof.
#  But we still want to have a clean make, of course!

	gcc -o demo -Wno-implicit-function-declaration demo.c
	
quicksort: quicksort.c
	gcc -o quicksort quicksort.c
	
prog1: prog1.c
	gcc -o prog1 prog1.c

prog2: prog2.c
	gcc -o prog2 prog2.c

varargs: varargs.c
	gcc -o varargs varargs.c

static: static.c
	gcc -o static static.c

clean: 
	rm demo quicksort prog1 prog2 varargs static



				
