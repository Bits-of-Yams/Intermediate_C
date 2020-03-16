//
//  Exercise 4-2
//
//	SOLUTION COULD BE EMBELLISHED BY
//	1) CHECKING INPUT NUMBER AGAINST WORDSIZE LIMIT
//	2) PRINTING OUTPUT IN BINARY RATHER THAN OCTAL
//	 	

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINESIZE 100

int main()
{
	unsigned string = 0;
	int num;
	char input[LINESIZE], bitno[LINESIZE];

	printf("Enter the action ('on', 'off', or 'quit'): ");
	while (fgets(input, LINESIZE, stdin) != NULL) {
        
        input[strlen(input) - 1] = '\0';    // strip off newline
        
		if (strcmp(input, "quit") == 0) {
			break;
        }
		else if (strcmp(input, "on") == 0) {
			printf("bit number: ");
			fgets(bitno, LINESIZE, stdin);
			num = atoi(bitno);
			string = string | (1 << num - 1);
		}
		else if (strcmp(input, "off") == 0) {
			printf("bit number: ");
			fgets(bitno, LINESIZE, stdin);
			num = atoi(bitno);
			string = string &~ (1 << num - 1);
		}
		else {
			printf("illegal string: %s\n", input);
        }

		printf("%o\n", string);
		printf("Enter the action ('on', 'off', or 'quit'): ");
	}
}
