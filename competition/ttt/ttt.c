#include <stdio.h>

int main() {
	FILE *fileI = fopen("ttt.in", "r");
	FILE *fileO = fopen("ttt.out", "w+");

	int N, M;
	fscanf(fileI, "%d %d", &N, &M);
	printf("N = %d, M = %d\n", N, M);

	char grid[N][M];
	int i, j;
	for (i = 0; i < N+1; i++) {
		for (j = 0; j < M+1; j++) {
			char temp;
			fscanf(fileI, "%c", &temp);
			if (temp != '\n') {
				grid[N][M] = temp;
				printf("c = %c\n", grid[N][M]);
			}
		}
	}

	return 0;
}
