// ex1-15.c -- print Fahrenheit-Celsius table using a function

#include <stdio.h>

float fahr_to_celsius(float fahr);

int main(void)
{
	// initialization
	float fahr, celsius;
	float lower, upper, step;
	
	lower = 0;
	upper = 300;
	step = 20;
	
	// main loop
	printf("Fahrenheit-Celsius Table\n");
	fahr = lower;
	while (fahr <= upper)
	{
		celsius = fahr_to_celsius(fahr);
		printf("%3.0f\t%6.1f\n", fahr, celsius);
		fahr = fahr + step;
	}
	
	return 0;
}

// fahr_to_celsius: transform fahr into celsius
float fahr_to_celsius(float fahr)
{
	return (5.0 / 9.0) * (fahr - 32.0);
}