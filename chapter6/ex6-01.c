// ex6-01.c -- implement getword

#include <stdio.h>
#include <ctype.h>

int getch(void);
void ungetch(int c);

// getword: get next word or character from input
int getword(char *word, int lim)
{
    int c, d;
    char *w = word;
    int prev;

    while (isspace(c = getch()))
        ;
    if (c != EOF)
        *w++ = c;
    if (c == '"')
    {
        while ((c = getch()) != '"' && c != EOF)
            if (c == '\\')
                getch();
        return getword(word, lim);
    }
    else if (c == '#')
    {
        while ((c = getch()) != '\n')
            ;
        return getword(word, lim);
    }
    else if (c == '/')
    {
        d = getch();
        if (d == '*')
        {
            prev = 0;
            while ((c = getch()) != EOF)
            {
                if (prev == '*' && c == '/')
                    break;
                prev = c;
            }
            if (c == EOF)
                ungetch(c);
            return getword(word, lim);
        } 
        else
            ungetch(d);
    }
    if (!isalpha(c) && c != '_')
    {
        *w = '\0';
        return c;
    }
    for ( ; --lim > 0; w++)
        if (!isalnum(*w = getch()) && *w != '_')
        {
            ungetch(*w);
            break;
        }
    *w = '\0';
    return word[0];
}



#define BUFSIZE 100

int buf[BUFSIZE];     // buffer for ungetch
int bufp = 0;         // next free position in buf

// getch: get a (possibly pushed-back) character
int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

// ungetch: push character back on input
void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}