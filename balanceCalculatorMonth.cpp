#include <stdio.h>

#define DAYS 30

float profit[DAYS][2], balance;
char garbage[100];

enum balanceChange {
	CREDIT,
	DEBIT
};

int main() {
	//Initialization
	balance = 0;
	
	//Data input
	printf("Balance Calculator\n(!) Input daily earnings and expenses of the month as positive real numbers");
	
	for (int i = 0; i < DAYS; i++) {		//days
		printf("\n\nDay %i\n----------------------------", i+1);
		for (int j = 0; j < 2; j++) {		//earnings/expenses
			
			switch (j) {	//j loop is not necessary, but it gives room for improvement in the case an instruction depends on balance change instance, but happens on them all
				case CREDIT:
					//error handling (a function could be made, but it takes some time, which i don't want to spend on this program)
					while (1) {
						printf("\nEarnings: ");
						if (scanf(" %f", &profit[i][CREDIT]) != 1) {
							scanf("%s", garbage);
							printf("\nERROR: Invalid input");
							continue; //skips break;, repeating the loop
						} else if (profit[i][CREDIT] < 0) {
							printf("\nERROR: Invalid input");
							continue; 
						}
						break;
					}
					break;
				case DEBIT:
					while (1) {
						printf("\nExpenses: ");
						if (scanf(" %f", &profit[i][DEBIT]) != 1) {
							scanf("%s", garbage);
							printf("\nERROR: Invalid input");
							continue;
						} else if (profit[i][DEBIT] < 0) {
							printf("\nERROR: Invalid input");
							continue;
						}
						break;
					}
					break;
			} //switch end
		} //inner loop end
		balance += profit[i][CREDIT] - profit[i][DEBIT];
	} //outer loop end
	
	//Data ouput
	printf("\n-------------------------------------\n");
	printf("Current balance: $ %.2f", balance);
	
	return 0;
}

