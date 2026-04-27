// ex1-23.c -- delete /*...*/ comment in the code

#include <stdio.h>

#define IN 1
#define OUT 0

int main(void)
{
	// initialization
	int c;
	int comment_state, str_state, inflag, outflag;
	
	// main loop
	comment_state = OUT;
	str_state = OUT;
	inflag = outflag = OUT;
	while ((c = getchar()) != EOF)
	{
		if (str_state == OUT)
		{
			if (c == '"' && comment_state == OUT)
				str_state = IN;
		}
		else
		{
			if (c == '"' && comment_state == OUT)
				str_state = OUT;
		}
		if (str_state == OUT)
		{
			if (comment_state == OUT)
			{
				if (inflag == IN && c == '*')
				{	
					comment_state = IN;
					inflag = OUT;
				}
				else if (inflag == IN)
				{
					putchar('/');
					putchar(c);
					inflag = OUT;
				}
				else if (c == '/')
					inflag = IN;
				else
					putchar(c);
			}
			else
			{
				if (outflag == IN && c == '/')
				{
					comment_state = OUT;
					outflag = OUT;
				}
				else if (outflag == IN)
					outflag = OUT;
				else if (c == '*')
					outflag = IN;
			}
		}
		else
			putchar(c);
	}
	
	return 0;
}