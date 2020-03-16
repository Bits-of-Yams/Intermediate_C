//
//  Exercise C-1
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int main(int argc, char **argv)
{
	char line1[MAX], line2[MAX];
	FILE *fp1, *fp2;
	int lineno = 0;
    
	setbuf(stdout, NULL);
    
	if (argc != 3) {
		printf("usage: comp: file1 file2\n");
		exit(1);
	}
    
	fp1 = fopen(argv[1], "r");
	if (fp1 == NULL) {
		printf("couldn't open %s\n", argv[1]);
		exit(2);
	}
    
	fp2 = fopen(argv[2], "r");
	if (fp2 == NULL) {
		printf("couldn't open %s\n", argv[2]);
		exit(3);
	}
    
	while (fgets(line1, MAX, fp1) != NULL) {
		lineno++;
		if (fgets(line2, MAX, fp2) == NULL){
			printf("EOF on %s\n", argv[2]);
			exit(4);
		}
		if (strcmp(line1, line2) != 0) {
			printf("%s AND %s differ: line %d\n", argv[1], argv[2], lineno);
			exit(6);
		}
	}
    
	if (fgets(line2, MAX,fp2) == NULL){
		printf("FILES are identical\n");
		exit(0);
	}
    
	printf("EOF on %s\n", argv[1]);
	exit(5);
}
