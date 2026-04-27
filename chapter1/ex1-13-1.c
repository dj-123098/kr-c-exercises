// ex1-13-1.c -- display a histogram of the lengths of the words in the input
// horizontal version

#include <stdio.h>

#define IN 1
#define OUT 0
#define MAXLEN 20

int main(void)
{
	// initialization
	int c, state, length;
	int i, j;
	int lengths[MAXLEN];
	for (i = 0; i < MAXLEN; ++i)
		lengths[i] = 0;

	// main loop
	state = OUT;
	while ((c = getchar()) != EOF)
	{
		if ((c == ' ' || c == '\t' || c == '\n') && state == IN)
		{
			++lengths[length - 1];
			state = OUT;
		}
		else if (c == ' ' || c == '\t' || c == '\n')
			;
		else if (state == OUT)
		{
			state = IN;
			length = 1;
		}
		else
			++length;
	}
	++lengths[length - 1];
	
	// print the histogram
	printf("Length Histogram\n");
	for (i = 0; i < MAXLEN; ++i)
	{
		printf("%2d: ", i + 1);
		for (j = 0; j < lengths[i]; ++j)
			printf("* ");
		printf("\n");
	}
	
	return 0;
}