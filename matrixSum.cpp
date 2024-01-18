#include <stdio.h>

int numbers[3][2], sum;
char garbage[100];

int main() {
	//Initialization
	sum = 0;
	
	//Data input
	printf("Input integer numbers for a 3x2 matrix\n");
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			while (1) {
				printf("\nInput number of line %i | column %i: ", i+1, j+1);
				if (scanf(" %i", &numbers[i][j]) != 1) {
					scanf("%s", garbage);
					printf("\nERROR: Invalid input");
				} else {
					break;
				}	
			}
		//Processing
		sum += numbers[i][j];
		}
	}
	
	//Data output
	printf("\n----------------------------------------------------------\n");
	printf("The sum of all matrix elements result %i", sum);
	
	return 0;
}
