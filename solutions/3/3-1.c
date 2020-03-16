//
//  Exercise 3-1
//
#include <stdio.h>

int add(int x, int y);

int main()
{
	int a = 5;
	int b = 6;
	
	printf("%d\n", add(a, b));
}

int add(int x, int y)
{
	if (x == 0) {
		return(y);
	} else {
		return(add(x - 1, y + 1));
	}
}
