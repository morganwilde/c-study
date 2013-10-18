#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int *userToDate(char *userInput) {
	// stores the return value of the date in numerals
	int * dateReady = malloc(sizeof(int));
	
	int i = 0;
	int element = 0;

	while (i < strlen(userInput)) {
		if (i == 0) {
			// -> takes the four char year
			// <- turns it into a 4 digit int
			dateReady[element] = (
				(userInput[i]  -'0')*1000+ 
				(userInput[i+1]-'0')*100 +
				(userInput[i+2]-'0')*10  +
				(userInput[i+3]-'0')
			);
			
			i += 5;
		} else {
			// -> takes a two char numeric value
			// <- turns it into a 2 digit int
			dateReady[element] = (
				(userInput[i]  -'0')*10+
				(userInput[i+1]-'0')
			);
			
			i += 3;
		}
		//printf("element %d = %d, %s\n", element, dateReady[element], userInput);
		element++;
	}
	return dateReady;
}

int main(int argc, char *argv[])
{
	// seconds from UNIX epoch of the date user inputs
	long datetime;
	int  unixdate[6] = {1970, 1, 1, 0, 0, 0};
	char userdatestring[19];
	int *userdate;

	// for testing purposes - set datetime manually
	strcpy(userdatestring, "2013 09 14 21 51 20");


	userdate = userToDate(userdatestring);
	
	printf("value of userdate = %s\n", userdatestring);
	printf("value of year: %d, month: %d\n", userdate[0], userdate[1]);
	
	return 0;
}
