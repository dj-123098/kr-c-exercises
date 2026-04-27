// ex1-8.c -- count ' 's, '\t's, '\n's in input

#include <stdio.h>

int main(void)
{
	// initialization
	int c, nl, n2, n3;
	
	nl = n2 = n3 = 0;

	// main loop
	while ((c = getchar()) != EOF)
	{
		if (c == ' ')
			++nl;
		else if (c == '\t')
			++n2;
		else if (c == '\n')
			++n3;
	}

	// display results
	printf("spaces: %d\n", nl);
	printf("tabs: %d\n", n2);
	printf("enters: %d\n", n3);

	return 0;
}