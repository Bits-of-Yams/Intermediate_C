#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv, char** envp)
{
	if(argc != 2) {
		fprintf(stderr, "Usage: envptr variable-name\n");
		exit(1);
	}
	
	while(*envp != NULL) {
		if (strstr(*envp, argv[1])) {
			printf("%s\n", *envp);
			exit(0);
		} else {
			envp++;
        }
	}

	printf("%s not found\n", argv[1]);
}
