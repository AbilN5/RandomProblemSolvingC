#include <stdio.h>

int hoursWorked;
float hoursValue;
float discountPercentage;
float totalDiscount;
float bruteSalary;
float liquidSalary;

int main() {
		
	//Data input
	printf("SALARY PROCESSING\n--------------------------\n");
	
	printf("Input hour value: ");
	scanf("%f", &hoursValue);
	while (hoursValue < 0) {
		printf("ERROR - Input a positive value for hour value: ");
		scanf("%f", &hoursValue);	
	}
	
	printf("Input total hours worked: ");
	scanf("%i", &hoursWorked);
	while (hoursWorked < 0) {
		printf("ERROR - Input a positive value for hours worked: ");
		scanf("%i", &hoursWorked);	
	}
	
	printf("Input discount percentage: ");
	scanf("%f", &discountPercentage);
	while ((discountPercentage < 0) || (discountPercentage > 100)) {
		printf("ERROR - Input a valid percentage: ");
		scanf("%f", &discountPercentage);	
	}
	
	//Processing
	bruteSalary = hoursWorked*hoursValue;
	totalDiscount = bruteSalary*discountPercentage/100;
	liquidSalary = bruteSalary - totalDiscount;
	
	//Data output
	printf("--------SALARY PROCESSED--------\n");
	printf("Brute Salary: %f\n", bruteSalary);
	printf("Total Discount: %f\n", totalDiscount);
	printf("Liquid Salary: %f", liquidSalary);
	
	return 0;
}
