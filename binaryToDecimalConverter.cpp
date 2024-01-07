#include <stdio.h>

int decimalNumber;
char binaryNumber[34];
int numberMagnitude;
int binaryDigits[32];
int binaryDigitsInverted[32];

int main() {
	
	//Data Input
	printf("Input a binary number for integer (up to 32 bits): ");
	fgets(binaryNumber, sizeof(binaryNumber), stdin);
	
	{
		int i = 0;
		while (binaryNumber[i] != '\n') {
			binaryDigits[i] = binaryNumber[i] - 48;
			if ((binaryDigits[i] < 0) || (binaryDigits[i] > 1)) {
				printf("ERROR: Invalid input\nInput a binary number for integer (up to 32 bits): ");
				fgets(binaryNumber, sizeof(binaryNumber), stdin);
				i = -1;
			}
			i++;
		}
		binaryNumber[i] = '\0';
		numberMagnitude = --i;
		for (int j = 0; j <= i; j++) {
			binaryDigitsInverted[j] = binaryDigits[i-j];
		}
	}
	
	//Get decimal number
	for (int i = 0; i < numberMagnitude; i++) {
		int termOfPotency = binaryDigitsInverted[i];
		for (int j = 1; j <= i; j++) {
			termOfPotency *= 2;
		}
		decimalNumber += termOfPotency;
	}
	
	if (binaryDigitsInverted[numberMagnitude] == 1) {
		int twoMagnitude = -1;
		for (int i = 1; i <= numberMagnitude; i++) {
			twoMagnitude *= 2;
		}
		decimalNumber += twoMagnitude; 
	} 
	
	printf("The binary number %s is equal to the decimal number %i", binaryNumber, decimalNumber);

	return 0;
}
