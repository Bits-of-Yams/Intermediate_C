#include <stdio.h>
#include <stdarg.h>

// PROTOTYPE FOR sum
// NOTE THE ...
int sum(int n, ...);

int main()
{
	printf("%d\n", sum(3, 7, -2, 4));
	printf("%d\n", sum(5, 1, 2, 3, 4, 5));
}

int sum(int n, ...)	//ARGS HAVE NO NAMES
{
	va_list arg;	//arg REFERS TO EACH
			        //ARG IN TURN
	int i, s;
    
	va_start(arg, n);	//arg POINTS TO FIRST ARG
    
	for(i = s = 0; i < n; i++) {
		s += va_arg(arg, int); 	//RETURN NEXT ARG
    }
    
	va_end(arg);			//CLEANUP
	return s;
}
