//
//  Exercise B-2
//
#include <string.h>
#include <stdio.h>

#define WORDSIZE 10
#define NO_WORDS 100
#define NOT_FOUND -1

int lookup(char (*tab)[WORDSIZE], char *word,  int limit);
int sort(char (*tab)[WORDSIZE], int *n, int limit);

int main()
{
	char *pc, *delim = "\n\t .,<>[]\\_}{()=";
	char words[NO_WORDS][WORDSIZE], word[WORDSIZE];
	int num = 0, i, ans, counts[NO_WORDS];
    
	for (i = 0; i < NO_WORDS; i++) {
		counts[i] = 0;
    }
    
	while (scanf("%s", word) != EOF) {
		pc = strtok(word, delim);
		while (pc != NULL) {
			if ((ans = lookup(words, pc, num)) == NOT_FOUND) {
				strcpy(words[num], pc);
				counts[num++] = 1;
			} else {
				counts[ans]++;
            }
			pc = strtok(NULL, delim);
		}
	}
    
	sort(words, counts, num);
    
	for (i = 0; i < num; i++) {
		printf("%3d %s\n", counts[i], words[i]);
    }
}

int lookup(char (*tab)[WORDSIZE], char *word,  int limit)
{
	int i;
    
	for (i = 0; i < limit; i++) {
	    if (strcmp(tab[i], word) == 0) {
		    return(i);
        }
    }
    
	return(NOT_FOUND);
}

int sort(char (*tab)[WORDSIZE], int *n, int limit)
{
	int i, j, t;
	char temp[WORDSIZE];
    
	for (i = 0; i < limit - 1; i++) {
		for (j = i + 1; j < limit; j++) {
			if(strcmp(tab[i], tab[j]) > 0) {
				strcpy(temp, tab[i]);
				strcpy(tab[i],tab[j]);
				strcpy(tab[j], temp);
				t = n[i];
				n[i] = n[j];
				n[j] = t;
			}
        }
    }
}
