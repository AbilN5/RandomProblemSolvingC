#include <stdio.h>
#include <conio.h>

char letter;

int main() {
	
	//Data input
	printf("Input a character: ");
	letter = getche();
	
	//Data output
	
	switch(letter) {
		case 'a': case 'e': case 'i': case 'o': case 'u':
			printf("\nVowel");
			break;
		default:
			printf("\nNot a vowel");
	}
	
	return 0;
}
