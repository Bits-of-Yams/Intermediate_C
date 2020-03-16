#include <stdio.h>

#define MAX 3
#define SIZE 10

int cube(int);
int square(int);
int times2(int);

int getvalues(int * data, int size);
void print(int * data, int size);
void compute(int * data, int size, int (*ptf)(int));

int main( )
{
	int j, numValues;
	int (*p[MAX])();
	int x[SIZE];
	p[0] = cube;
	p[1] = square;
	p[2] = times2;
	
	for (j = 0; j < MAX; j++) {
		numValues = getvalues(x, SIZE);		// FILL x
		printf("\n");
		print(x, numValues);			    // PRINT x BEFORE
		compute(x, numValues, p[j]);		// COMPUTE on x
		print(x, numValues);			    // PRINT x AFTER
	}
}

int cube(int x)
{	
	return x * x * x;
}

int square(int x)
{
	return x * x;
}

int times2(int x)
{
	return 2 * x;
}

int getvalues(int * data, int size)
{
	int i;
	for(i = 0; i < size; i++)
		data[i] = i + 1;
	return i;
}

void print(int * data, int size)
{
	int i;
	for(i = 0; i < size; i++)
		printf("%d ", data[i]);
	printf("\n");	
}

void compute(int * data, int size, int(*ptf)(int))
{
	int i;
	for(i = 0; i < size; i++)
		data[i] = ptf(data[i]);
}
