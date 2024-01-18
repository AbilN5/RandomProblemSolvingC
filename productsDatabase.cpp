#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>

//Macros declaration
#define PRODUCT_CODE_SIZE 5 //must have 1 more space, for '\0'
#define PRODUCT_NAME_MAX 31	//must have 1 more space, for '\0'
#define MAX_TRIES_REALLOC 100 
#define PRODUCTS_PER_PAGE 10

//Constants declaration


//Global variables declaration
int productsQuantity = 0;

//Enums declaration
enum menuChoices {
	EXIT = '0',
	ADD = '1',
	EDIT = '2',
	EXCLUDE = '3',
	PRINT = '4'
};

enum memberChangeChoices {
	BACK = '0',
	CODE = '1',
	NAME = '2',
	COST = '3',
	SELL = '4',
	STOCK = '5'
};

enum actionPrintChoices {
	MENU = '0',
	PREVIOUS = '1',
	NEXT = '2'
};

//Heterogeneous data structures

struct products {
	char code[PRODUCT_CODE_SIZE];
	char name[PRODUCT_NAME_MAX];
	float valueCost;
	float valueSell;
	int stock; 
};

//Functions prototyping

	//Utility functions
	void readInput(char dataTypeChar, const char* message, void* inputVariable, size_t stringSize);
	void clearInputBuffer();	
	void clearScreen();
	void positionSwapperProducts(products* array, int initialPos, int finalPos);
	void toProductsNull(products* productFirstPos, products nullProduct, int initialPos, int finalPos);
	void addProduct(products* productOnPosition, int position);
		//Product members input
		void inputCode (products* productOnPosition, int position);
		void inputName (products* productOnPosition, int position);
		void inputCost (products* productOnPosition);
		void inputSell (products* productOnPosition);
		void inputStock (products* productOnPosition);
	void printProduct(products* productPointer, int position);
	void findProduct(bool* productFound, int* ptrPosition, const char* headerMessage, products* currentProducts);
	
	//Test functions
	void readInputTest();
	void positionSwapperProductsTest();

//Program execution
int main() {
	//Initialization
	size_t productsTypeSize = sizeof(struct products);
	products nullProductTemplate;
	nullProductTemplate.code[0] = '\0';
	nullProductTemplate.name[0] = '\0';
	nullProductTemplate.valueCost = 0;
	nullProductTemplate.valueSell = 0;
	nullProductTemplate.stock = 0;
	
	fprintf(stdout, "DATABASE initialization...\n");
	
	readInput('i', "\nInput the number of products to be inputted: ", &productsQuantity, 0);
	while (productsQuantity <= 0) {
		fprintf(stderr, "\nERROR 105: Invalid input\nExpected input: positive integer\n");
		readInput('i', "\nInput the number of products to be inputted: ", &productsQuantity, 0);
	}
	
	products* currentProducts = (products*) malloc(productsTypeSize * productsQuantity);
	while (currentProducts == NULL) {
		char tryAgainChoice = '\0';
		fprintf(stderr, "\nERROR 201: Memory allocation failed");
		
		readInput('c', "\nWant to try again? <Y|N> ", &tryAgainChoice, 0);
		while (tryAgainChoice != 'Y' && tryAgainChoice != 'N') {
			fprintf(stderr, "\nERROR 106: Invalid input\nExpected input: Y, N\n");
			readInput('c', "\nWant to try again? <Y|N> ", &tryAgainChoice, 0);
		}
		
		if (tryAgainChoice == 'N') {
			return 1;
		}
		
		currentProducts = (products*) malloc(productsTypeSize*productsQuantity);
	}
	clearScreen();
	
	fprintf(stdout, "DATABASE initialization...\n");
	fprintf(stdout, "Memory allocation was successful!\n\n");
	
	toProductsNull(currentProducts, nullProductTemplate, 0, productsQuantity - 1);
	for (int i = 0; i < productsQuantity; i++) {
		fprintf(stdout, "|Product number %i|\n", i+1);
		addProduct(&currentProducts[i], i);
		fprintf(stdout, "\n");
	}
	
	//Database menu
	bool productFound;
	int position;
	char choice = '\0';
	while (choice != EXIT) {
		clearScreen();
		fprintf(stdout, "PRODUCTS DATABASE | MENU\n-------------------------------------\n");	
		fprintf(stdout, "Choose an action:\n\n");
		fprintf(stdout, "[0]Exit Program\n");
		fprintf(stdout, "[1]Add Product\n");
		fprintf(stdout, "[2]Change Product\n");
		fprintf(stdout, "[3]Exclude Product\n");
		fprintf(stdout, "[4]Print Products Information\n");
		
		readInput('c', "", &choice, 0);
		while (choice != EXIT && choice != ADD && choice != EDIT && choice != EXCLUDE && choice != PRINT) {
			fprintf(stderr, "\nERROR 106: Invalid input\nExpected input: 0, 1, 2, 3, 4\n");
			readInput('c', "", &choice, 0);
		}
		
		switch(choice) {
			case EXIT:
			break;
			case ADD:
			//Add product
				//variable declaration - compiler doesn't allow direct assignment of values to variables inside switch
				char tryAgain;
				products* addedProducts;
				int addQuantity;
				
				//variable initialization
				tryAgain = 'Y';
				addedProducts = NULL;
				addQuantity = 0;
				
				clearScreen();
				fprintf(stdout, "PRODUCTS DATABASE | ADD\n-------------------------------------\n");
				
				//input quantity to be added
				readInput('i', "\nInput the number of products to be added: ", &addQuantity, 0);
				while (addQuantity <= 0) {
					fprintf(stderr, "\nERROR 105: Invalid input\nExpected input: positive integer\n");
					readInput('i', "\nInput the number of products to be added: ", &addQuantity, 0);
				}
				
				//resize products array
				productsQuantity += addQuantity;
				addedProducts = (products*) realloc(currentProducts, productsTypeSize*productsQuantity);
					
				//check if realocation was sucessful
				while (addedProducts == NULL && tryAgain == 'Y') {
					fprintf(stderr, "\nERROR 201: Memory allocation failed\n");
					readInput('c', "\nWant to try again? <Y|N> ", &tryAgain, 0);
					while (tryAgain != 'Y' && tryAgain != 'N') {
						fprintf(stderr, "\nERROR 106: Invalid input\nExpected input: Y, N\n");
						readInput('c', "\nWant to try again? <Y|N> ", &tryAgain, 0);
					}
					
					if (tryAgain == 'Y') {
						addedProducts = (products*) realloc(currentProducts,productsTypeSize*productsQuantity);
					}
				}
				
				//memory freeing and variables correction
				if (tryAgain == 'N') {
					productsQuantity -= addQuantity;
					break;
				} else {
					currentProducts = addedProducts;
					addedProducts = NULL;
				}
				
				//product addition
				clearScreen();
				fprintf(stdout, "PRODUCTS DATABASE | ADD\n-------------------------------------\n");
				toProductsNull(currentProducts, nullProductTemplate, productsQuantity - addQuantity, productsQuantity - 1);
				for (int i = productsQuantity - addQuantity; i < productsQuantity; i++) {
					fprintf(stdout, "|Added Product Number %i|\n", i - productsQuantity + addQuantity + 1);
					addProduct(&currentProducts[i], i);
				}
				
			break;
			case EDIT:
			//Change products' members
				//variables declaration
				char memberEditChoice;
				
				//variables initialization
				memberEditChoice = '\0';
				productFound = false;
				
				//find product to edit 
				findProduct(&productFound, &position, "PRODUCTS DATABASE | EDIT", currentProducts);
				
				
				//User didn't want to input a new code after it was not found
				if (!productFound) {
					break;
				}
				
				//Product corresponding to inputted code was found - choose what member to change
				while (memberEditChoice != '0') {
					clearScreen();
					fprintf(stdout, "PRODUCTS DATABASE | EDIT\n-------------------------------------\n");
					
					//print product
					printProduct(currentProducts, position);
					
					//print actions
					fprintf(stdout, "Choose an action: \n");
					fprintf(stdout, "[0] Go back to menu\n");
					fprintf(stdout, "[1] Edit code\n");
					fprintf(stdout, "[2] Edit name\n");
					fprintf(stdout, "[3] Edit cost value\n");
					fprintf(stdout, "[4] Edit sell value\n");
					fprintf(stdout, "[5] Edit stock available\n");
					
					//read choice
					readInput('c', "", &memberEditChoice,0);
					while (memberEditChoice != BACK && memberEditChoice != CODE && memberEditChoice != NAME && memberEditChoice != COST && memberEditChoice != SELL && memberEditChoice != STOCK) {
						fprintf(stderr, "\nERROR 106: Invalid input\nExpectedInput: 0, 1, 2, 3, 4, 5\n");
						readInput('c', "", &memberEditChoice,0);
					}
					
					switch(memberEditChoice) {
						case CODE: 
							inputCode ((currentProducts + position), position);
						break;
						case NAME:	
							inputName ((currentProducts + position), position);
						break;
						case COST:
							inputCost (currentProducts + position);
						break;
						case SELL:	
							inputSell (currentProducts + position);
						break;	
						case STOCK:	
							inputStock (currentProducts + position);
						break;		
					}
				}
				
			break;
			case EXCLUDE:
			//Exclude products
				//variables declaration
				char excludeConfirmation;
				
				//variables initialization
				productFound = false;
				position = 0;
				
				//find product to exclude
				findProduct(&productFound, &position, "PRODUCTS DATABASE | EXCLUDE", currentProducts);
				
				//user didn't want to input a new code after it was not found
				if (!productFound) {
					break;
				}
				
				//product corresponding to inputted code was found - request confirmation
				clearScreen();
				fprintf(stdout, "PRODUCTS DATABASE | EXCLUDE\n-------------------------------------\n");
				readInput('c', "Are you sure you want to do this? This process is not reversible... <Y|N> ", &excludeConfirmation, 0);
				while (excludeConfirmation != 'N' && excludeConfirmation != 'Y') {
					fprintf(stderr, "\nERROR 106: Invalid input\nExpected input: Y, N\n");
					readInput('c', "Are you sure you want to do this? This process is not reversible... <Y|N> ", &excludeConfirmation, 0);
				}
				
				//confirmation denied - exit exclude case
				if (excludeConfirmation == 'N') {
					break;
				}
				
				//confirmation provided - exclude product
				//move product to last position
				positionSwapperProducts(currentProducts, position, productsQuantity - 1);
				
				//resize products array
				productsQuantity--;
				products* excludedProducts;
				excludedProducts = (products*) realloc(currentProducts, productsTypeSize*productsQuantity);
				
				//check if reallocation was sucessful
				int tries;
				tries = 0;
				while (excludedProducts == NULL && tries < MAX_TRIES_REALLOC) {
					excludedProducts = (products*) realloc(currentProducts, productsTypeSize*productsQuantity);
					tries++;
				}
				
				//reallocation failed
				if (tries == 100 && excludedProducts == NULL) {
					toProductsNull(excludedProducts, nullProductTemplate, productsQuantity, productsQuantity);
					fprintf(stderr, "\nERROR 201: Memory allocation failed\nProduct excluded by nullification\n");
				} else {
					currentProducts = excludedProducts;
					excludedProducts = NULL;
					fprintf(stdout, "\nProduct excluded successfully\n");
				}
				
				//press anything to continue - used for user to be able to read the message
				char tempChar;
				readInput('c', "\nPress anything to continue", &tempChar, 0);
				
			break;
			case PRINT:
			//Print all products
				//variables declaration
				int totalPages;
				int pagesIndex;
				char actionPrintChoice;
				bool lastPage;
				bool firstPage;
				
				//variables initialization
				actionPrintChoice = '\0';
				totalPages = (productsQuantity / PRODUCTS_PER_PAGE) + 1;
				pagesIndex = 0;
				
				while (actionPrintChoice != MENU) {
					//print products
					clearScreen();
					fprintf(stdout, "PRODUCTS DATABASE | LIST\n-------------------------------------Page %i\n", pagesIndex + 1);
					for (int productsIndex = pagesIndex*PRODUCTS_PER_PAGE; productsIndex < (pagesIndex*PRODUCTS_PER_PAGE + PRODUCTS_PER_PAGE) && productsIndex < productsQuantity; productsIndex++) {
					printProduct(currentProducts, productsIndex);
					}
					
					//change page or go back to menu
					fprintf(stdout, "\n-------------------------------------\n");
					fprintf(stdout, "Choose an action: \n");
					
					fprintf(stdout, "[0] Go back to menu\n");
					
					if (pagesIndex > 0) {
						firstPage = false;
						fprintf(stdout, "[1] Previous page\n");
					} else {
						firstPage = true;
					}
					
					if (pagesIndex < totalPages - 1) {
						lastPage = false;
						fprintf(stdout, "[2] Next page\n");
					} else {
						lastPage = true;
					}
					
					//read input from user based on current page
					readInput('c', "", &actionPrintChoice, 0);
					if (!firstPage && !lastPage) {
						while (actionPrintChoice != MENU && actionPrintChoice != PREVIOUS && actionPrintChoice != NEXT) {
							fprintf(stderr, "\nERROR 106: Invalid input\nExpected input: 0, 1, 2\n");
							readInput('c', "", &actionPrintChoice, 0);
						}
					}
					if (firstPage && !lastPage) {
						while (actionPrintChoice != MENU && actionPrintChoice != NEXT) {
							fprintf(stderr, "\nERROR 106: Invalid input\nExpected input: 0, 2\n");
							readInput('c', "", &actionPrintChoice, 0);	
						}
					}
					if (!firstPage && lastPage) {
						while (actionPrintChoice != MENU && actionPrintChoice != PREVIOUS) {
							fprintf(stderr, "\nERROR 106: Invalid input\nExpected input: 0, 1\n");
							readInput('c', "", &actionPrintChoice, 0);	
						}
					}
					if (firstPage && lastPage) {
						while (actionPrintChoice != MENU) {
							fprintf(stderr, "\nERROR 106: Invalid input\nExpected input: 0\n");
							readInput('c', "", &actionPrintChoice, 0);
						}
					}
					
					//execute action
					if (actionPrintChoice == PREVIOUS) {
						pagesIndex--;
					}
					if (actionPrintChoice == NEXT) {
						pagesIndex++;
					}
					
				}
			break;
		}
	}
	
	
	
	//Finalization
	free(currentProducts);

	return 0;
}


//Utility functions
void readInput(char dataTypeChar, const char* message, void* inputVariable, size_t stringSize) { //pass 0 for stringSize if not a string 
	char garbage[100];
	
	switch(dataTypeChar) {
		case 'i':
			
			while (1) {
				fprintf(stdout, message);
				if (scanf(" %i", (int*) inputVariable) == 1) {
					clearInputBuffer();
					break;
				} else {
					fgets(garbage, sizeof(garbage)/sizeof(garbage[0]), stdin);
					fprintf(stderr, "\nERROR 101: Invalid input\nExpected input: integer number\n");
				}
			}
			
		break;
		case 'f':
			
			while (1) {
				fprintf(stdout, message);
				if (scanf(" %f", (float*) inputVariable) == 1) {
					clearInputBuffer();
					break;
				} else {
					fgets(garbage, sizeof(garbage)/sizeof(garbage[0]), stdin);
					fprintf(stderr, "\nERROR 102: Invalid input\nExpected input: real number\n");
				}
			}
			
		break;
		case 'e':
			
			while (1) {
				fprintf(stdout, message);
				if (scanf(" %lf", (double*) inputVariable) == 1) {
					clearInputBuffer();
					break;
				} else {
					fgets(garbage, sizeof(garbage)/sizeof(garbage[0]), stdin);
					fprintf(stderr, "\nERROR 103: Invalid input\nExpected input: real number\n");
				}
			}
			
		break;
		case 's':
			
			while (1) {
				fprintf(stdout, message);
				if (fgets((char*)inputVariable, stringSize, stdin) != NULL) {
					size_t lenght = strlen((char*)inputVariable);
					if (lenght > 0 && ((char*)inputVariable)[lenght - 1] == '\n') {
						((char*)inputVariable)[lenght - 1] = '\0';
					} else {
						clearInputBuffer();
					}
					break;	
				} else {
					fprintf(stderr, "\nERROR 104: Invalid input\nInput is too big or there is no input\n");
					clearInputBuffer();
				}
			}
			
		break;
		case 'c':
			
			fprintf(stdout, message);
			*(char*) inputVariable = toupper(getche());
			fprintf(stdout, "\n");
			
		break;
		default:
			fprintf(stderr, "\n\nERROR 001: WRONG SYNTAX ON readinput() USE");
		break;
	}	
}

void clearInputBuffer() {
	int c;
	while ((c = getchar()) != '\n' && c != EOF) { };
}

void clearScreen() {
	system("cls");
}

//Test functions
void readInputTest() {
	
	//Variable initialization
	int testStringSize = 20;
	
	int testInteger;
	float testFloat;
	double testDouble;
	char testString[testStringSize], testChar;
	
	//Data input
	fprintf(stdout, "readInput Test:\n");
	
	readInput('i', "\nInput an integer: ", &testInteger, 0);
	readInput('f', "\nInput a float   : ", &testFloat, 0);
	readInput('e', "\nInput a double  : ", &testDouble, 0);
	readInput('s', "\nInput a string  : ", testString, sizeof(testString)/sizeof(testString[0]));
	readInput('c', "\nInput a char    : ", &testChar, 0);
	
	//Data output
	fprintf(stdout, "\nResulted integer: %i", testInteger);
	fprintf(stdout, "\nResulted float  : %.3f", testFloat);
	fprintf(stdout, "\nResulted double : %e", testDouble);
	fprintf(stdout, "\nResulted string : %s", testString);
	fprintf(stdout, "\nResulted char   : %c\n", testChar);	
	
	//Data input	
	readInput('s', "\nInput a string  : ", testString, sizeof(testString)/sizeof(testString[0]));
	readInput('i', "\nInput an integer: ", &testInteger, 0);
	readInput('f', "\nInput a float   : ", &testFloat, 0);
	readInput('c', "\nInput a char    : ", &testChar, 0);
	readInput('e', "\nInput a double  : ", &testDouble, 0);
	
	//Data output
	fprintf(stdout, "\nResulted integer: %i", testInteger);
	fprintf(stdout, "\nResulted float  : %.3f", testFloat);
	fprintf(stdout, "\nResulted double : %e", testDouble);
	fprintf(stdout, "\nResulted string : %s", testString);
	fprintf(stdout, "\nResulted char   : %c\n", testChar);
	
	//Data input	
	readInput('s', "\nInput a string  : ", testString, sizeof(testString)/sizeof(testString[0]));
	readInput('i', "\nInput an integer: ", &testInteger, 0);
	readInput('f', "\nInput a float   : ", &testFloat, 0);
	readInput('c', "\nInput a char    : ", &testChar, 0);
	readInput('e', "\nInput a double  : ", &testDouble, 0);
	
	//Data output
	fprintf(stdout, "\nResulted integer: %i", testInteger);
	fprintf(stdout, "\nResulted float  : %.3f", testFloat);
	fprintf(stdout, "\nResulted double : %e", testDouble);
	fprintf(stdout, "\nResulted string : %s", testString);
	fprintf(stdout, "\nResulted char   : %c\n", testChar);
}

void positionSwapperProducts(products* array, int initialPos, int finalPos) {	//finalPos should always be last position, as this function is intended to be used when excluding a product
	
	products temp = array[initialPos];
	for (int i = initialPos; i < finalPos; i++) {
		array[i] = array[i+1];
	}
	array[finalPos] = temp; //this is intended to avoid garbage only
	
}

void positionSwapperProductsTest() {	//change data type of positionSwapper to int* to test it 
	/*
	
	//Data initialization
	int arraySize = 10;
	int testArray[arraySize];
	int posToSwap = 5;
	
	for (int i = 0; i < arraySize; i++) {
		testArray[i] = i;
	}
	
	//Data output and swapping
	fprintf(stdout, "Original array: ");
	for (int i = 0; i < arraySize; i++) {
		fprintf(stdout, "\nPosition[%i]: %i", i, testArray[i]);
	}
	
	positionSwapperProducts(testArray, posToSwap, arraySize - 1);
	
	fprintf(stdout, "\n\nSwapped array: ");
	for (int i = 0; i < arraySize; i++) {
		fprintf(stdout, "\nPosition[%i]: %i", i, testArray[i]);
	}
	
	*/
	
}

void toProductsNull(products* productFirstPos, products nullProduct, int initialPos, int finalPos) {
	for (int i = initialPos; i <= finalPos; i++) {
		productFirstPos[i] = nullProduct;
	}
}

void addProduct(products* productOnPosition, int position) {
	inputCode(productOnPosition, position);
	inputName(productOnPosition, position);
	inputCost(productOnPosition);
	inputSell(productOnPosition);
	inputStock(productOnPosition);
}

void inputCode(products* productOnPosition, int position) {

	bool isValidCode = false;
	do {
		readInput('s', "\nInput product code: ", productOnPosition->code, PRODUCT_CODE_SIZE);
		
		isValidCode = true;
		for (int i = 0; i < PRODUCT_CODE_SIZE - 1 && isValidCode; i++) {
			if (productOnPosition->code[i] == '\0') {
				isValidCode = false;
				fprintf(stderr, "\nERROR 107: Invalid input\nExpected input: %i characters", PRODUCT_CODE_SIZE - 1);
				continue;
			}
		}
		for (int i = position; i > position - productsQuantity && isValidCode; i--) {
			if (i == 0) {
				continue;
			}
			if (strcmp((productOnPosition - i)->code, productOnPosition->code) == 0) {
				isValidCode = false;
				fprintf(stderr, "\nERROR 108: Invalid input\nThis code is already registered for another product [%s]", (productOnPosition - i)->code);
				continue;
			}
		}
	} while (!isValidCode);

}

void inputName(products* productOnPosition, int position) {
	
	bool isValidName = false;
	do {
		readInput('s', "\nInput product name: ", productOnPosition->name, PRODUCT_NAME_MAX);
		
		isValidName = true;
		for (int i = position; i > position - productsQuantity && isValidName; i--) {
			if (i == 0) {
				continue;
			}
			char name[2][PRODUCT_NAME_MAX];
			strcpy(name[0], productOnPosition->name);
			strcpy(name[1], (productOnPosition - i)->name);
			
			for (int j = 0; j < 2; j++) {
				for (int k = 0; name[j][k] != '\0'; k++) {
					name[j][k] = toupper(name[j][k]);
				}
			}
			
			if (strcmp(name[0], name[1]) == 0) {
				isValidName = false;
				fprintf(stderr, "\nERROR 109: Invalid input\nThis name is already registered for another product [%s]", (productOnPosition - i)->name);
				continue;
			}
		}	
	} while (!isValidName); 

}

void inputCost(products* productOnPosition) {

	readInput('f', "\nInput product cost value: ", &productOnPosition->valueCost, 0);
	while (productOnPosition->valueCost <= 0.0) {
		fprintf(stderr, "\nERROR 110: Invalid input\nExpected input: positive number");
		readInput('f', "\nInput product cost value: ", &productOnPosition->valueCost, 0);
	}

}

void inputSell(products* productOnPosition)	{
	
	readInput('f', "\nInput product sell value: ", &productOnPosition->valueSell, 0);
	while (productOnPosition->valueSell <= 0.0) {
		fprintf(stderr, "\nERROR 110: Invalid input\nExpected input: positive number");
		readInput('f', "\nInput product sell value: ", &productOnPosition->valueSell, 0);
	}

}	

void inputStock(products* productOnPosition) {

	readInput('i', "\nInput product quantity in stock: ", &productOnPosition->stock, 0);
	while (productOnPosition->stock < 0) {
		fprintf(stderr, "\nERROR 105: Invalid input\nExpected input: positive integer");
		readInput('i', "\nInput product quantity in stock: ", &productOnPosition->stock, 0);
	}	

}	

void printProduct(products* productPointer, int position) {
	fprintf(stdout, "\n|Product: %s|\n-------------------------------------\n", productPointer[position].name);
	fprintf(stdout, "Code      \t: %s\n", productPointer[position].code);
	fprintf(stdout, "Name      \t: %s\n", productPointer[position].name);
	fprintf(stdout, "Cost Value\t: $ %14.2f\n", productPointer[position].valueCost);
	fprintf(stdout, "Sell Value\t: $ %14.2f\n", productPointer[position].valueSell);
	fprintf(stdout, "Stock     \t:   %11i\n", productPointer[position].stock);
	fprintf(stdout, "-------------------------------------\n\n");
}

void findProduct(bool* productFound, int* ptrPosition, const char* headerMessage, products* currentProducts) {
	char tryAgain;
	char productCode[PRODUCT_CODE_SIZE];
	bool isValidCode;
	
	//variables initialization
	tryAgain = 'Y';
	isValidCode = false;
	*productFound = false;
	
	while (!*productFound) {
		clearScreen();
		fprintf(stdout, "%s\n-------------------------------------\n", headerMessage);
		
		//input code of product to change
		do {
			readInput('s', "\nInput product code: ", productCode, PRODUCT_CODE_SIZE);
			
			isValidCode = true;
			for (int i = 0; i < PRODUCT_CODE_SIZE - 1 && isValidCode; i++) {
				if (productCode[i] == '\0') {
					isValidCode = false;
					fprintf(stderr, "\nERROR 107: Invalid input\nExpected input: %i characters", PRODUCT_CODE_SIZE - 1);
					continue;
				}
			}
		} while (!isValidCode);
		
		//check if there is a code corresponding to the inputted one
		for ((*ptrPosition) = 0; (*ptrPosition) < productsQuantity && !(*productFound); (*ptrPosition)++) {
			if (strcmp(productCode, currentProducts[(*ptrPosition)].code) == 0) {
				*productFound = true;
				break; //mantain position
			}
		}
		
		if (!(*productFound)) {
			fprintf(stderr, "\nERROR 202: Product not found");
			readInput('c', "\nInput new code? <Y|N> ", &tryAgain, 0);
			while (tryAgain != 'Y' && tryAgain != 'N') {
				fprintf(stderr, "\nERROR 106: Invalid input\nExpectedInput: Y, N\n");
				readInput('c', "\nInput new code? <Y|N> ", &tryAgain, 0);
			}
		}
		
		if (tryAgain == 'N') {
			break;
		}
	}
}

/* errors:
first digit: indicates error nature
second and third digits: error id

error nature list:
0: syntax error
1: input error
2: run-time error

errors list:

001: invalid character as parameter for readinput().
 
101: invalid input. Correct input: integer
102: invalid input. Correct input: float
103: invalid input. Correct input: double	(if an integer or float is inputted, it will be converted, which is not a problem)
104: invalid input. Problem: input is too big for the string or EOF reached before a character was found
105: invalid input. Correct input: positive integer
106: invalid input. Correct input: specified characters
107: invalid input. Problem: not enough characters
108: invalid input. Problem: already existent code 
109: invalid input. Problem: already existent name
110: invalid input. Correct input: positive real number

201: memory allocation failed
202: product not found

*/



