#include <stdio.h>

#define MAX 10
#define LOOPS 100

void fun(void);

int main()
{
	int i;
    
	for(i = 0; i < LOOPS; i++) {
		fun();
    }
}

void fun()
{
	static int x = 0;
    
	if((x % MAX) == (MAX - 1)) {
		printf("%d\n", x);
	}
	x++;
}
