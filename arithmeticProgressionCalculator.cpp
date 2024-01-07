#include <stdio.h>

int commomDifference;
int initialTerm;
int numberTerms;
int lastTerm;
int sumProgression;

int main() {
		
	//Data input
	printf("ARITHMETIC PROGRESSION CALCULATOR\n-------------------------------\n");
	
	printf("Input the initial term of the progression: ");
	scanf("%i", &initialTerm);
	printf("Input the commom difference (number summed up each progression): ");
	scanf("%i", &commomDifference);
	printf("Input the number of terms: ");
	scanf("%i", &numberTerms);
	
	//Processing and Output
	int lastTerm = initialTerm + commomDifference*(numberTerms-1);
	int sumProgression = (initialTerm+lastTerm)*numberTerms/2;
	
	printf("\nThe last term of the progreesion is %i\nThe sum of all terms of the progression is %i", lastTerm, sumProgression);
			
	return 0;
}
