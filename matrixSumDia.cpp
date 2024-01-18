#include <stdio.h>

int elements[4][4], diagonal, sum;
char garbage[100];

int main() {
	//Initialization
	diagonal = sum = 0;
	
	//Data input
	for (int i = 0; i < 4; i++) { 		//lines
		for (int j = 0; j < 4; j++) {	//columns
			//error handling
			while (1) {
				printf("\nInput element [%i,%i]: ", i+1, j+1);
				if (scanf(" %i", &elements[i][j]) != 1) {
					scanf("%s", garbage);
					printf("\nERROR: Invalid input");
				} else {
					break;
				}
			}
			sum += elements[i][j];
			if (i == j) {
				diagonal += elements[i][j];
			}
		}
	}
	
	//Data output
	printf("\n-------------------------------------------\n");
	printf("Sum of all elements        : %10i\n", sum);
	printf("Sum of elements of diagonal: %10i\n", diagonal);
	
	return 0;
}

