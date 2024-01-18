#include <stdio.h>

int age;

int main() {
	
	//Data input
	printf("Input the age of the swimmer: ");
	scanf("%i", &age);
	
	while (age < 0) {
		printf("ERROR: Invalid input\nInput the age of the swimmer: ");
		scanf("%i", &age);
	}
	
	//Data output
	
	printf("\n--------------------------------\n");
	if (age < 5) {
		printf("Enrolled inapt to be a participant");
	} else if (age < 8) {
		printf("Infantile A swimmer");
	} else if (age < 11) {
		printf("Infantile B swimmer");
	} else if (age < 14) {
		printf("Juvenile A swimmer");
	} else if (age < 18) {
		printf("Juvenile B swimmer");
	} else {
		printf("Adult swimmer");
	}
	
	return 0;
}
