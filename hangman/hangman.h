#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct statsStruct
{
	int numGamesWon;
	int numGamesLoss;
	int numWrongGuesses;
} stats;

extern int parseString(char *toParseString, char ***stringArrayPtr);
extern int parseStringFile(char *fileName, char ***stringArrayPtr);
extern char *randomStringFromArray(char **stringArray, int arrayStringCount);
extern int charOccurances(char aChar, char *aString);
extern void promptCharAndReplace(char *targetString);
extern int parseProgramArgs(int argCount, char **argvArray, char **switchArray, char **argArray);
extern int promptProgramArgs(char **switchArray, char **argArray);
extern bool promptPlayAgain(void);
extern void *allocateMemory(void);
extern bool stringIsDigits(char *aString);

void printBanner(void);
void getAndPrintStats(stats *statsStructPtr);
void saveStats(stats *statsStructPtr);
