// ex1-17.c -- display all lines with at least 80 length

#include <stdio.h>

#define MAXLINE 1000

int getline(char line[], int maxline);

int main(void)
{
    // initialization
    int len;
    char line[MAXLINE];

    // main loop
    while ((len = getline(line, MAXLINE)) > 0)
		if (len > 80)
			printf("%s", line);
	
    return 0;
}

// getline: get line within lim
int getline(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n') 
	{
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}