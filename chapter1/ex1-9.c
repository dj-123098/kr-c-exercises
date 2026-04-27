// ex1-9.c -- display input with spaces replaced by one space

#include <stdio.h>

#define IN  1
#define OUT 0

int main(void)
{
	// initialization
	int c;
	int flag;
	
	// main loop
	flag = OUT;
	while ((c = getchar()) != EOF)
	{
		if (c == ' ')
			if (flag == OUT)
			{
				putchar(c);
				flag = IN;
			}
		else
		{
			putchar(c);
			flag = OUT;
		}
	}
	
	return 0;
}