#include <stdio.h>
#include <malloc.h>

int main()
{	
	int *iPtr;
	void *ptr = malloc(10);
    
	iPtr = ptr;
	*iPtr = 10;
	printf("%d\n", *iPtr);
	
	printf("The size of what iPtr is pointing to... %ld\n", sizeof(*iPtr));
	printf("The size of what ptr is pointing to... %ld\n", sizeof(*ptr));
}
