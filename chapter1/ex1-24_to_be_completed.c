// ex1-24.c -- find unmatched parentheses errors in C programs
// to be completed

#include <stdio.h>

int main(void)
{
	// initialization
	int c;
	int paren, brack, brace;
	
	// main loop
	paren = brack = brace = 0;
	while ((c = getchar()) != EOF)
	{
		if (c == '(')
			++paren;
		else if (c == ')')
			--paren;
		else if (c == '[')
			++brack;
		else if (c == ']')
			--brack;
		else if (c == '{')
			++brace;
		else if (c == '}')
			--brace;
	}

	// display results
	if (paren < 0)
	{
		printf("Unbalanced parentheses\n");
		paren = 0;
	}
	else if (brace < 0)
	{
		printf("Unbalanced braces\n");
		brace = 0;
	}
	else if (brack < 0)
	{
		printf("Unbalanced brackets\n");
		brack = 0;
	}

	return 0;
}