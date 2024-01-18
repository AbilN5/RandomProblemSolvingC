#include <stdio.h>

float averageKmLiter;
float averageVelocity;
float travelTime;
float distance;
float usedLiters;

int main() {
	
	//Data input
	printf("Input average kilometers traveled per liter: ");
	scanf("%f", &averageKmLiter);
	printf("Input average velocity during travel (km/h): ");
	scanf(" %f", &averageVelocity);
	printf("Input travel time (hours): ");
	scanf(" %f", &travelTime);
	
	//Data processing
	distance = travelTime * averageVelocity;
	usedLiters = distance/averageKmLiter;
	
	//Data output
	printf("Average velocity: %f Km/h\nTravel time: %f hours\nTraveled Distance: %f Kms\nUsed liters: %f L\n", averageVelocity, travelTime, distance, usedLiters);
				
	return 0;
}

