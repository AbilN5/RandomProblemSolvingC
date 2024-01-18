#include <stdio.h>

#define MAX_MATRIX_SIZE 30

int matrixSize;
bool triangularUpper, triangularLower;

int main() {
	//Initialization
	triangularUpper = triangularLower = true;
	
	//Data input
	printf("Input the matrix's size: ");
	while (scanf(" %i", &matrixSize) > MAX_MATRIX_SIZE || matrixSize <= 0) {
		printf("\nERROR: Invalid input");
		printf("\nInput the matrix's size: ");
	}
	
	//matrix initialization
	int squareMatrix[matrixSize][matrixSize];
	
	printf("\n\nMatrix elements\nInput only 0s and 1s\n\n");
	for (int i = 0; i < matrixSize; i++) {
		for (int j = 0; j < matrixSize; j++) {
			
			//element input
			printf("Line %i | Column %i: ", i+1, j+1);
			scanf(" %i", &squareMatrix[i][j]);
			
			//check if invalid for special matrices
			if (squareMatrix[i][j] == 0) {
				if (j < i) {
					triangularLower = false;
				} else if (j > i) {
					triangularUpper = false;
				} else {
					triangularLower = triangularUpper = false;
				}
			} else /*== 1*/ {
				if (j < i) {
					triangularUpper = false;
				} else if (j > i) {
					triangularLower = false;
				}
			}
			printf("\n");
		} //inner loop end
		printf("\n");	
	} //outer loop end
	
	//Data output
	printf("\n\nSQUARE MATRIX %ix%i\n------------------------------------------\n", matrixSize, matrixSize);
	for (int i = -2; i < matrixSize; i++) {
		for (int j = -1; j < matrixSize; j++) {
			if (i == -2) { 					//2 lines before matrix 
				if (j == -1){ 					//1 column before matrix
					printf("     |");
				} else {						//matrix visual index
					printf("  %i  |", j+1);
				}
			} else if (i == -1) {			//1 line before matrix
				printf("-----|");
			} else {						//matrix lines
				if (j == -1) {					//1 column before matrix
					printf("  %i  |", i+1);		
				} else {						//matrix elements
					printf("  %i  |", squareMatrix[i][j]);
				}
			}
		} //inner loop end
		printf("\n");
	} //outer loop end
	
	//output matrix type
	printf("\n");
	printf("The inserted matrix is a");
	if (triangularUpper) {
		printf("n upper triangular matrix");
	}
	if (triangularLower) {
		printf(" lower triangular matrix");
	}
	if (!triangularLower && !triangularUpper) {
		printf(" regular square matrix");
	}
	
	
	return 0;
}
