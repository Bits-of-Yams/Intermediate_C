//
//  Starter file for Exercise 4-2
//

#include <stdio.h>

#define SIZE 5

int ispal(unsigned int p);

int main()
{
	int i;
	char line[100];
	unsigned int value;
	
	//
	//	SOME TEST VALUES
	//
	//			               YES    YES  YES   NO    YES
	unsigned int a[SIZE] = { 0177777, 01700, 0,  034, 053152 };
	for (i = 0; i < SIZE; i++) {
		value = a[i];
		if( ispal(value) ) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
}
int ispal(unsigned int p)
{
//
//	YOU WRITE THIS PART
//
}
