// ex1-20.c -- detab

#include <stdio.h>

#define TAB 8

int main(void)
{
	// initialization
	int c;
	int cnt;
	int i;
	
	// main loop
	cnt = 0;
	while ((c = getchar()) != EOF)
	{
		if (c == '\t')
		{
			for (i = TAB; i > cnt; --i)
				printf(" ");
			cnt = 0;
		}
		else if (c == '\n')
		{
			cnt = 0;
			putchar(c);
		}
		else
		{
			++cnt;
			if (cnt == TAB)
				cnt = 0;
			putchar(c);
		}
	}
	
	return 0;
}