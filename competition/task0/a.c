#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main() {
	// input/output sources
	FILE *fileIn = fopen("gram.in", "r+");
	FILE *fileOut = fopen("gram.out", "w");

	if (!fileIn) return 1; // error in reading file

	// read out all the lines
	int maxString = 51; // 1 byte for \0 + 1 byte for \n
	char buffer[maxString]; // store the word here
	char *wordIn = malloc(strlen(buffer));
	char *wordCheck;
	char *message = malloc(50);
	int wordCount, i;

	// read the base word
	fgets(buffer, maxString, fileIn);
	strcpy(wordIn, buffer);
	// read the number of words
	fgets(buffer, maxString, fileIn);
	wordCount = atoi(buffer);
	//printf("count - %d\n", wordCount);

	while (fgets(buffer, maxString, fileIn) != NULL) {
		i++;
		wordCheck = malloc(strlen(buffer));
		strcpy(wordCheck, buffer);
	
		// see if it contains all the right letters
		int letter;
		int matches = 0; // letter source, letter target

		if (strcmp(wordCheck, wordIn) == 0) {
			// strings match
			strcpy(message, "IDENTICAL\n");
			//printf("IDENTICAL\n");
		} else {
			for (letter = 0; letter < strlen(wordIn); letter++) {
				if (strchr(wordCheck, wordIn[letter])) matches++;
			}
			// test for an anagram
			if (matches == strlen(wordIn)) {
				strcpy(message, "ANAGRAM\n");
				//printf("ANAGRAM\n");
			}
			else {
				strcpy(message, "NOT AN ANAGRAM\n");
				//printf("NOT AN ANAGRAM\n");
			}
		}
		fwrite(message, 1, strlen(message), fileOut);

		if (i == wordCount) break;
	}
	
	//fwrite("\n", 1, 1, fileOut);

	// free IO sources
	fclose(fileIn);
	fclose(fileOut);
	// free pointers
	if (wordIn) free(wordIn);
	if (wordCheck) free(wordCheck);

	return 0;
}
