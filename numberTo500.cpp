#include <stdio.h>

int numberInput, numberMax, number;
char garbage[100];

int main() {
	//Data initialization
	numberInput = number = 0;
	numberMax = 500;
	
	//Data input and processing
	while (number < numberMax) {
		printf("Current number: %i\n", number);
		printf("Input an integer (finished after number is equal or above %i): ", numberMax);
		while (scanf("%i", &numberInput) != 1) {
			scanf("%s", garbage);
			printf("ERROR: Invalid Input\nInput an integer (finished after number is equal or above %i): ", numberMax);
		}
		{
		int c;
		while (((c = getchar()) != '\n') && (c != EOF)) { }
		}
		
		number += numberInput;	
	}
	
	//Data output
	printf("\n-------------------------------\nFinal number: %i", number);
}
