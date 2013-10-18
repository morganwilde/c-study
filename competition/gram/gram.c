#include <stdio.h>
#include <string.h>

void printCharCount(int index, int *array) {
	if ((index >= 48 && index < 58) ||
		(index >= 65 && index < 91) ||
		(index >= 97 && index < 123)) {
		printf("char[%c] = %d\n", index, array[index]);
	}
}

int main() {
	FILE *fileI = fopen("gram.in", "r");
	FILE *fileO = fopen("gram.out", "w+");

	char wordPrime[50] = "\0";
	int wordCount;
	fscanf(fileI, "%s", wordPrime);
	fscanf(fileI, "%d", &wordCount);

	// Take the count of each letter in wordPrime
	int charArray[256] = {0};
	int i;
	for (i = 48; i < 58; i++)	charArray[i] = 0;
	for (i = 65; i < 91; i++)	charArray[i] = 0;
	for (i = 97; i < 123; i++)	charArray[i] = 0;

	// Take the count
	for (i = 0; i < strlen(wordPrime); i++) {
		charArray[wordPrime[i]] += 1;
		//printf("char - %c\n", wordPrime[i]);
	}
	/*
	for (i = 0; i < 256; i++) {
		printCharCount(i, charArray);
	}
	*/

	for (i = 0; i < wordCount; i++) {
		int checkArray[256] = {0};
		// Read a word to check
		char wordCheck[50] = "\0";
		fscanf(fileI, "%s", wordCheck);
		//printf("word - %s\n", wordCheck);

		// Store the character data
		int j;
		for (j = 0; j < strlen(wordCheck); j++) {
			checkArray[wordCheck[j]] += 1;
		}

		// Compare to prime word
		int test = 0;
		for (j = 0; j < strlen(wordPrime); j++) {
			int testA = charArray[wordPrime[j]];
			int testB = checkArray[wordPrime[j]];
			//printf("testA = %d, testB = %d\n", testA, testB);
			if (testA == testB) test++;
		}
		if (test == strlen(wordPrime)) {
			if (strcmp(wordPrime, wordCheck) == 0)
				fprintf(fileO, "IDENTICAL\n");
			else
				fprintf(fileO, "ANAGRAM\n");
		} else {
			fprintf(fileO, "NOT AN ANAGRAM\n");
		}
	}

	//printf("word - %s\n", wordPrime);
	//printf("count - %d\n", wordCount);

	return 0;
}
