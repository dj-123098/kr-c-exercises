// ex5-07.c -- implement readlines

#include <stddef.h>

#define MAXLEN 1000

// readlines: read input lines
int readlines(char lineptr[][MAXLEN], int maxlines)
{
    int len, nlines;

    nlines = 0;
    while ((len = getline(lineptr[nlines], MAXLEN)) > 0)
        if (nlines >= maxlines)
            return -1;
        else
            lineptr[nlines++][len-1] = '\0';
    return nlines;
}