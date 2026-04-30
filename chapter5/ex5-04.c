// ex5-04.c -- implement strend

// return 1 if t at the end of s else 0
int strend(char *s, char *t)
{
    
    int len;

    while (*s++);
    for (len = 0; *t++; ++len);
    for (--s, --t; *t-- == *s--; --len);
    if (len)
        return 0;
    return 1;
}