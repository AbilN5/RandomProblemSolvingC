#include <stdio.h>

int vector[10];
char garbage[100];

int main() {
	
	printf("Input 10 integer values\n\n");
	//Data input
	for (int i = 0; i < 10; i++) {
		while (1) {
			printf("Input value number %i: ", i+1);
			if (scanf(" %i", &vector[i]) == 1) {
				break;
			}
			else {
				printf("ERROR: Invalid Input\n");
				scanf("%s", garbage);
			}
		}
	}
	
	//Data output
	printf("\nVector Content (Above or Equal to 10)\n---------------------------------------------\n");
	for (int i = 0; i < 10; i++) {
		if (vector[i] >= 10) {
			printf("vector[%i]: %10i\n", i, vector[i]);
		}
	}
	
	return 0;
}
