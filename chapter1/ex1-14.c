// ex1-14.c -- display a histogram of the frequency of each character in the input

#include <stdio.h>

int main(void)
{
	// initialization
	int c;
	int i, j;
	int characters[26];
	for (int i = 0; i < 26; ++i)
		characters[i] = 0;
	
	// main loop
	while ((c = getchar()) != EOF)
		if (c > 'a' && c < 'z')
			++characters[c - 'a'];
	
	// print the histogram
	printf("Character Histogram\n");
	for (i = 0; i < 26; ++i)
	{
		printf("%c: ", 'a' + i);
		for (j = 0; j < characters[i]; ++j)
			printf("* ");
		printf("\n");
	}
	
	return 0;
}