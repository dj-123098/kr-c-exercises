// ex1-3.c -- add title to the Fahrenheit-Celsius Table

#include <stdio.h>

int main(void)
{
	// initialization
	float fahr, celsius;
	float lower, upper, step;
	
	lower = 0;
	upper = 300;
	step = 20;
	
	// begin main loop
	printf("Fahrenheit-Celsius Table\n");
	fahr = lower;
	while (fahr <= upper)
	{
		celsius = (5.0 / 9.0) * (fahr - 32.0);
		printf("%3.0f\t%6.1f\n", fahr, celsius);
		fahr = fahr + step;
	}

	return 0;
}