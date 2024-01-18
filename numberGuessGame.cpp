#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int number, numberAnswer;

#define MAX_NUMBER 10
#define MIN_NUMBER 1
#define MAX_ATTEMPTS 3

int main() {
	
	srand(time(NULL));
	number = rand() % (MAX_NUMBER - MIN_NUMBER + 1) + MIN_NUMBER;
	
	printf("I just thought a number between 1 and 10, can you guess it right?\n");
	for (int i = 1; i <= MAX_ATTEMPTS; i++) {
		printf("Try number %i: ", i);
		scanf(" %i", &numberAnswer);
		if (numberAnswer == number) {
			printf("Congratulations! You guessed it right on try number %i", i);
			break;
		} else {
			if (i < MAX_ATTEMPTS) {
				if (number < numberAnswer) {
					printf("I thought a lower number... Good luck on next try\n");
				} else {
					printf("I thought a higher number... Good luck on next try!\n");
				}
			} else {
				printf("Seems like you couldn't guess the number I thought. It is %i", number);
			}
		}
	}
	
	
	return 0;
}
