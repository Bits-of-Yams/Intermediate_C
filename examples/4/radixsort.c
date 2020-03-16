#include <stdio.h>

#define SIZE 15

int wordlength(void);
void radix(int *v, int size);
void print(int * array, int size);

int main()
{
	int data[]= {46,30,82,90,56,17,95,15,48,26,4,58,71,79,92};
	
	printf("ORIGINAL:\n");
	print(data, SIZE);
	radix(data, SIZE);
	printf("SORTED:\n");
	print(data, SIZE);
}

void radix(int *v, int size)
{
	int temp[SIZE], t_index, v_index, i, k = 0;
	unsigned mask;
	int wordsize = wordlength() - 1;
	// LOOP(WORDSIZE -1) TIMES
	while (k < wordsize)
	{
		t_index = v_index = 0;
        
		// mask for bit manipulation
		mask = 1 << k;
        
		// separate into v and temp
		for ( i = 0; i < size; i++) {
			if ((v[i] & mask) == 0) {
				v[v_index++] = v[i];
			} else {
				temp[t_index++] = v[i];
            }
		}
		//combine
		for(i = 0; i < t_index; i ++) {
			v[v_index++] = temp[i];
        }
		// just for aid in displaying the output

		
		//print(v, SIZE);
		k++;
	}
}

void print(int * array, int size)
{
	int i;
    
	for(i = 0; i < size; i++) {
		printf("%d ", array[i]);
    }
	printf("\n");
}

int wordlength(void)
{
	unsigned int x = ~0;
	int count = 0;
    
	while(x != 0) {
		count++;
		x >>= 1;
	}
	return count;
}
