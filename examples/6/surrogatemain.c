#include "surrogate.h"

#define NUM 100

int main( )  {
    PR record_pointers[NUM];
	int number;

    number = get_the_data(record_pointers, NUM);
    
	if(number > 0) {
	    sort(record_pointers, number);
		print(record_pointers, number);
	}
}

