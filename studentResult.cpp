#include <stdio.h>

float n1, n2, ma;

int main() {
	
	//Data input
	printf("Input the test grades for test 1 and test 2: ");
	scanf("%f %f", &n1, &n2);
	
	//Processing
	ma = (n1 + n2)/2;
	
	//Data output
	if (ma >= 7)
		printf("Student APPROVED");
	else if (ma < 3)
		printf("Student REPROVED");
	else 
		printf("Student IN EXAM");	
	
	return 0;
}
