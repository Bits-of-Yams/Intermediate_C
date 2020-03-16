//
//   Exercise 6-5
//
//   The envptr program behaves incorrectly because 
//   the strstr function looks for substrings and not 
//   string equality.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv, char **envp)
{
	char *pc;
	if ( argc != 2) {
		printf("Usage: env argument\n");
			exit(1);
	}
	while(*envp != NULL) {
		if(strstr(*envp, argv[1])) {
			pc = strchr(*envp,'=');
			if(strlen(argv[1]) == (pc - *envp)){
				printf("%s\n", *envp);
				exit(1);
			}
		}
		++envp;
	}
	printf("%s NOT FOUND\n", argv[1]);
}
