#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char encryptedMessage[201];
char decryptedMessage[201];
char outputMessage[201];
char modeChoice;
char restart;
int shiftJump;

void WriteScreen(char message[]);
void ClearScreen();
void MessageProcessing(char inputMessage[], char outputMessage[], int jump);
void ClearInputBuffer();

int main() {

	do {
		restart = '\0';
			
		//Instructions input
		WriteScreen("Write [E] if you want to ENCRYPT your message\nWrite [D] if you want to DECRYPT your message");
		scanf("%c", &modeChoice);
		ClearInputBuffer();
		modeChoice = toupper(modeChoice);
		
		while ((modeChoice != 'E') && (modeChoice != 'D')) {
			WriteScreen("ERROR: Invalid Input\nWrite [E] if you want to ENCRYPT your message\nWrite [D] if you want to DECRYPT your message");
			scanf("%c", &modeChoice);
			ClearInputBuffer();
			modeChoice = toupper(modeChoice);
		}
		
		WriteScreen("Input the shift jump of the message (max: 93 | min: 1)");
		scanf("%i", &shiftJump);
		ClearInputBuffer();
		
		while ((shiftJump > 93) || (shiftJump < 1)) {
			WriteScreen("ERROR: Invalid Input\nInput the shift jump of the message (max: 93 | min: 1)");
			scanf("%i", &shiftJump);
			ClearInputBuffer();
		}
		
		WriteScreen("Write the message to be processed (200 characters)");
		if (modeChoice == 'E') {
			fgets(decryptedMessage, sizeof(decryptedMessage), stdin);
			if ((strlen(decryptedMessage) > 0) && (decryptedMessage[strlen(decryptedMessage) - 1] == '\n')) {
				decryptedMessage[strlen(decryptedMessage) - 1] = '\0';
			}
	 	} else {
	 		fgets(encryptedMessage, sizeof(encryptedMessage), stdin);
			if ((strlen(encryptedMessage) > 0) && (encryptedMessage[strlen(encryptedMessage) - 1] == '\n')) {
				encryptedMessage[strlen(encryptedMessage) - 1] = '\0';
			}
		}
		ClearInputBuffer();
		
		//processing
		if (modeChoice == 'E') {
			MessageProcessing(decryptedMessage, encryptedMessage, shiftJump);
		} else {
			MessageProcessing(encryptedMessage, decryptedMessage, -shiftJump);
		}
		
		//output
		if (modeChoice == 'E') {
			WriteScreen("The input message was successfuly encrypted:\nDo you want to process another message? [Y/N]");
			printf("%s\n---------------------------------------------------------\n", encryptedMessage);
		} else {
			WriteScreen("The input message was successfuly decrypted:\nDo you want to process another message? [Y/N]");
			printf("%s\n---------------------------------------------------------\n", decryptedMessage);
		}
		
		//restart
		scanf("%c", &restart);
		ClearInputBuffer();
		restart = toupper(restart);
		
		while ((restart != 'Y') && (restart != 'N')) {
			WriteScreen("ERROR: Invalid Input\nPress [Y] if you want to process another message or [N] if you want to exit");
			scanf("%c", &restart);
			ClearInputBuffer();
			restart = toupper(restart);
		}
	} while (restart == 'Y');
	
	return 0;
}

void WriteScreen(char message[]) {
	ClearScreen();
	printf("CAESAR CIPHER ENCRYPTING/DECRYPTING ALGORITHM\n\n");
	printf("%s \n", message);
	printf("---------------------------------------------------------\n");	
}

void ClearScreen() {
	system("cls");
}

void MessageProcessing(char inputMessage[], char outputMessage[], int jump) {
	int asciiValue;
	int i;
	for	(i=0; inputMessage[i] != '\0'; i++) {
		asciiValue = inputMessage[i];
		if ((asciiValue > 32) && (asciiValue < 127)) {
			asciiValue = (asciiValue - 33 + jump) % 94;
			if (asciiValue < 0) {
				asciiValue = 94 + asciiValue;
			}
			asciiValue += 33;
			outputMessage[i] = asciiValue;
		} else {
			outputMessage[i] = asciiValue;
		}
	}
	outputMessage[i] = '\0';
}

void ClearInputBuffer() {
	int c;
	while ((c = getchar()) != '\n' && c != EOF) { }
}
