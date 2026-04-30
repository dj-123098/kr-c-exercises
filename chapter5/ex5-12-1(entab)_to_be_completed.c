// ex5-12-1(entab).c -- entab with optional command line arguments
// to be completed

#include <stdio.h>

int main(int argc, char *argv[])
{
	// initialization
	int c;
	int cnt, blanks;
    int m, n;

    // define m, n
    m = n = 8;
    if (argc >= 2)
	{
		if (argv[1][0] == '-')
			m = atoi(++(argv[1]));
		else
			n = atoi(++(argv[1]));
	}
	if (argc == 3)
	{
		if (argv[2][0] == '-')
			m = atoi(++(argv[2]));
		else
			n = atoi(++(argv[2]));
	}
	
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
			if (cnt == n)
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
			if (cnt == n)
				cnt = 0;
			putchar(c);
		}
	}
	
	return 0;
}