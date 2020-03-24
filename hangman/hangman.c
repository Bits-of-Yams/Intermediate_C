#include "hangman.h"

int main(int argc, char *argv[])
{
	char *userInput = NULL;
	size_t userInputBufSize = 0;
	stats gameStatsStruct = {0};
	char **wordsBank = NULL;
	int numWordsInBank = 0;
	bool roundOver = false, playAgain;
	char *answerStringPtr = NULL;
	int answerStringLen = 0;
	char hiddenString[14];
	int numWrongGuesses = 0;

	/* CHECK TO COMMAND LINE ARGUMENT FOR WORD BANK */
	if(2 < argc)
	{
		printf("Closing Application: Too many arguments\n");
		return 0;
	}
	else if(2 == argc)
	{
		if(0 == (numWordsInBank = parseStringFile(argv[1], &wordsBank)))
		{
			printf("Could not find file. Using default word bank");
			numWordsInBank = parseStringFile("hangman.words", &wordsBank);
		}

	}
	else
	{
		numWordsInBank = parseStringFile("hangman.words", &wordsBank);
	}

	/* PRINT BANNER */
	printBanner();

	/* THE GAME LOOP */
	do
	{
		/* OPEN STATS FILE AND PRINT */
		getAndPrintStats(&gameStatsStruct);
		
		numWrongGuesses = 0;
		roundOver = false;

		//pick a random word
		answerStringPtr = randomStringFromArray(wordsBank, numWordsInBank);
		answerStringLen = strlen(answerStringPtr);
		memset(hiddenString, 0, 14);
		for(int stringIndex = 0; stringIndex < answerStringLen; stringIndex++)
		{
			hiddenString[stringIndex] = '_';
		}

		//build the board
		while(!roundOver)
		{
			printf("\e[30;0H\e[K");
			printf("\e[37;0H Wrong Guesses: %d of 6\t%c %c %c %c %c %c %c %c %c %c %c %c %c", numWrongGuesses, 
				hiddenString[0], hiddenString[1], hiddenString[2], hiddenString[3], hiddenString[4], 
				hiddenString[5], hiddenString[6], hiddenString[7], hiddenString[8], hiddenString[9], 
				hiddenString[10], hiddenString[11], hiddenString[12]);

			//prompt for guess
			printf("\e[38;0H\e[K Enter a Guess: ");
			getline(&userInput, &userInputBufSize, stdin);
			userInput[strcspn(userInput, "\n")] = 0;

			//check answer
			for(int charGuesses = 0; charGuesses < strlen(userInput); charGuesses++)
			{
				//a wrong guess
				if(0 == charOccurances(userInput[charGuesses], answerStringPtr))
				{
					numWrongGuesses++;
					printf("\e[37;0H Wrong Guesses: %d of 6\t%c %c %c %c %c %c %c %c %c %c %c %c %c", numWrongGuesses, 
						hiddenString[0], hiddenString[1], hiddenString[2], hiddenString[3], hiddenString[4], 
						hiddenString[5], hiddenString[6], hiddenString[7], hiddenString[8], hiddenString[9], 
						hiddenString[10], hiddenString[11], hiddenString[12]);


					//too many guesses?0
					if(6 == numWrongGuesses)
					{
						gameStatsStruct.numGamesLoss++;
						gameStatsStruct.numWrongGuesses += 6;
						saveStats(&gameStatsStruct);
						roundOver = true;
						printf("\e[30;0H\e[1;31m\t YOU LOST!\e[0m");
						break;
					}
				}

				//current char is in string; userInput[charGuesses]
				for(int answerIndex = 0; answerIndex < strlen(answerStringPtr); answerIndex++)
				{
					if(userInput[charGuesses] == answerStringPtr[answerIndex])
					{
						hiddenString[answerIndex] = answerStringPtr[answerIndex];
						printf("\e[37;0H Wrong Guesses: %d of 6\t%c %c %c %c %c %c %c %c %c %c %c %c %c", numWrongGuesses, 
							hiddenString[0], hiddenString[1], hiddenString[2], hiddenString[3], hiddenString[4], 
							hiddenString[5], hiddenString[6], hiddenString[7], hiddenString[8], hiddenString[9], 
							hiddenString[10], hiddenString[11], hiddenString[12]);

					}
				}

				//is word revealed
				if(0 == charOccurances('_', hiddenString))
				{
					gameStatsStruct.numGamesWon++;
					gameStatsStruct.numWrongGuesses += numWrongGuesses;
					saveStats(&gameStatsStruct);
					roundOver = true;
					printf("\e[30;0H\e[1;32m\t YOU WON!\e[0m");
					break;
				}
		
			}
			free(userInput);
			userInput = NULL;
			userInputBufSize = 0;
		}
		
		//play again?
		printf("\e[38;0H\e[K");
		playAgain = promptPlayAgain();
	} while(playAgain);

	//save stats to file
	saveStats(&gameStatsStruct);

	/* CLEAN UP ALLOCATED MEMORY */
	free(*wordsBank);
	free(wordsBank);

	return 0;
}

void printBanner()
{
	printf("\e[2J\e[0;0H");
	printf("\e[1;34m************************************************************************\n");
	printf("*\e[5m**********************************************************************\e[0;1;34m*\n");
	printf("*\e[5m*\e[0;1;36m                                                                    \e[5;34m*\e[0;1;34m*\n");
	printf("*\e[5m*\e[0;1;36m     H    H    AA    N     N    GGGG   M     M    AA    N     N     \e[5;34m*\e[0;1;34m*\n");
	printf("*\e[5m*\e[0;1;36m     H    H   A  A   NN    N   G    G  MM   MM   A  A   NN    N     \e[5;34m*\e[0;1;34m*\n");
	printf("*\e[5m*\e[0;1;36m     H    H  A    A  N N   N  G        M M M M  A    A  N N   N     \e[5;34m*\e[0;1;34m*\n");
	printf("*\e[5m*\e[0;1;36m     HHHHHH  AAAAAA  N  N  N  G        M  M  M  AAAAAA  N  N  N     \e[5;34m*\e[0;1;34m*\n");
	printf("*\e[5m*\e[0;1;36m     H    H  A    A  N   N N  G   GGGG M     M  A    A  N   N N     \e[5;34m*\e[0;1;34m*\n");
	printf("*\e[5m*\e[0;1;36m     H    H  A    A  N    NN   G    G  M     M  A    A  N    NN     \e[5;34m*\e[0;1;34m*\n");
	printf("*\e[5m*\e[0;1;36m     H    H  A    A  N     N    GGGG   M     M  A    A  N     N     \e[5;34m*\e[0;1;34m*\n");
	printf("*\e[5m*\e[0;1;36m                                                                    \e[5;34m*\e[0;1;34m*\n");
	printf("*\e[5m**********************************************************************\e[0;1;34m*\n");
	printf("\e[1;34m************************************************************************\e[0m\n");

	return;
}

void getAndPrintStats(stats *statsStructPtr)
{
	char **charPtrsFromFile = NULL;
	char *strtolEndPtr = NULL;

	printf("\e[15;0H");

	if(3 == parseStringFile("hangman.stats", &charPtrsFromFile))
	{
		statsStructPtr->numGamesWon = strtol(charPtrsFromFile[0], &strtolEndPtr, 10);
		strtolEndPtr = NULL;
		statsStructPtr->numGamesLoss = strtol(charPtrsFromFile[1], &strtolEndPtr, 10);
		strtolEndPtr = NULL;
		statsStructPtr->numWrongGuesses = strtol(charPtrsFromFile[2], &strtolEndPtr, 10);
		free(*charPtrsFromFile);
		free(charPtrsFromFile);
	}
	else
	{
		statsStructPtr->numGamesWon = 0;
		statsStructPtr->numGamesLoss = 0;
		statsStructPtr->numWrongGuesses = 0;
	}

	printf("      \e[1;37m-Game %d-        \e[32m%d Wins\e[37m / \e[31m%d Losses\e[37m        Average Score: %.1f \e[0m", (statsStructPtr->numGamesWon + 
			statsStructPtr->numGamesLoss + 1), statsStructPtr->numGamesWon, statsStructPtr->numGamesLoss,
			0 == (statsStructPtr->numGamesWon + statsStructPtr->numGamesLoss) ? 0 : (statsStructPtr->numWrongGuesses
			* 1.0) / (statsStructPtr->numGamesWon + statsStructPtr->numGamesLoss));
	return;
}

void saveStats(stats *statsStructPtr)
{
	char *statsStringPtr = calloc(13, sizeof(char));
	FILE *statsFile = fopen("hangman.stats", "w");
	if(NULL == statsFile)
	{
		perror("ERROR in saveStats: ");
	}
	snprintf(statsStringPtr, 12, "%d %d %d", statsStructPtr->numGamesWon, statsStructPtr->numGamesLoss, statsStructPtr->numWrongGuesses);
	fwrite(statsStringPtr, strlen(statsStringPtr), 1, statsFile);
	fclose(statsFile);
	free(statsStringPtr);
}

