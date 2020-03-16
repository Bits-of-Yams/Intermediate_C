//
//  Starter file for Exercise 8-1
//

struct fraction {
	int n;
	int d;
};

typedef struct fraction FRACTION, *FPTR;

FRACTION create(int numerator, int denominator);
FRACTION input(void);
void print(FPTR);
int gcd(int first_dividend, int second_dividend);
FRACTION add(FPTR, FPTR);
FRACTION mult(FPTR, FPTR);
FRACTION divide(FPTR, FPTR);
FRACTION subtract(FPTR, FPTR);
          
