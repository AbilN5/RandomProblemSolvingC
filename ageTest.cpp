#include <stdio.h>

int age;

int main() {
	
	//Data input
	printf("Input your age: ");
	scanf("%i", &age);
	
	while (age < 0) {
		printf("ERROR: Invalid input\nInput your age: ");
		scanf("%i", &age);
	}
	
	//Data output
	printf("\nAge: %i\n--------------------\n", age);
	
	if (age >= 16)
		printf("Able to vote\n");
	else if (age < 5)
		printf("How are you even using this?\n");
	if (age >= 18)
		printf("Able to drive\n");
	if (age >= 100)
		printf("Seems like you are pretty old, huh? Please contact me and tell me your secrets");
	
	return 0;
}
