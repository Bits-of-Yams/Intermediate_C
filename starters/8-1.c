//
//  Starter file for Exercise 8-1
//

#include <stdio.h>
#include <stdlib.h>

#include "8-1-fraction.h"


int main()
{
    //  You write the main function
}

FRACTION init(int num, int denom)
{
	FRACTION temp;
    
	temp.n = num;
	temp.d = denom;
	return(temp);
}

FRACTION input(void)
{
	char line[16];
	FRACTION temp;
    
	printf("Enter the numerator: ");
	temp.n = atoi(fgets(line, 16, stdin));
    
	printf("Enter the denominator: ");
	temp.d = atoi(fgets(line, 16, stdin));
    
	return(temp);
}

void print(FPTR t)   // recall FPTR is a fraction pointer
{
    printf("%d/%d\n", t -> n, t -> d);
}
