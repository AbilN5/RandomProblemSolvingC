#include <stdio.h>

int arraySize, i;
char garbage[100];

#define ARRAY_PATTERNS 2 

enum arrayPatern {
	ORIGINAL,
	INVERSE
};

int main() {
	
	//Data input
	printf("Array Inversor\n----------------------------\n");
	
	//array size
	while (1) {
		printf("\nInput the array size: ");
		int valid;
		if ((valid = scanf(" %i", &arraySize)) == 1 && arraySize > 0) {
			break;
		} else {
			if (valid != 1) {
				scanf("%s", garbage);
			}
			printf("Error: Invalid input");
		}
	}
	
	int numbers[ARRAY_PATTERNS][arraySize];
	
	//array content
	for (i = 0; i < arraySize; i++){	
			while (1) {
			printf("\nInput number %i: ", i+1);
			if (scanf(" %i", &numbers[ORIGINAL][i]) == 1) {
				break;
			} else {
				scanf("%s", garbage);
				printf("Error: Invalid input");
			}
		}
	}
	i--; //adjust i back to last array position
	
	//Processing - Inversion
	for (int j = 0; j <= i; j++) {
		numbers[INVERSE][j] = numbers[ORIGINAL][i-j];	//As j increases, i - j decreases. When i == j, i - j = 0.
	}
	
	//Data output
	printf("\nInversed Array\n-------------------------------------------------------------------------------\n");
	for (i = 0; i < arraySize; i++) {
		printf("Position %i:\t(Original) %10i | %10i (Inversed)\n", i+1, numbers[ORIGINAL][i], numbers[INVERSE][i]);
	}
	
	return 0;
}
