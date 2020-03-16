#include <stdio.h>

#define STRING_SIZE 100

int main()
{	
	char string[STRING_SIZE];
	double x;

	fgets(string, STRING_SIZE, stdin);
	x = atof(string);
	printf("%f\n", x);
}
