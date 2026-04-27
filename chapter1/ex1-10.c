// ex1-10.c -- display input with escape sequences visible

#include <stdio.h>

int main(void)
{
	// initialization
	int c;
	
	// main loop
	while ((c = getchar()) != EOF)
	{
		if (c == '\t')
		{
			putchar('\\');
			putchar('t');
		}
		else if (c == '\b')
		{
			putchar('\\');
			putchar('b');
		}
		else if (c == '\\')
		{
			putchar('\\');
			putchar('\\');
		}
		else
			putchar(c);
	}
	
	return 0;
}