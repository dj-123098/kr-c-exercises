// ex1-4.c -- print Celsius-Fahrenheit table for celsius = 0, 10, ..., 100

#include <stdio.h>

int main(void)
{
	// initialization
	float celsius, fahr;
	float lower, upper, step;
	
	lower = 0;
	upper = 100;
	step = 10;
	
	// begin main loop
	printf("Celsius-Fahrenheit Table\n");
	celsius = lower;
	while (celsius <= upper)
	{
		fahr = celsius * 1.8 + 32;
		printf("%3.0f\t%6.1f\n", celsius, fahr);
		celsius = celsius + step;
	}
	
	return 0;
}