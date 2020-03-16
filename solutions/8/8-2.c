//
//  Exercise 8-2
//
#include <stdio.h>

struct complex {
	double real;
	double imag;
};

typedef struct complex COMPLEX, *PC;

COMPLEX init(double, double);
void print(COMPLEX);
COMPLEX add(COMPLEX, COMPLEX);

int main()
{
	COMPLEX a, b ,c;
    
	a = init(3.0, 5.5);
	b = init(-2.0, 4.5);
	print(a);
	print(b);
	c = add(a,b);
	print(c);
}

COMPLEX init(double r, double i)
{
	COMPLEX temp;
    
	temp.real = r;
	temp.imag = i;
	return(temp);
}

void print(COMPLEX t)
{
	printf("%.2f + %.2fi\n", t.real, t.imag);
}

COMPLEX add(COMPLEX x, COMPLEX y)
{
	COMPLEX temp;
    
	temp.real = x.real + y.real;
	temp.imag = x.imag + y.imag;
	return(temp);
}
