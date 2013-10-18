#include <stdio.h>
#include <limits.h>

int main() {
	FILE *fileI = fopen("ads.in", "r");
	FILE *fileO = fopen("ads.out", "w+");

	// Read the input file
	// N - the number of clients
	int N;
	fscanf(fileI, "%d", &N);
	// i 	- index the new array
	// C 	- the array of all the client ad buys
	// min 	- the smallest number of ads a client bought
	// minI - the index of that client
	// max 	- the largest number of ads
	// maxI - the index of that client
	int i, C[N], min = 0, minI, max = 0, maxI;
	for (i = 0; i < N; i++) {
		fscanf(fileI, "%d", &C[i]);
		if (min == 0 || min > C[i]) {
			min = C[i];
			minI = i;
		}
		if (max == 0 || max < C[i]) {
			max = C[i];
			maxI = i;
		}
		//printf("C[%d] = %d\n", i, C[i]);
	}
	//printf("min = %d; minI = %d\n", min, minI);
	//printf("max = %d; maxI = %d\n", max, maxI);
	
	// Describe the optimal sequence
	i = maxI;
	int j = 0;
	while (j <= 100000) {
		//printf("i = %d, C[%d] = %d\n", i+1, i, C[i]);
		if (C[i] > 0) {
			// Write to file
			fprintf(fileO, "%d\n", i+1);

			C[i] = C[i] - 1;
			if (C[i] > 0) {
				// Check leftmost
				if (C[i-1] > 0 && i-1 >= 0) {
					i = i - 1;
				} else {
					i = i + 1;
				}
				// Check rightmost
			} else if (C[i-1] > 0 && i-1 >= 0) {
				i = i - 1;
			} else if (C[i+1] > 0 && i+1 < N) {
				i = i + 1;
			}
		} else {
			break;
		}
		
		j++;
	}

	//printf("INT_MAX = %d\n", INT_MAX);
	//printf("LONG_MAX = %ld\n", LONG_MAX);
	
	return 0;
}
