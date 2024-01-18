#include <stdio.h>
#include <conio.h>
#include <ctype.h>

enum gender {
	MALE,
	FEMALE,
	OTHER,
	UNDEFINED = -1
};

const char *genderIdentifiers[] = {
	"MALE",
	"FEMALE",
	"OTHER",
	"UNDEFINED"
};

enum variable {
	QUANTITY,
	HEIGHT
};

float people[3][2], averageHeight; 
int height, i, j, counter, invalidCounter;  
char name[30], garbage[100], continueChoice, gender;

void readinput(void* inputVariable, const char* inputMessage, const char* dataTypeFormatted)  //[variable to receive value], [message], [%d, %c, or %s]

int main() {
	//Data initialization
	for (i = 0; i < sizeof(people)/sizeof(people[0]); i++) {
		for (j = 0; j < sizeof(people[i])/sizeof(people[i][0]); j++) {
			people[i][j] = 0;
		} 
	}
	i = j = 0;
	counter = 1;	
	
	printf("Input data according to dataset and decide when to stop\n----------------------------------\n");
	
	do {
		//Data input
		printf("|Person %i|\n\n", counter);
		
		readinput(name, "Name: ", "%s");
		
		readinput(&gender, "Gender: <[M] for Male | [F] for Female | [O] for Other> ", "%c");
		while ((gender != 'M') && (gender != 'F') && (gender != 'O')) {
			printf("Error: Invalid input\n");
			readinput(&gender, "Gender: <[M] for Male | [F] for Female | [O] for Other> ", "%c");
		}
		
		readinput(&height, "Height (cm): ", "%d");
		
		
		//Processing
		enum gender currentGender = UNDEFINED;
		switch (gender) {
			case 'M':
				currentGender = MALE; 
				break;
			case 'F':
				currentGender = FEMALE;
				break;
			case 'O':
				currentGender = OTHER;
				break;
		}
		
		people[currentGender][QUANTITY]++;
		people[currentGender][HEIGHT] += height;
		
		//Decide if user wants to continue
		printf("\nDo you want to continue? <Y|N> ");
		continueChoice = toupper(getche());
		while ((continueChoice != 'Y') && (continueChoice != 'N')) {
			printf("\nERROR: Invalid input\nDo you want to continue? <Y|N> ");
			continueChoice = toupper(getche());	
		}
		
		counter++;
		printf("\n----------------------------------\n");
	} while (continueChoice != 'N');
	counter--; //Adjustment to avoid counting more than the inputted participants
	
	//Data output
	for (i = 0; i < 3; i++) {
		printf("|%s|\n", genderIdentifiers[i]);
		if (people[i][QUANTITY] > 0) {
		averageHeight = (float) people[i][HEIGHT]/people[i][QUANTITY];
		} else {
			averageHeight = 0;
		}
		printf("Quantity           : %.0f\n", people[i][QUANTITY]);
		printf("Average height     : %.1f cm\n", averageHeight);
		printf("----------------------------------\n");
	}
	
	return 0;
}

void readinput(void* inputVariable, const char* inputMessage, const char* dataTypeFormatted) {
	while(1) {
		printf(inputMessage);
		if (dataTypeFormatted == "%d") {
			if (scanf(dataTypeFormatted, (double *)inputVariable) == 1) {
				int c;
				while ((c = getchar()) != '\n' && c != EOF);
				break;
			} else {
				scanf("%s", garbage);
				printf("ERROR: Invalid input\n");	
			}		
		} else if (dataTypeFormatted == "%s") {
			fgets((char*)inputVariable, sizeof(inputVariable), stdin);
			break;
		} else if (dataTypeFormatted == "%c") {
			*(char*)inputVariable = toupper(getche());
			printf("\n");
			break;
		} else {
			printf("\nPROGRAM FAILURE: SYNTAX ERROR ON dataTypeFormatted");
			break;
		}
	}
}	
	
