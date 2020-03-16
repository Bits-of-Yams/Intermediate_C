#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "sort.h"

void printlines(char **ptrs, int lines)
{
	while(--lines >= 0)
     	printf("%s\n",*ptrs++);
}

void sort(char **p, int lines, int (*f)(const char*, const char*))
{
     int i, j;
     char *pc;
     for(i = 0;  i < lines - 1; i++)
        for(j = i + 1; j < lines; j++)
        	if( f(p[i],p[j]) > 0 )
        		 pc = p[i], p[i] = p[j], p[j] = pc;
}

int numcmp(const char *s, const char *t) { return(atof(s) - atof(t)); }
int revnum(const char *s, const char *t) { return(atof(t) - atof(s)); }
int revcmp(const char *s, const char *t) { return(strcmp(t,s));       }
