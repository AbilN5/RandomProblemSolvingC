#include <stdio.h>
#include <conio.h>
#include <math.h>

char operation;
float number1, number2, result, resultMulti;
int precision;
bool valid = true;

int main() {

	//Data input
	printf("Input the 1st number: \t");
	scanf("%f", &number1);
	printf("Input the 2nd number: \t");	
	scanf(" %f", &number2);
	printf("Choose an operation ( + | - | * | / ): \t");
	operation = getche();
	
	
	//Processing
	//switch option:
	switch(operation) {
		case '+':
			result = number1 + number2;
			break;
		case '-':
			result = number1 - number2;
			break;
		case '*':
			result = number1 * number2;
			break;
		case '/':
			result = number1 / number2;
			break;
		default:
			valid = false;
			printf("\nERROR: Invalid Input");
	}
	
	/*//if-else chain option:
	if (operation == '+')
		result = number1 + number2;
	else if (operation == '-')
		result = number1 - number2;
	else if (operation == '*')
		result = number1 * number2;
	else if (operation == '/')
		result = number1 / number2;
	else {
		valid = false;
		printf("\nERROR: Invalid Input");
	}
	*/
	
	//Getting the number's precision up to 5
	if (valid) {
		precision = 0;
		resultMulti = result;
		for (int i = 1; i <= 5; i++) {
			if (fmod(resultMulti, 1) != 0)
				precision++;
			else
				break;
			resultMulti *= 10;
		}
	
	//Data output
	printf("\n------------------------\n\nResult: %.*f", precision, result);
	}
	
	return 0;
}
