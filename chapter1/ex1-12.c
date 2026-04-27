// ex1-12.c -- display input with one word per line

#include <stdio.h>

#define IN  1
#define OUT 0

int main(void)
{
	// initialization
	int c, state;
	
	// main loop
	state = IN;
	while ((c = getchar()) != EOF)
	{
		if (c == ' ' || c == '\n' || c == '\t')
			 if (state == IN)
			 {
				 putchar('\n');
				 state = OUT;
			 }
		else
		{
			if (state == OUT)
				state = IN;
			putchar(c);
		}
	}
	
	return 0;
}