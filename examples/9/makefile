all: listmain orderedmain rand circularmain twowaymain 

listmain: listmain.c list.c list.h
	gcc -c list.c
	gcc -o listmain listmain.c list.o

orderedmain: orderedmain.c ordered.c ordered.h
	gcc -c ordered.c
	gcc -o orderedmain orderedmain.c ordered.o

rand: rand.c
	gcc -o rand rand.c

circularmain: circularmain.c circular.c list.h
	gcc -c circular.c
	gcc -o circularmain circularmain.c circular.o

twowaymain: twowaymain.c twoway.c twoway.h
	gcc -c twoway.c
	gcc -o twowaymain twowaymain.c twoway.o

clean: 
	rm *.o listmain orderedmain rand circularmain twowaymain 

