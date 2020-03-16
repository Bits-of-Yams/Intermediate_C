//
//  Exercise C-2
//

#include <stdio.h>

#define MAX 100

int main(int argc, char **argv)
{
	char line[MAX];
	FILE *fpin;
    
	while(--argc > 0) {
		fpin = fopen(*++argv, "r");
        
		if (fpin == NULL) {
			printf("can't open %s\n", *argv);
			continue;
		}
        
		while(fgets(line, MAX, fpin) != NULL) {
			fputs(line, stdout);
        }
        fclose(fpin);
        
		printf("----END OF %s ----\n", *argv);
	}
}
