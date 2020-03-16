//
//   Exercise 5-2
//

#include <stdio.h>


void sort3(int *ptr1, int *ptr2, int *ptr3);
void sort2(int *ptra, int *ptrb); 

int main() 
{
    int a = 7, b = 2, c = 4;

    sort3(&a, &b, &c);
    printf("After: a = %d, b = %d, c = %d\n", a, b, c);
}

void sort3(int *ptr1, int *ptr2, int *ptr3)
{
	sort2(ptr1, ptr2);
	sort2(ptr2, ptr3);
	sort2(ptr1, ptr2);
}

void sort2(int *ptra, int *ptrb) 
{
	int temp;
	
	if (*ptra > *ptrb) {  // Swap if in wrong order
		temp = *ptra;
		*ptra = *ptrb;
		*ptrb = temp;
	}
}	
