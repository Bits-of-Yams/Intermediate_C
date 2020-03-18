#include <stdbool.h>

int parseString(char *toParseString, char ***stringArrayPtr);
int parseStringFile(char *fileName, char ***stringArrayPtr);
char *randomStringFromArray(**stringArray);
int charOccurances(char aChar, char *aString);
void promptCharAndReplace(char *targetString);
int parseProgramArgs(int argCount, char **argvArray, char **switchArray, char **argArray);
int promptProgramArgs(char **switchArray, char **argArray);
bool promptPlayAgain(void);
void *allocateMemory(void);
bool stringIsDigits(char *aString);


