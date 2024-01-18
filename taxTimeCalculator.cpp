#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float salaryInitial, salaryCurrent, salaryFinal, salaryFinalPercentage, changePercentage;
char garbage[100];

void inputfloat(float* inputVariable, const char* message); 

int main() {
	
	//Data input	
	inputfloat(&salaryInitial, "Input initial salary: ");
	
	inputfloat(&salaryFinalPercentage, "Input final salary as percentage of initial salary (without %% symbol): ");
	while (salaryFinalPercentage < 0.0) {
		printf("ERROR: Invalid input\n");
		inputfloat(&salaryFinalPercentage, "Input final salary as percentage of initial salary (without %% symbol): ");
	}
	
	inputfloat(&changePercentage, "Input the addition/reduction percentage (without %% symbol | positive for addition, negative for reduction): ");
	while ((changePercentage == 0.0) || (changePercentage < -100.0) || ((((100.0 - salaryFinalPercentage)*-1.0)/changePercentage) < 0.0)) {
		printf("ERROR: Invalid input\n");
		inputfloat(&changePercentage, "Input the addition/reduction percentage (without %% symbol | positive for addition, negative for reduction): ");
	}
	
	//Processing
	salaryFinalPercentage /= 100.0;
	changePercentage /= 100.0;
	salaryFinal = salaryInitial*salaryFinalPercentage;
	salaryCurrent = salaryInitial;
	
	//Data output and processing
	printf("\n--------------------------------\n|Initial Period|\n");
	printf("Current salary:\t$ %.2f\n", salaryCurrent);
	printf("Goal          :\t$ %.2f\n", salaryFinal);
	
	int counter = 1;
	while (fabs(salaryFinal - salaryInitial) > fabs(salaryCurrent -salaryInitial)) {
		salaryCurrent *= 1.0 + changePercentage;
		
		printf("--------------------------------\n|Period %i|\n", counter);
		printf("Current salary:\t$ %.2f\n", salaryCurrent);
		printf("Goal          :\t$ %.2f\n", salaryFinal);
		counter++;
	}
	
	return 0;
}

void inputfloat(float* inputVariable, const char* message) {
	printf(message);
	while (scanf("%f", inputVariable) != 1) {
		scanf("%s", garbage);
		printf("ERROR: Invalid input\n%s", message);
	}
	{
		int c;
		while (((c = getchar()) != '\n') && (c != EOF)) { }
	}
}

