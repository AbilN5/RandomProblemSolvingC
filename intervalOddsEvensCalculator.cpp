#include <stdio.h>
#include <stdlib.h>

int number1, number2, interval, odds, evens;
char garbage[100];

int main() {
	while (1) {
		printf("Input two numbers separated by a space or new line: ");
		if (scanf(" %i%i", &number1, &number2) == 2) {
			break;
		} else {
			printf("ERROR: Invalid input | Input anything and press [ENTER] if the program doesn't read invalid input automatically\n");
			scanf("%s", garbage);
		}
	}
	
	//Processing
	interval = abs(number1 - number2) + 1;
	odds = interval/2 + ((interval % 2) * (abs(number1) % 2));
	evens = interval/2 + ((interval % 2) * ((abs(number1) + 1)% 2));
	/*	interval % 2 determines if interval can be divided in equal parts, if not, it results 1
		if it results 1, number1 and number2 are either both odd or even 
		if they are odd, there is 1 more odd than evens, if they are even, there is 1 more even than odds
		abs(number1) % 2 will return 1 if they are odd, and (abs(number1) + 1) % 2 will return 1 if its even 
		the whole expression in both odds/evens will return interval/2 + [0,1]*[0,1], returning 0 for equal numbers of odds/evens and 1 for odds/even complementarily if not 
	*/
	
	//Data output
	if (number1 > number2) {
		int temporary = number1;
		number1 = number2;
		number2 = temporary;
	}
	
	printf("\n-------------------------------------\n|Interval[%i,%i]|\nEvens: %i\nOdds: %i", number1, number2, evens, odds);
	
	return 0;
}
