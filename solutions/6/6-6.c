//
//   Exercise 6-6
//

#include <stdio.h>

int add(int, int);
int mult(int, int);
int (*fun(int))(int, int);

int main()
{
	int x;
	int (*p)();		// A FUNCTION POINTER

	p = fun(1);		// 'fun' RETURNS A POINTER
	x = (*p)(5,10);		// INVOKE THE FUNCTION
	printf("%d\n", x);	//	RETURNED BY 'fun'
	p = fun(2);
	x = (*p)(5,10);
	printf("%d\n", x);
}

int (*fun(int which))()	//	VERY MESY
{
	int (*param)();
	param = add;
	if(which != 1)
	param = mult;
	return(param);
}

int add(int a, int b)
{
	return( a + b );
}

int mult(int a, int b)
{
	return( a * b);
}
