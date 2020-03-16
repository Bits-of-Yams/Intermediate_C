#include <stdio.h>
#include <assert.h>
#include "fraction.h"

FRACTION input()
{
	FRACTION p;
 	printf("input num then denom (n/d) ");
	//	"%d/%d"  format => allows input of the
	//	of the form	n/d

	scanf("%d/%d", &p.n, &p.d);
	while( getchar() != '\n');			 // flush the newline away
	return(p);
}

FRACTION create(int numerator, int denominator)
{
	FRACTION p;
	p.n = numerator;
	p.d = denominator;
	return(p);
}

void print(FPTR p)
{
	int temp;
	
	assert(p -> d != 0 );		// div by 0
	temp = gcd(p->n, p->d);		// reduce
	assert(temp != 0);		    // sanity check
	
	p -> n = p -> n / temp;
	p -> d = p -> d / temp;
	if ( 1 == p -> d)			    // easy reading
		printf("%d\n", p -> n);
	else if ( 0 == p -> n)   		// easy reading
		printf("0\n");
	else
		printf("%d/%d\n", p -> n, p -> d);
}

FRACTION add(FPTR f, FPTR s)
{
	FRACTION p;
	p.n = f -> n * s -> d   +   f -> d * s -> n;
	p.d = f -> d * s -> d;
	return(p);
}

int gcd(int top, int bot)
{
	int quot, rem;
	quot = top / bot;
	rem = top % bot;
	while(rem != 0)
	{
		top = bot;
		bot = rem;
		quot = top / bot;
		rem = top % bot;
	}
	return bot;
}
