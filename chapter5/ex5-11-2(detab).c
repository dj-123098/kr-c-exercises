// ex5-11-2(detab).c -- detab with optional command line arguments

#include <stdio.h>

int main(int argc, char *argv[])
{
	// initialization
	int c;
	int cnt;
	int i;
    int tab;

    // define tab
    if (argc == 1)
        tab = 8;
    else
        tab = atoi(++(argv[1]));
        
	// main loop
	cnt = 0;
	while ((c = getchar()) != EOF)
	{
		if (c == '\t')
		{
			for (i = tab; i > cnt; --i)
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
			if (cnt == tab)
				cnt = 0;
			putchar(c);
		}
	}
	
	return 0;
}