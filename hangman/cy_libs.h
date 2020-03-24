#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <errno.h>
#include <time.h>

int parseString(char *toParseString, char ***memAddrOfPtrToCharPtrArray);
int parseStringFile(char *fileName, char ***memAddrOfPtrToCharPtrArray);
char *randomStringFromArray(char **stringArray, int arrayStringCount);
int charOccurances(char aChar, char *aString);
bool promptPlayAgain(void);
