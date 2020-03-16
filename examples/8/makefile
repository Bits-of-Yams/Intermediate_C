all: mainfrac mainset

mainfrac: mainfrac.c fraction.c fraction.h
	gcc -c fraction.c
	gcc -o mainfrac mainfrac.c fraction.o

mainset: mainset.c set.c set.h
	gcc -c set.c
	gcc -o mainset mainset.c set.o

clean: 
	rm *.o mainfrac mainset