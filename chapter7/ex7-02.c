// ex7-02.c -- print input reasonably

#include <stdio.h>
#include <ctype.h>

#define MAXLINE 60
#define HEX     4

// increment: next line
int increment(int pos, int n)
{
    if (pos + n < MAXLINE)
        return pos + n;
    else
    {
        putchar('\n');
        return n;
    }
}

int main(void)
{
    // initialization
    int c, pos = 0;

    // main loop
    while ((c = getchar()) != EOF)
    {
        if (isgraph(c) || c == ' ')
        {
            pos = increment(pos, 1);
            putchar(c);
        }
        else
        {
            pos = increment(pos, HEX);
            printf("\\x%02x", c);
        }
    }
    return 0;
}