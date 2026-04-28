// ex4-01.c -- implement strindex

#include <string.h>

// strindex: return the index of the rightmost occurrence of t in s, or -1 if none
int strindex(char s[], char t[])
{
    int i, j, k;

    for (i = strlen(s) - 1; i >= 0; i--)
	{
        for (j = i, k = 0; s[j] == t[k] && t[k] != '\0'; j++, k++)
            ;
        if (t[k] == '\0')
            return i;
    }
    return -1;
}