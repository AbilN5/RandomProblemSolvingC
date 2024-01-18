#include <stdio.h>

float monthlyRevenue, currentPrice;

int main() {
	
	//Data input
	printf("Input the monthly revenue: ");
	scanf("%f", &monthlyRevenue);
	printf("Input the current price of the product: ");
	scanf(" %f", &currentPrice);
	
	//Processing
	if ((monthlyRevenue < 500) && (currentPrice < 30)) {
		currentPrice += (currentPrice*.1);
	} else if (((monthlyRevenue >= 500) && (monthlyRevenue < 1200)) && ((currentPrice >= 30) && (currentPrice < 80))) {
		currentPrice += (currentPrice*.15);
	} else if ((monthlyRevenue >= 1200) && (currentPrice <= 80)){
		currentPrice -= (currentPrice*.2);
	}
	
	//Data output
	printf("\n----------------------\nReadjusted value: $ %.2f", currentPrice);
	
	return 0;
}
