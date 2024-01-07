#include <stdio.h>

char numberDigits[21];
char invertedNumber[21];
int verifier;

int main() {
	
	//Data input
	printf("Write a number without 0 algharism: ");
	fgets(numberDigits, sizeof(numberDigits), stdin);
	
	int i = 0;
	while ((i <= 20) && (numberDigits[i] != '\n')) {
		verifier = numberDigits[i];
		if ((verifier != 43) && (verifier != 45) && ((verifier < 49) || (verifier > 57))) {
			printf("ERROR: Invalid input\nWrite a number without 0 algharism: ");
			fgets(numberDigits, sizeof(numberDigits), stdin);
			i = -1;
		}
		i++;
	}
	numberDigits[i] = '\0';
	i--; //sets i to the last number before \0
	
	//Number inversion
	for (int j = i; j >= 0; j--) {
		invertedNumber[i-j] = numberDigits[j]; 	//i - j is the last number - j. As j becomes smaller, i - j increases
	}
	
	invertedNumber[i+1] = '\0';
	
	//Data output
	printf("The inverse of %s is %s", numberDigits, invertedNumber);
	
	return 0;
}
