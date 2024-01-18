#include <stdio.h>

float X, Y;

int main() {
	
	//Data input
	printf("Input a value for a point on a cartesian plane (X,Y) separating both by a space or a new line: ");
	scanf("%f %f", &X, &Y);
	
	//Data output
	printf("\n(%.1f, %.1f)\n---------------------\n", X, Y);
	if ((X == 0) && (Y == 0)){
		printf("Point is located on origin");
	} else if (X == 0) {
		printf("Point is located on Y axis"); 
	} else if (Y == 0) {
		printf("Point is located on X axis");
	} else if ((X > 0) && (Y > 0)) {
		printf("Point is located on first quadrant");
	} else if ((X > 0) && (Y < 0)) {
		printf("Point is located on fourth quadrant");
	} else if /* X < 0 */ (Y > 0) {
		printf("Point is located on second quadrant");
	} else /* X < 0 && Y < 0 */ {
		printf("Point is located on third quadrant");
	}
	
	return 0;
}
