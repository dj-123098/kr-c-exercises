// ex1-22.c -- separate line

#include <stdio.h>

#define N 20

int getline(char line[], int lim);
int delete_blanks(char line[], int len);

int main(void)
{
	// initialization
	int cnt, len;
	int i;
	char line[N];
	
	// main loop
	while ((len = getline(line, N)) > 0)
	{
		len = delete_blanks(line, len);
		if (line[len - 1] == '\n')
			printf("%s", line);
		else
			printf("%s\n", line);
	}
	
	return 0;
}

// getline: get line within lim
int getline(char line[], int lim)
{
	int c, i;
	
	for (i = 0; (i < lim - 2) && (c = getchar()) != '\n' && c != EOF; ++i)
		line[i] = c;
	if (c == '\n')
	{
		line[i] = c;
		++i;
	}
	line[i] = '\0';
	
	return i;
}

// delete_blanks: delete blanks at the end of line
int delete_blanks(char line[], int len)
{
	int i;
	
	for (i = len - 1; i >= 0 && (line[i] == ' ' || line[i] == '\t'); --i)
		;
	line[i + 1] = '\0';
	
	return i + 1;
}