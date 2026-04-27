// ex1-21.c -- entab

#include <stdio.h>

#define TAB 8

int main(void)
{
	// initialization
	int c;
	int cnt, blanks;
	
	// main loop
	cnt = blanks = 0;
	while ((c = getchar()) != EOF)
	{
		if (c == '\n')
		{
			for (; blanks > 0; --blanks)
				putchar(' ');
			putchar(c);
			cnt = blanks = 0;
		}
		else if (c == ' ')
		{
			++cnt;
			++blanks;
			if (cnt == TAB)
			{
				putchar('\t');
				cnt = blanks = 0;
			}
		}
		else if (c == '\t')
		{
			putchar(c);
			cnt = blanks = 0;
		}
		else
		{
			for (; blanks > 0; --blanks)
				putchar(' ');
			++cnt;
			if (cnt == TAB)
				cnt = 0;
			putchar(c);
		}
	}
	
	return 0;
}