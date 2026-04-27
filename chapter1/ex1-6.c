// ex1-6.c -- verify the value of (getchar() != EOF)

#include <stdio.h>

int main(void)
{
	int c;
	
	while ((c = getchar()) != EOF)
		printf("%d\n", c != EOF);
	printf("%d\n", c != EOF);
	
	return 0;
}