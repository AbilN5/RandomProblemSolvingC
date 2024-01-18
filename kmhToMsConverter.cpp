#include <stdio.h>

float kmh;
float ms;

int main () {
	
	//Data input
	printf("Input a value in km/h: ");
	scanf("%f", &kmh);
	
	//Processing
	ms = kmh/3.6;
	
	//Data output
	printf("%f km/h is equal to %f m/s", kmh, ms);
	
	return 0;
}
