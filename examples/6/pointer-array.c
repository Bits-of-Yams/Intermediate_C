//
//  pointer-array.c
//

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

#define MAX 100   	// number of lines 
#define LENGTH 80   // line length     

int main()	
{
	char line[LENGTH + 1];
	char *ptrs[MAX];	
	int len, i = 0, j;
	
	while (fgets(line, LENGTH, stdin) != NULL) {
		if (i == MAX) {
			fprintf(stderr, "Sorry, array full\n");
			break;
		}
	 
		len = strlen(line);
		line[len - 1] = '\0';		// strip off newline
		len--;
		
		ptrs[i] = malloc(len + 1);
		if (ptrs[i] == NULL) {
			fprintf(stderr, "Out of memory\n");
			exit(1);
		}
		
		strcpy(ptrs[i++], line);
	}
	
	for (j = 0; j < i; ++j) {
		printf("%s\n", ptrs[j]);
	}
	
	for (j = 0; j < i; ++j) {	// deallocate memory
		free (ptrs[j]);
	}
}
