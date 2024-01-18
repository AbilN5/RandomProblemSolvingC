#include <stdio.h>
#include <stdlib.h>

#define NUMBERS_TO_NEWLINE 20

int printedNumbers, sign;
char countingFormat[NUMBERS_TO_NEWLINE];

int main() {
	//Initialization
	countingFormat[0] = '\n';
	for (int i = 1; i < NUMBERS_TO_NEWLINE; i++) {
		countingFormat[i] = ' '; 
	}
	
	//Data input 
	printf("Input the number of odd numbers you want to count: ");
	scanf("%i", &printedNumbers);
	
	//Processing and output
	sign = (printedNumbers != 0) ? abs(printedNumbers)/printedNumbers : 0;
	
	printf("Odd numbers in reverse order:\nCounting...");
	for (int i = printedNumbers; i != 0; i -= sign) {
		printf("%c%i", countingFormat[(i * sign) % NUMBERS_TO_NEWLINE], 2*i-sign);
	}
	
	return 0;
}
