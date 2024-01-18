#include <stdio.h>

int vector[10], positives, negatives, zeroes;
char garbage[100];

int main() {
	//Initialization
	positives = negatives = zeroes = 0;
	
	printf("Input 10 integers\n");
	//Data input
	for (int i = 0; i < 10; i++) {
		while (1) {
			printf("\nInput value %i: ", i+1);
			if (scanf(" %i", &vector[i]) == 1) {
				break;
			} else {
				scanf("%s", garbage);
				printf("ERROR: Invalid input\n");	
			}
		}
		if (vector[i] > 0) {
			positives++;
		} else if (vector[i] < 0) {
			negatives++;
		} else {
			zeroes++;
		}
	}
	
	//Data output
	printf("\n\n---------------------------\n");
	printf("The vector contains...\n");
	printf("Positives:\t%10i\n", positives);
	printf("Negatives:\t%10i\n", negatives);
	printf("Zeroes   :\t%10i\n", zeroes);
	
	return 0;
}
