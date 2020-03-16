#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

#include "sort.h"

int main(int argc,char **argv)  {
	char *ptrs[NO_LINES];
	int i, lines;

	if(argc != 2) {
		printf("usage: sort -n numerical\n");
		printf("       sort -a alphabetical\n");
       		printf("       sort -r reverse alpha\n");
		printf("       sort -rn reverse numeric\n");
       		exit(3);
	}

	if((lines = readlines(ptrs,NO_LINES)) == ERROR) {
       		printf("too many lines or no room\n");
		exit(1);
	}

	if(strcmp(argv[1], "-n") == 0)
		sort(ptrs, lines, numcmp);
	else if(strcmp(argv[1], "-a") == 0)
		sort(ptrs, lines, strcmp);
	else if(strcmp(argv[1], "-r") == 0)
       	sort(ptrs, lines, revcmp);
	else if(strcmp(argv[1], "-rn") == 0)
       	sort(ptrs, lines, revnum);
	else {
	   	printf("incorrect argument\n");
       	exit(4);
	}
	printlines(ptrs, lines);

	for (i = 0; i < lines; i++) {
		free(ptrs[i]);
	}		
}

int readlines(char **p,int limit)  {
	int n = 0;
	char *pc, line[LINE_LENGTH];

	while(fgets(line, LINE_LENGTH, stdin) != NULL) {
     	if(n > limit) {
     		return(ERROR);
        } else if((pc = malloc(strlen(line) + 1)) == NULL) {
        	return(ERROR);
        } else {    
			strcpy(pc,line); 
			p[n++] = pc; 
		}
	}
	return(n);
}
