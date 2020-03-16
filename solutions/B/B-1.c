//
//  Exercise B-1
//

#include <stdio.h>
#include <string.h>

#define GOOD_FORM 1

int verify(char *);

int main()
{
	char *digits = "0123456789";
	char line[100];
	char *pc;

	while (fgets(line, 100, stdin) != NULL) {
		if (verify(line) == GOOD_FORM) {
			printf("%s IS FINE \n", line);
        }
	}
}

int verify(char *s)
{
	int len1, len2;
	char *pc;
	char *digits = "0123456789";

	pc = strchr(s,'.');

	if(pc == NULL) {
		printf("%s: no decimal point\n",s);
		return(-1);
	}

	if(strlen(pc + 1) != 2) {
		printf("2 chars after the point\n");
		return(-1);
	}

	if(strspn(pc + 1,digits) != strlen(pc + 1)) {
		printf("not all digits beyond point\n");
		return(-1);
	}

	*pc = '\0';
	len1 = strspn(s,digits);
	len2 = strlen(s);
	if(len1 != len2) {
		printf("should be all digits before point\n");
		return(-1);
	}
	*pc = '.';

	return(GOOD_FORM);
}
