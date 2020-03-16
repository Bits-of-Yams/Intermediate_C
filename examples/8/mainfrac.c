//
//  mainfrac.c
//
#include <stdio.h>
#include "fraction.h"

#define MAX 5

int main()
{
	int i;
	FRACTION array[MAX];
	FRACTION s;

	s = create(0, 1);

	printf("Enter %d fractions\n", MAX);
	for (i = 0; i < MAX; i++) {
		printf("input fraction # %d ", i + 1);
		array[i] = input();
	}

	for ( i = 0; i < MAX; i++) {
		s = add(&s, &array[i]);
    }

	print(&s);
}
