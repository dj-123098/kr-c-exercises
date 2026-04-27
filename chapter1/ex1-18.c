// ex1-18.c -- print lines without backspaces at the end

#include <stdio.h>

#define IN 1
#define OUT 0
#define MAXLINE 1000

int getline(char line[], int maxline);
void delete_blank(char line[], int len);

int main(void)
{
	// initialization
    int len;
    char line[MAXLINE];

	// main loop
    while ((len = getline(line, MAXLINE)) > 0)
	{
		delete_blank(line, len);
		if (line[0] != '\0')
			printf("%s\n", line);
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

// delete_all_backspaces: delete all backspaces at the end of lines
void delete_blank(char line[], int len)
{
	int flag = IN;
	
	for (len--; len >= 0 && flag == IN; len--)
	{	
		if (line[len] != ' ' && line[len] != '\t' && line[len] != '\n')
			flag = OUT;
	}
	line[len + 2] = '\0';
}