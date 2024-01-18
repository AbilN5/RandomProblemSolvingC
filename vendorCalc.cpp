#include <stdio.h>
#include <string.h>

char vendorID[13], vendorName[21];
float baseSalary, monthSells, comission, comissionPercentage, totalSalary;

int main() {
	
	//Data input
	printf("Input vendor's name: ");
	gets(vendorName);
	printf("Input vendor's ID: ");
	scanf("%s", vendorID);
	printf("Input vendor's fixed salary: ");
	scanf(" %f", &baseSalary);
	while (baseSalary < 0) {
		printf("ERROR: Invalid input\nInput vendor's fixed salary: ");
		scanf(" %f", &baseSalary);
	}
	printf("Input vendor's revenue: ");
	scanf(" %f", &monthSells);
	
	//Processing
	if (monthSells <= 500) {
		comissionPercentage = .025;
	} else {
		comissionPercentage = .04;
	}
	comission = monthSells*comissionPercentage;
	totalSalary = baseSalary + comission;
	
	//Data output
	printf("\n-----------------------------\nVendor's name:\t\t\t|  %s\nVendor's ID: \t\t\t|%s\nVendor's revenue: \t\t|$ %.2f\nVendor's fixed salary: \t\t|$ %.2f\nVendor's comission: \t\t|$ %.2f\nVendor's final salary: \t\t|$ %.2f", vendorName, vendorID, monthSells, baseSalary, comission, totalSalary);
	
	return 0;
}


