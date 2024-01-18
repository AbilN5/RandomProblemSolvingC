#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*OBS.: I thought something while starting to make the code, but realized it was kinda dumb to create an array for	
three distinct variables that don't relate at all, but I decided to keep it anyways, so I could exercise a little on 
enums (I kinda like using arrays too, but don't take this as an example on what to do)								*/

int arraySize, range[3];
char garbage[100];

enum rangeElements {
	MIN_NUMBER,
	MAX_NUMBER,
	INTERVAL_ELEMENTS
};

int main() {
	//Initialization
	srand(time(NULL));
	for (int i = 0; i < INTERVAL_ELEMENTS; i++) {
		range[i] = 0;
	}
	
	//Data input
	printf("Random Numbers Generator (no rep)\n---------------------------------\n");
	
	//numbers quantity
	while (1) {
		printf("Input the numbers quantity: ");
		int valid;
		if ((valid = scanf(" %i", &arraySize)) == 1 && arraySize > 0) {
			break;
		} else {
			if (valid != 1) {
				scanf("%s", garbage);
			}
			printf("ERROR: Invalid input\n");
		}
	}
	
	//numbers range
	do {
		printf("Input two values that encompass the values range (range must be greater or equal to numbers quantity)\n");
		int valid;
		if ((valid = scanf(" %i %i", &range[MIN_NUMBER], &range[MAX_NUMBER])) != 2) {
			scanf("%s", garbage);
			printf("ERROR: Invalid input\n");
			continue;
		}
		range[INTERVAL_ELEMENTS] = abs(range[MIN_NUMBER] - range[MAX_NUMBER]) + 1;	
		if (range[INTERVAL_ELEMENTS] < arraySize) {
			printf("ERROR: Invalid input\n");
		}
	} while (range[INTERVAL_ELEMENTS] < arraySize);
	
	//min-max adjust
	if (range[MIN_NUMBER] > range[MAX_NUMBER]) {
		range[MIN_NUMBER] ^= range[MAX_NUMBER];
		range[MAX_NUMBER] ^= range[MIN_NUMBER];
		range[MIN_NUMBER] ^= range[MAX_NUMBER];	//XOR swap. Kinda tricky
	}
	
	//Processing 
	//array creation
	int number[arraySize];
	
	//number generation
	for (int i = 0; i < arraySize; i++) {
		number[i] = (rand() % range[INTERVAL_ELEMENTS]) + range[MIN_NUMBER]; // generate number -> insert it on interval -> move numbers by min number (0 -> min number, and so on)
		for (int j = i-1; j >=0; j--) {
			if (number[i] == number[j]) {
				number[i] = (rand() % range[INTERVAL_ELEMENTS]) + range[MIN_NUMBER];
				j = i;	//Goes back to last position, which will be decremented and test all positions again
			}
		}
	}
	
	//Data output
	printf("\nGENERATED NUMBERS\n------------------------------------------\n");
	for (int i = 0; i < arraySize; i++) {
		printf("Number %i\t:%10i\n", i+1, number[i]);
	}
	
	return 0;
}
