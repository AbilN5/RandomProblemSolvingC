#include <stdio.h>

int A, B, C;

int main() {
	
	//Data input
	printf("Input integer values for variables A, B, and C, separated by a space or new line: ");
	scanf("%i %i %i", &A, &B, &C);
	
	//Data output 
	if ((A < B + C) && (B < C + A) && (C < A + B)) {
		printf("It is possible to create a triangle with the inputted values");
	} else {
		printf("It is not possible to create a triangle with the inputted values");
	}
	
}
