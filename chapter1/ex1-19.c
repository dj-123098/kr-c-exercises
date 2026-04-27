// ex1-19.c -- reverse all lines

#include <stdio.h>

#define MAXLINE 1000

int getline(char line[], int maxline);
void reverse(char line[], char reversed[], int len);

int main(void)
{
    // initialization
    int len;
    char line[MAXLINE];
	char reversed[MAXLINE];

    // main loop
    while ((len = getline(line, MAXLINE)) > 0)
	{
		reverse(line, reversed, len);
		printf("%s\n", reversed);
	}
	
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

// reverse: reverse a line
void reverse(char line[], char reversed[], int len)
{
	for (int i = 0; i < len; ++i)
		reversed[i] = line[len - i - 1];
	reversed[len] = '\0';
}