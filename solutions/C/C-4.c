//
//  Exercise C-4
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct simple {
	int a;
	int b;
};

#define MAXFILENAME 80

int main()
{
	long distance =  sizeof(struct simple);
	FILE *fp;
	char fname[MAXFILENAME];
	struct simple first, last;
	int n;

	printf("Enter filename: ");
	fgets(fname, MAXFILENAME, stdin);
    fname[strlen(fname) - 1] = '\0';    //  Strip off newline
    
	fp = fopen(fname, "r+b");
	if (fp == NULL) {
		printf("Can't open %s\n", fname);
		exit(1);
	}
    
	distance = distance * -1;

	fread(&first, sizeof(struct simple), 1, fp);
    
	fseek(fp, distance, 2);
	fread(&last, sizeof(struct simple),1,fp);
    
	fseek(fp, distance, 2);
	fwrite(&first,sizeof(struct simple),1,fp);
    
	fseek(fp, 0L, 0);
	fwrite(&last,sizeof(struct simple),1,fp);
    
	fflush(fp);
	fclose(fp);
}
