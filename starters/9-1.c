//
//  Starter file for Exercise 9-1
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

#include "9-1-list.h"

int main()
{
	PP list, node;
    
	initialize(&list);
    
	node = create("mike", 100);
	list = insert(node, list);
    
	node = create("tom", 200);
	list = insert(node, list);
    
	if (! is_empty(list)) {
		print(list);
    }
}

BOOLEAN is_empty(PP p)
{
	return(p == NULL ? 1 : 0);
}

void initialize(PP *p)
{
	*p = NULL;
}

void print(PP p)
{
	while(p) {
		printf("%-10s %d\n",p -> name, p -> f_number);
		p = p -> link;
	}
}

PP insert(PP data, PP p)
{
	data -> link = p;
	return(data);
}

PP create(char *name, int number)
{
	PP p;
    
	p = (PP) malloc(sizeof(PASS));
	if (p == NULL) {
		printf("malloc: out of memory\n");
		exit(1);
	}
    
	p -> f_number = number;
	strcpy(p -> name, name);
	p -> link = NULL;
	return(p);
}
