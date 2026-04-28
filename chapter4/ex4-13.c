// ex4-13.c -- implement reverse using recursion

#include <string.h>

// reverse's helper function
void reverser(char s[], int i, int j);

// reverse: reverse string s
void reverse(char s[])
{
    reverser(s, 0, strlen(s) - 1);
}

// reverser: reverse string s from index i to j
void reverser(char s[], int i, int j)
{
    char temp;

    if (i < j)
    {
        temp = s[i], s[i] = s[j], s[j] = temp;
        reverser(s, ++i, --j);
    }
}

