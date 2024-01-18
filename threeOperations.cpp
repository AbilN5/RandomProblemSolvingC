#include <stdio.h>
#include <conio.h>

int op, a, b, c, sum;
float average;

int main() {
	
	//Data input
	printf("Input a value for A: ");
	scanf("%i", &a);
	printf("Input a value for B: ");
	scanf(" %i", &b);
	printf("Input a value for C: ");
	scanf(" %i", &c);
	printf("Choose a case for operation ( 1 | 2 | 3 ): ");
	op = getche();
	op -= 48;
	
	while ((op < 1) || (op > 3)) {
		printf("\nERROR: Invalid value\nChoose a case for operation ( 1 | 2 | 3 ): ");
		op = getche();
		op -= 48;
	}
	
	//Processing and data output
	switch(op) {
		case 1:
			average = (float) ((a + b + c)/3);
			printf("\n\nThe average of %i, %i, and %i is %.2f", a, b, c, average);
			break;
		case 2:
			sum = a + b + c;
			printf("\n\nThe sum of %i, %i, and %i, is %i", a, b, c, sum);
			break;
		case 3:
			if ((b % 2) == 0) {
				printf("\n\n%i is an even number", b);
			} else {
				printf("\n\nB is an odd number");
			}
			break;
	}
	
	
	return 0;
}
