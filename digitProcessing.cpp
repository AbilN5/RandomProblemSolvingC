#include <stdio.h>

int ogNumber;
int digit[4];
int digitsProcessed;
int magnitude;
int processedNumber;

int main() {
	
	//Data Input
	printf("Input a number with 3 digits: ");
	scanf("%i", &ogNumber);
	
	while ((ogNumber <= -1000) || (ogNumber >= 1000) || ((ogNumber < 100) && (ogNumber > -100))) {
		printf("ERROR: Invalid Input\nInput a number with 3 digits: ");
		scanf("%i", &ogNumber);
	}
	
	//Processing - Step 1: Get each digit
	magnitude = 10;
	digitsProcessed = 0;
	for (int i = 1; i <= 3; i++) {
		digit[i] = (ogNumber % magnitude) - digitsProcessed;
		digitsProcessed += digit[i];
		digit[i] /= (magnitude/10);
		magnitude *= 10;
	}
	
	//Processing - Step 2: Find the four digit
	digit[0] = (digit[1]*5 + digit[2]*3 + digit[3]) % 7;
	
	//Processing - Step 3: Find the new number
	processedNumber = 0;
	magnitude /= 10;
	for (int i = 3; i >= 0; i--) {
		processedNumber += digit[i]*magnitude;
		magnitude /= 10;
	}
	
	//Data output
	printf("The new number is %i", processedNumber);
	
	return 0;
}
