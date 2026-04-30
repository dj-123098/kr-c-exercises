// ex5-06.c -- implement getline, atoi, itoa, reverse, strindex, getop using pointer

#include <stdio.h>

// getline: get line within lim
int getline(char *s, int lim)
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

#include <ctype.h>

// atoi: convert s to integer
int atoi(char *s)
{
    int n, sign;

    while (isspace(*s++))
        ;
    sign = (*s == '-') ? -1 : 1;
    if (*s == '+' || *s == '-')
        s++;
    for (n = 0; isdigit(*s); s++)
        n = 10 * n + (*s - '0');
    return sign * n;
}

// itoa's help function
void reverse(char *s);

// itoa: convert n to characters in s
void itoa(int n, char *s)
{
    int sign;
	unsigned un;
    char *p;

    un = ((sign = n) > 0)? n : -n;

    p = s;
    do
        *p++ = un % 10 + '0';
	while ((un /= 10) > 0);
    if (sign < 0)
        *p++ = '-';
    *p = '\0';
    reverse(s);
}

// reverse: reverse string s
void reverse(char *s)
{
	char *left, *right;
	char c;
	
    for (right = s; *right; right++)
        ;
	for (left = s, right--; left < right; ++left, --right)
		c = *left, *left = *right, *right = c;
}

// strindex: return the index of the rightmost occurrence of t in s, or -1 if none
int strindex(char *s, char *t)
{
    char *sbeg, *sp, *tp;

    for (sbeg = s; *sbeg; sbeg++)
        ;
    for (sbeg--; sbeg >= s; sbeg--)
	{
        for (sp = sbeg, tp = t; *sp == *tp && *tp; sp++, tp++)
            ;
        if (!*tp)
            return (int)(sbeg - s);
    }
    return -1;
}

#define NUMBER '0'

int getch(void);
void ungetch(int);

// getop: get next character or numeric operand
int getop(char *s)
{
    int c;

    while ((*s = c = getch()) == ' ' || c == '\t')
        ;
    *++s = '\0';
    if (!isdigit(c) && c != '.')
        return c;

    if (isdigit(c))
        while (isdigit(*s++ = c = getch()))
            ;
    if (c == '.')
        while (isdigit(*s++ = c = getch()))
            ;
    *--s = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}