//
//  Exercise C-5
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct simple {
	int a;
	int b;
};

#define MAXLINE 80

int main()
{
	long distance = sizeof(struct simple);
	FILE *fp;
	char fname[MAXLINE];
	char number[MAXLINE];
	struct simple x;
	int n, recs;
    
	printf("Enter filename: ");
    fgets(fname, MAXLINE, stdin);
    fname[strlen(fname) - 1] = '\0';    //  Strip off newline
  
	fp = fopen(fname, "rb");
	if (fp == NULL) {
		printf("Can't open %s\n", fname);
		exit(1);
	}
    
	printf("Enter record number: ");
	n = atoi(fgets(number, MAXLINE, stdin));
    
	fseek(fp, 0L, 2);    //  Seek to end of file
    
	recs = ftell(fp) / sizeof(struct simple);
	printf("No. of records = %d\n", recs);
    
	if (n > recs) {
		printf("Sorry, %d is too big\n", n);
		exit(2);
	}
    
	distance = distance *  n * -1;
	fseek(fp, distance, 2);
    
	while(fread(&x, sizeof(struct simple), 1, fp) > 0) {
		printf("%d %d\n", x.a, x.b);
    }
}
