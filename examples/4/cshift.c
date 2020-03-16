#include <stdio.h>

unsigned int rcshift(unsigned int, unsigned int);
unsigned int lcshift(unsigned int, int);
int wordlength(void);

int main()
{
	unsigned int n = 0777;
	unsigned int num = 1;
    
	printf("%d\n", wordlength());
	printf("BEFORE: %o\n", n);
	n = rcshift(n, num);
	printf("AFTER RIGHT: %o\n", n);
//	n = lcshift(n, num);
//	printf("AFTER LEFT: %o\n", n);
}

unsigned int rcshift(unsigned int number, unsigned int howmany)
{
	int i; 
	unsigned int mask = ~0;
    
	mask = mask >>1;
	mask = ~mask;
    
	for (i = 0; i < howmany; i++) {
		if (number & 01) {
			number = (number >>1)|mask;
		} else {
			number >>= 1;
        }
	}
	return (number);
}

unsigned int lcshift(unsigned int number, int howmany) {
	unsigned int r;
    
	r = rcshift(number, wordlength() - howmany);
	return (r);
}

int wordlength(void) {
	unsigned int x = ~0;
	int count = 0;
    
	while(x != 0) {
		count++;
		x >>= 1;
	}
	return count;
}

