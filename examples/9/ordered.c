#include <stdio.h>
#include <string.h>
#include <malloc.h>

#include "ordered.h"

void initialize(PP *p)
{
	*p = NULL;
}

BOOLEAN is_empty(PP p)
{
	return( p == NULL ? 1 : 0 );
}

void print(PP p)
{
	while (p != NULL) {
		printf("%s %d\n", p -> name, p -> f_number);
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
	return(p);
}

PP order(PP data, PP p)
{
	PP prev;
	PP save = p;
	if(is_empty(p) || (strcmp(data -> name, p -> name) < 0 ))  {
		data -> link = p;
		return(data);
	}
	while((p != NULL) && (strcmp(data -> name, p -> name) > 0)){
		prev = p;
		p = p -> link;
	}
	data -> link = prev -> link;
	prev -> link = data;
	return(save);
}
