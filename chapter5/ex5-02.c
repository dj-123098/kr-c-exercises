// ex5-02.c -- implement getfloat

#include <stdio.h>
#include <ctype.h>

int getch(void);
void ungetch(int);

// getfloat: get next float from input into *pn
int getfloat(float *pn)
{
    int c, sign, power;

    while (isspace(c = getch()))
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-')
    {
        ungetch(c);
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')
        c = getch();
    if (!isdigit(c) && c != '.')
        return 0;
    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');
    if (c == '.')
        c = getch();
    for (power = 0; isdigit(c); c = getch(), ++power)
        *pn = 10 * *pn + (c - '0');
    for (; power > 0; --power)
        *pn /= 10;
    *pn *= sign;
    if (c != EOF)
        ungetch(c);
    return c;
}



#define BUFSIZE 1     // 1 buffer character at most

char buf[BUFSIZE];    // buffer for ungetch
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