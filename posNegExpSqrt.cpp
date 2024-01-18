#include <stdio.h>
#include <math.h>

int number;

int main() {
	
	//Data input
	printf("Input a number: ");
	scanf("%i", &number);
	
	//Data output
	if (number > 0) {
		printf("||Positive Number||\nSquare root: %.2f", sqrt(number));
	}
	if (number < 0) {
		printf("||Negative Number||\nSquare: %i", (number*number));
	}
	if (number == 0) {
		printf("Number is 0");
	}
	
	return 0;
}
