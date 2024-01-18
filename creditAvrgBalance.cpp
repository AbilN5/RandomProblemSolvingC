#include <stdio.h>

float averageBalance, creditPercentage, credit;

int main() {
	
	//Data input
	printf("Input the client's average balance: ");
	scanf("%f", &averageBalance);
	
	//Processing
	if (averageBalance <= 200) {
		creditPercentage = 0;
	} else if (averageBalance <= 400) {
		creditPercentage = .2;	
	} else if (averageBalance <= 600) {
		creditPercentage = .3;
	} else {
		creditPercentage = .4;
	}
	credit = averageBalance*creditPercentage;
	
	//Data output
	if (credit != 0) {
		printf("\nClient is able to receive $ %.2f credit based on average balance of $ %.2f", credit, averageBalance);
	} else {
		printf("\nClient is not able to receive credit");
	}
		
	return 0;
}
