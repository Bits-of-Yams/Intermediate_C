#include <stdio.h>
#define SIZE 5

void quick(int*, int, int);
void swap(int*a, int* b);
void print(int* data, int size);

int main()
{
	int a[SIZE] = {34, 2, -1, -5, 12};
	print(a, SIZE);
	quick(a, 0, SIZE - 1);
	print(a, SIZE);
}

void quick(int * p, int low, int high)
{
	printf("PIVOT IS %d AT LOW %d HIGH %d\n", p[low], low, high);
	if(low < high) {
		int lo = low;
		int hi = high + 1;
		int elem = p[low];
		for (;;) {
			while(p[++lo] < elem && lo < hi)
				;
			while(p[--hi] > elem && high >= lo)
				;
			if(lo < hi)
				swap(&p[lo], &p[hi]);
			else
				break;
		}
		swap(&p[low], &p[hi]);
		quick(p, low, hi - 1);
		quick(p, hi + 1, high);
	}
}

void swap(int*a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void print(int* data, int size)
{
	int i;
	for(i = 0; i < size; i++)
		printf ("%d ", data[i]);
	printf("\n");
}
