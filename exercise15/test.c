#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	printf("Hello\n");
	
	int n = atoi(&argv[1][0]);

	printf("Number - %d\n", n);

	return 0;
}
