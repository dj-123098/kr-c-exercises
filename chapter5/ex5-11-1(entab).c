// ex5-11-1(entab).c -- entab with optional command line arguments

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	// initialization
	int c;
	int cnt, blanks;
    int tab;

    // define tab
    if (argc == 1)
        tab = 8;
    else
        tab = atoi(++(argv[1]));
	
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
			if (cnt == tab)
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
			if (cnt == tab)
				cnt = 0;
			putchar(c);
		}
	}
	
	return 0;
}