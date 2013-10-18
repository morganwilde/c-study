#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

char *binary(int decimal, char *binaryNum) {
	if (strlen(binaryNum) < 8) {
		printf("strlen of binaryNum: %zd, initialize it.\n", strlen(binaryNum));
		binaryNum = "00000000\0";
	}

	if (decimal > 0) {
		int i;
		for (i = 0; decimal - pow(2, i) > 0; i++);
		i--;

		// recursive step
		//binaryNum[i] = '1';
		char binaryNumBuffer[9] = {'\0'};
		int j;
		for (j = 8; j > 0; j--) {
			if (j == i)
				strcat(binaryNumBuffer, "1");
			else
				strcat(binaryNumBuffer, "0");
			
		}

		binaryNum = binaryNumBuffer;
		printf("copied string - %s\n", binaryNum);
		binaryNum = binary(decimal - pow(2, i), binaryNum);
	} else {
		
	}
	
	return binaryNum;
}

char *test(int number, char *storage) {
	int storageSize = 8; // how many bits to store
	if (storage == NULL)
		storage = malloc(storageSize + 1); // memory for storageSize number of chars + NULL char

	int i;
	for (i = 0; number > pow(2, i); i++);
	int power;
	if (i > 0) power = i - 1;
	else power = 0;
	int remainder = number - pow(2, power);

	printf("number:%d, power:%d, remainder:%d\n", number, power, remainder);

	for (i = storageSize; i >= 0; i--) {
		if (storageSize - i == power) {
			storage[storageSize - i] = '1';
			printf("char number for 1: [%d]\n", i);
		}
		else if (storage[storageSize - i] != '1') storage[storageSize - i] = '0';		
	}
	storage[storageSize] = '\0';
	printf("storage state: [%s]\n", storage);
	
	if (remainder > 0)
		storage = test(remainder, storage);

	return storage;
}

int main()
{
	char *testResult = test(17, NULL);
	printf("storage is '%s', strlen is %zd\n", testResult, strlen(testResult));

	int j;
	for (j = 0; j < strlen(testResult); j++) {
		printf("element at [%d]=(%c)\n", j, testResult[j]);
	}

	return 0;
}
