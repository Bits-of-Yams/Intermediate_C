//
//  checkers.c
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HOW_MANY_RANDOMS 10
#define N 64
#define BPW 8
#define ELEMENTS (N/BPW)

void binary_print(unsigned char);

int main()
{
	unsigned char occupied[ELEMENTS];
	int i, number, row, bit;
    
	for(i = 0; i < ELEMENTS; i++) {
		number = rand() % N;
		row = number / BPW;
		bit = number % BPW;
		occupied[row] |= 1 << bit;
	}
    
	for(i = 0; i < ELEMENTS; i++) {
		binary_print(occupied[i]);
    }
}

void binary_print(unsigned char element)
{
	int i;
	char output[BPW + 1];
    
	strcpy(output, "\0");
	unsigned mask = 1;
	for(i = 0; i < BPW; i++){
		if(element & mask) {
			output[BPW - 1 - i] = '1';
		} else {
			output[BPW - 1 - i] = '0';
        }
		mask <<= 1;
	}
	output[i] = '\0';
	printf("%s\n", output);
}
