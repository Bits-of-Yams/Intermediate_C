#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"

void initialize(PP * p)
{
	*p = NULL;
}

BOOLEAN is_empty(PP p)
{
	return( p == NULL );
}

void print(PP p)
{
	while (p != NULL) {
		printf("%s %d\n", p ->name, p ->f_number);
		p = p -> link;
	}
}
PP create(char *name, int number)
{
	PP p;
	p = (PP) malloc(sizeof(PASS));
	if( p == NULL ){
		printf("malloc: no more room\n");
		return(NULL);
	}
	p -> f_number = number;
	strcpy(p -> name, name);
	p -> link = NULL;
	//			FOR TWO WAY LINKED LISTS
	//	p -> blink = NULL;	LATER
	//					IN THE CHAPTER
	return(p);
}

PP insert(PP data, PP p)
{
	data -> link = p;
	return(data);
}

PP append(PP data, PP p)
{
	PP temp = p;
	PP prev;
	if(is_empty(p)) {
		p = insert(data, p);
		return(p);
	}
	while(p != NULL) {
		prev = p;
		p = p -> link;
	}
	//    prev POINTS TO LAST ELEMENT
	prev -> link = data;
	return(temp);
}

