#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#include "set.h"

SETP create()
{
	SETP temp;
	temp = (SETP) malloc(sizeof(SET));
	if(temp == NULL) {
		printf("malloc: no more room\n");
		exit(1);
	}
	temp -> howmany = 0;
	return(temp);
}

void add(int new, SETP p)
{
	if( p -> howmany == SIZE ) {
		printf("set overflow\n");
		exit(2);
	}
	p -> array[p -> howmany++] = new;
}

void print(SETP p)
{
	int i;
	for ( i = 0; i < p -> howmany; i++)
		printf("%d ", p -> array[i]);
	printf("\n");
}


SETP setunion(SETP a, SETP b)
{
	SETP c;
	int i, j;
	c = create();
	for ( i = 0; i < a -> howmany; i++)
		add(a -> array[i], c);
	for ( i = 0; i < b -> howmany; i++)  {
		for ( j = 0; j < a -> howmany; j++)
			if(b -> array[i] == a -> array[j])
				break;
		if ( j == a -> howmany)
			add(b -> array[i], c);
	}
	return(c);
}
