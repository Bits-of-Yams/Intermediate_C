// 
//  Exercise 9-1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAMESIZE 20

struct passenger {
    char name[NAMESIZE];
    int flight_number;
    struct passenger *link;
};

typedef struct passenger PASS, *PP;
typedef int BOOLEAN;

void initialize(PP *);   //   INITIALIZE THE LIST
BOOLEAN is_empty(PP);    //   IS THE LIST EMPTY?
PP insert(PP, PP);       //   ADD TO FRONT OF LIST
PP append(PP, PP);       //   ADD TO END OF LIST
PP create(char *, int);  //   CREATE AND FILL ELEMENT
void print(PP);          //   PRINT THE LIST

void swap(char * ffirst, char *second, PP head)
{
	char temp[100];
	int t;
	PP f, s;
	f = s = head;
	while(f != NULL) {
		if(strcmp(f -> name,ffirst) == 0)
			break;
		else
			f = f -> link;
	}
	if ( f == NULL ) {
		printf("didn't find %s\n", ffirst);
		return;
	}
	while(s != NULL) {
		if(strcmp(s -> name, second) == 0)
			break;
		else
			s = s -> link;
	}
	if ( s == NULL ) {
		printf("didn't find %s\n", second);
		return;
	}
	//
	//	BETTER (AND HARDER ) TO MOVE POINTERS
	//	(4 OF THEM) HERE THAN TO SWAP THE DATA
	//
	strcpy(temp, f -> name);
	strcpy(f -> name, s -> name);
	strcpy(s -> name, temp);
	t = f -> flight_number;
	f -> flight_number = s -> flight_number;
	s -> flight_number = t;
}
