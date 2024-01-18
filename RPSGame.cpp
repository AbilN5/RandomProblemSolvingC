#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

int finalPointsPlayer, finalPointsCPU, pointsPlayer, pointsCPU;  
char pointsDisplay[4], answerPlayer, answerCPU, continueChoice;

#define ROUNDS 3

int main() {
	//Initialization
	srand(time(NULL));
	pointsPlayer = pointsCPU = finalPointsPlayer = finalPointsCPU = 0;
	
	//Presentation
	printf("Welcome to ROCK/PAPER/SCISSORS game\n");
	
	do {
		//Game rounds
		int i;
		for (i = 1; i <= ROUNDS; i++) {
			
			//Cpu input
			answerCPU = rand() % 3 + 1;
			
			//Player input
			printf("\n\n-----------Round %i------------\n[R] ROCK | [P] PAPER | [S] SCISSORS\nChoice: ", i);
			answerPlayer = 0;
			answerPlayer = toupper(getche());
			while ((answerPlayer != 'R') && (answerPlayer != 'P') && (answerPlayer != 'S')) {
				printf("\nERROR: Invalid Input\nChoice: ");
				answerPlayer = toupper(getche());
			}
			
			//Char to number conversion
			if (answerPlayer == 'R') {
				answerPlayer = 1;
			} else if (answerPlayer == 'P'){
				answerPlayer = 2;
			} else {
				answerPlayer = 3;
			}
			
			//Print result
			printf("\n(PLAYER) ");
			switch (answerPlayer) {
				case 1:
					printf("ROCK ");
					break;
				case 2:
					printf("PAPER ");
					break;
				case 3:
					printf("SCISSORS ");
			}
			printf("X");
			switch (answerCPU) {
				case 1:
					printf(" ROCK ");
					break;
				case 2:
					printf(" PAPER ");
					break;
				case 3:
					printf(" SCISSORS ");
			}
			printf("(CPU)");
			
			//Calculate result
			if (answerPlayer == answerCPU) {
				printf(" DRAW");
				pointsDisplay[i - 1] = '-';
			} else if ((answerPlayer % 3 + 1) == answerCPU) {
				printf(" LOSS");
				pointsCPU += 1;
				pointsDisplay[i - 1] = 'X';
			} else {
				printf(" WIN");
				pointsPlayer += 1;
				pointsDisplay[i - 1] = 'O';
			}
		}
		//String finalization
		pointsDisplay[i] = '\0';
		
		//Output Results
		printf("\n\n\t%s\n-----------------------------\n", pointsDisplay);
		
		if (pointsPlayer == pointsCPU) {
			printf("That's a tie. Nice game!");
		} else if (pointsPlayer > pointsCPU) {
			printf("Congratulations, you've won!");
			finalPointsPlayer++;
		} else {
			printf("You've lost... More luck next time!");
			finalPointsCPU++;
		}
		
		pointsPlayer = pointsCPU = 0;
		
		printf("\n\nWant to play another time? <Y|N> ");
		continueChoice = toupper(getche());
		while ((continueChoice != 'N') && (continueChoice != 'Y')) {
			printf("\nERROR: Invalid input\nWant to play another time? <Y|N> ");
			continueChoice = toupper(getche());
		}
		
	} while (continueChoice != 'N');
	
	//Scoreboard output
	printf("\n\n\tSCOREBOARD\n-----------------------------\n(Player) %i X %i (CPU)\n-----------------------------\n", finalPointsPlayer, finalPointsCPU);
	if (finalPointsPlayer == finalPointsCPU) {
			printf("That's a DEFINITIVE tie. Nice game!");
		} else if (finalPointsPlayer > finalPointsCPU) {
			printf("Congratulations, you've DEFINITELY won!");
		} else {
			printf("You've DEFINITELY lost... More luck next time!");
		}
		
		if ((finalPointsPlayer >= 1000) && (finalPointsCPU == 0)) {
			printf("\n\nHey cheater, how do you feel doing that? That's a chance of 1 in ~1e300 (or smaller, depending how much you cheated after 1000 consecutive victories, which I'm not counting)");
		}
	return 0;
}
