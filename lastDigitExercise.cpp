#include <stdio.h>

int number;

int main() {
	
	//Data input
	printf("Input a number: ");
	scanf("%i", &number);
	
	//Data output
	printf("The last algarism of %i is %i", number, (number % 10));
	
	return 0;
}
