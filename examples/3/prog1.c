#include <stdio.h>

int add(int a, int b)
{
	return a + b;
}

int main()
{
	int i = 5, j = 5, x, y;

	x = add(i, i++);
	y = add(j++, j);

	printf("%d %d\n", x, y);
}



