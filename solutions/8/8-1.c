//
//  Exercise 8-1
//
#include <stdio.h>
#include <malloc.h>
#include <assert.h>

struct fraction {
	int n;
	int d;
};

typedef struct fraction FRACTION, *FPTR;

FRACTION create(int numerator, int denominator);
FRACTION input(void);
void print(FPTR);
int gcd(int first_dividend, int second_dividend);
FPTR add(FPTR, FPTR);
FRACTION mult(FPTR, FPTR);
FRACTION divide(FPTR, FPTR);
FRACTION subtract(FPTR, FPTR);

FPTR add(FPTR f, FPTR s)
{
	FPTR p;
	p = (FPTR)malloc(sizeof(FRACTION));
	assert( p != NULL);
	p -> n = f -> n * s -> d + f -> d * s -> n;
	p -> d = f -> d * s -> d;
	return(p);
}
