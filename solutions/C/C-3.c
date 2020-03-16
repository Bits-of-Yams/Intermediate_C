//
//  Exercise C-3
//

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int main(int argc, char **argv)
{
	int fileIsOpen;
    char line[MAX];
	FILE *fpin, *out;
    
	out = stdout;
    fileIsOpen = 0;
    
	if (argv[argc - 1][0] == '+'){
		out = fopen(argv[argc - 1], "w");
		if (out == NULL ) {
			printf("Error opening output file\n");
			exit(2);
		}
        fileIsOpen = 1;
	}
    
	while (--argc > 0) {
		fpin = fopen(*++argv,"r");
        
		if ( fpin == NULL) {
			printf("Can't open %s\n", *argv);
			continue;
		}
        
		while (fgets(line, MAX, fpin) != NULL) {
			fputs(line, out);
        }
        
        fclose(fpin);
	}
    
    if (fileIsOpen) {
        fclose(out);
    }
}
