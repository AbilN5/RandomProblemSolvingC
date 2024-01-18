#include <stdio.h>

int vector[10], biggest, position;
char garbage[100];

int main() {
	//Initialization
	position = biggest = -1; //This will be updated at least once, as the program only accepts zeroes and positive numbers
	
	//Data input
	printf("Input 10 positive integers");
	for (int i = 0; i < 10; i++) {
		while (1) {
			printf("\nInput number %i: ", i+1);
			int valid;
			if ((valid = scanf(" %i", &vector[i])) == 1 && vector[i] >= 0) {
				break;
			} else {
				if (valid != 1) {
				scanf("%s", garbage);
				}
				printf("\nERROR: Invalid input");
			}
		}
		if (biggest < vector[i]) {
			position = i;
			biggest = vector[i];
		}
	}
	
	//Data output
	printf("\n-------------------------------\n");
	printf("Biggest number :\t%10i\n", biggest);
	printf("Number position:\t%10i\n", position+1);
	
	return 0;
}
