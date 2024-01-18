#include <stdio.h>
#include <math.h>


#define JUMP 1



int main() {
	int ARRAY_SIZE = 4;
	
	int numbers[ARRAY_SIZE];
	
	printf("Original Array: \n");
	for (int i = 0; i < ARRAY_SIZE; i++) {
		numbers[i] = i + 1;
		printf("number[%i]: %i\n", i, numbers[i]);
	}	
	
	
	int max = (ARRAY_SIZE <= JUMP) ? JUMP : ARRAY_SIZE;
	
	while((max % ARRAY_SIZE) != 0 || (max % ARRAY_SIZE) != 0) {
		max++;
	}
	
	int iterations = max/JUMP - 1+1; // Calculate the number of iterations

    for (int i = 0; i < iterations; i++) {
        for (int j = 0; j < ARRAY_SIZE; j++) {
            numbers[(j + JUMP) % ARRAY_SIZE] = numbers[j]^numbers[(j + JUMP) % ARRAY_SIZE];
        }
    }
    for (int l = 0; l < max/ARRAY_SIZE; l++) {
     numbers[((l % ARRAY_SIZE) + JUMP) % ARRAY_SIZE] = numbers[(l % ARRAY_SIZE)]^numbers[((l % ARRAY_SIZE) + JUMP) % ARRAY_SIZE];
	}
	
	numbers[1] ^= numbers[0];
	
	printf("\n\nSwapped Array: \n");
	for (int i = 0; i < ARRAY_SIZE; i++) {
		printf("number[%i]: %i\n", i, numbers[i]);
	}
}
