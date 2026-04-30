// ex5-12-2(detab).c -- detab with optional command line arguments
// to be completed

#include <stdio.h>

int main(int argc, char *argv[])
{
	// initialization
	int c;
	int cnt;
	int i;
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
	cnt = 0;
	while ((c = getchar()) != EOF)
	{
		if (c == '\t')
		{
			for (i = n; i > cnt; --i)
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
			if (cnt == n)
				cnt = 0;
			putchar(c);
		}
	}
	
	return 0;
}