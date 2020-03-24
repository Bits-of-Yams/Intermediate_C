#include "cy_libs.h"

/* Requirement: Write a function that splits words (blank-delimited) from a string argument saving
 * in an array of strings passed as an argument to the function. Return the number of words split/saved.
 * 
 * ARGUMENTS:
 * toParseString - needs to point to heap memory, it will get broken into null terminated strings
 * stringArrayPtr - needs to be the address of a variable which points to NULL, not to be confused with the address of NULL.
 *
 * DESCRIPTION:
 * The function will allocate memory on the heap. The memory will be treated as a consecutive sequence of 
 * char pointers (char *) so that array indexing and pointer arithmetic operations on stringArrayPtr 
 * will be possible. To do so, the number of bytes to allocated should be the number of char pointers times the
 * size of a char pointer.
 *
 * Think of stringArrayPtr as a pointer to memory where char pointers are stored, a double pointer; however, 
 * because the function allocates this memory for the user it needs to set the value of the pointer to the
 * address it allocated, therefore, stringArrayPtr's memory address is passed to the function, hence a triple pointer.
 */
 int parseString(char *toParseString, char ***stringArrayPtr)
{
	int wordsParsed = 0;
	char *extractedStringPtr = NULL;
	if(NULL == toParseString)
	{
		printf("ERROR: toParseString was passed a NULL pointer in parseString\n");
		exit(1);
	}
	if(NULL != *stringArrayPtr)
	{
		printf("ERROR: stringArrayPtr wasn't a NULL pointer in parseString\n");
	}

	extractedStringPtr = strtok(toParseString, " "); //strtok returns a pointer to the start of the string it tokenized

	while(NULL != extractedStringPtr) //loop everytime there is a string pointer to store
	{
		wordsParsed++;
		//the memory address of stringArrayPtr (the pointer to char pointers) was given to the function
		//so to set where stringArrayPtr points to, dereference the triple pointer
		*stringArrayPtr = realloc(*stringArrayPtr, wordsParsed * sizeof(char *));
		if(NULL == *stringArrayPtr)
		{
			printf("ERROR: malloc returned NULL in parseString\n");
			exit(1);
		}

		//the following uses pseudo memory addresses for explanation purposes only
		//original string shows what strtok wil do to it after the while loop is done
		//we're doing pointer arithmetic on a variable that the compiler sees as a double pointer (pointer to char pointers)
		//means that pointer arithmetic will be handled as 8byte (64bit) or 4byte (32bit) increments
		//original string: hello\0cruel\0world		stringPtrArray: FFFFF100FFFFF106FFFFF10c
		//	0xFFFFF... 100    106    10c		    0xFF0000... F0	F4	F8
		//(*stringArrayPtr)     = 0xFF0000F0
		//(*stringArrayPtr) + 1 = 0xFF0000F4  the value is incremented by 4 because of the size of a char* in this 32bit example
		*((*stringArrayPtr) + (wordsParsed - 1)) = extractedStringPtr;
		//youre dereferencing after pointer arithmetic because you want to store the pointer at that memory address
		extractedStringPtr = strtok(NULL, " ");
	}

	return wordsParsed;
}
/* Requirements: Write a function that reads a file containing blank-delimited words and stores into a
 * character array such that each word from the file is one array element. Pass the array as an argument
 * and return the number of words read/parsed. Consider using the above function in this function?????
 *
 * IMPORTANT NOTE: getline will allocate memory on the heap. You will be using this memory outside of this
 * function so you do not want to free the memory in this function, just remember to free the stringArrayPtr
 * you pass to the function at some point before you exit the program, if you freed in this function, then
 * you'll either get bad data, broken functionality, or valgrind will throw read errors because youre reading
 * data that was freed, it may work because the data wasnt overwritten yet, but it was dangerous.
 */
int parseStringFile(char *fileName, char ***stringArrayPtr)
{
	char *stringFromFile = NULL;
	size_t stringFromFileBufSize = 0;
	int parsedStrings;
	FILE *filePtr = fopen(fileName, "r");
	if(NULL == filePtr)
	{
		if(ENOENT != errno)
		{
			printf("ERROR: fopen failed in parseStringFile\n");
			exit(1);
		}
		return 0;
	}

	getline(&stringFromFile, &stringFromFileBufSize, filePtr);
	fclose(filePtr);
	stringFromFile[strcspn(stringFromFile, "\n")] = 0; //get rid of the pesky \n and replace with a null terminator
	parsedStrings = parseString(stringFromFile, stringArrayPtr);

	return parsedStrings;
}

//Write a function that randomly selects a string from an array of strings
char *randomStringFromArray(char **stringArray, int arrayStringCount)
{
	srand(time(NULL));
	
	return stringArray[rand() % arrayStringCount];
}


//Write a function that counts the number of occurrences of a character within a string.
int charOccurances(char aChar, char *aString)
{
	int charCount = 0;
	char *ptrToRestOfTheString = strchr(aString, aChar);
	
	while(ptrToRestOfTheString != NULL)
	{
		charCount++;
		ptrToRestOfTheString = strchr(ptrToRestOfTheString + 1, aChar);
	}

	return charCount;
}

//Write a function that prompts the user “You wanna play again”, accepting input. If the input is ‘n’ return false; anything else, return true
//that 'anything else' means if it wasn't an 'n' then don't care what was put, just play again, I actually just checked the first char
//so if they put nYESreallyIwantToPlayAgain it still exits because userInput[0] was a 'n'
bool promptPlayAgain(void)
{
	char *userInput = NULL;
	size_t userInputBufSize = 0;

	printf("\e[KPlay Again? ");
	getline(&userInput, &userInputBufSize, stdin);
	if('n' == userInput[0])
	{
		free(userInput);
		return false;
	}
	free(userInput);
	return true;
}
