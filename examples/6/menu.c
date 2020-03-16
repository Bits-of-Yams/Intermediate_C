#include <stdio.h>
#include <stdlib.h>

#define MAX 100

double pow(double, double);
double add (double, double);
double mult(double, double);

struct commands {
	char *name;
	double (*pf)();
} c[] = { "add", add, "mult", mult, "power", pow };

#define SIZE sizeof(c)/ sizeof(struct commands)

main( )
{
	char line[MAX];
	double a,b, ans;
	int i;
	
	while(1) {
		printf("enter a command:\n");
		printf("add\nmult\npower\nquit\n => ");
		gets(line);
		if(strcmp(line,"quit") == 0)
			break;
		for (i = 0; i < SIZE; i++)
			if(strcmp(c[i].name,line) == 0) {
				printf("input first number ");
				a = atof(gets(line));
				printf("You entered %f %s\n", a, line);
				printf("input second number ");
				b = atof(gets(line));
				ans = c[i].pf(a,b);
				printf("ans is %f\n", ans);
				break;
		}
		if( i == SIZE )
			printf("%s not implemented\n",line);
		printf("press return to continue\n");
		gets(line);
		system("clear") && system("cls") ;
	}
}

double pow(double a, double b)
{
	int i;
	double temp = a;
	for(i = 0; i < b - 1; i ++)
		temp *= a;
	return temp;
} 

double add (double a, double b)
{
	return a + b;
}
	
double mult(double a, double b)
{
	return a * b;
}

