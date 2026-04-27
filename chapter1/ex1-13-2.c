// ex1-13-2.c -- display a histogram of the lengths of the words in the input
// vertical version

#include <stdio.h>

#define IN 1
#define OUT 0
#define MAXLEN 20

int main(void)
{
	//initialization
	int c, state, length;
	int i, j;
	int lengths[MAXLEN];
	for (i = 0; i < MAXLEN; ++i)
		lengths[i] = 0;
	int max;
	
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
	
	// print the histogram
	max = 0;
	for (i = 0; i < MAXLEN; ++i)
		if (max < lengths[i])
			max = lengths[i];
	printf("Length Histogram\n");
	for (i = 0; i < MAXLEN; ++i)
		printf("%2d ", i + 1);
	printf("\n");
	for (i = 0; i < max; ++i)
	{
		for (j = 0; j < MAXLEN; ++j)
		{
			if (i < lengths[j])
				printf(" * ");
			else
				printf("   ");
		}
		printf("\n");
	}
	
	
	return 0;
}