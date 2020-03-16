#include <stdio.h>

#define SIZE 5

int * begin(int * table, int size, int value);

int main()
{	
	// array must be sorted for a binary
	// search to occur
	int data[] = {10, 12, 34, 45, 65};
	int lookup = 21;
    
	int * found = binary(data, SIZE, lookup);
    
	if(found) {
		printf("%d was found\n", *found);
	} else {
		printf("%d was not found\n", lookup);
    }
}

int * binary (int * table, int size, int value)
{	
	int *begin = table, *end = begin + size -1, *mid;

	while(begin <= end) {
		mid = begin + (end - begin) / 2;
		if(*mid > value) {
			end = mid - 1;
        }
		else if(*mid < value) {
			begin = mid + 1;
        }
		else {
			return mid;
        }
	}
	return NULL;
}


