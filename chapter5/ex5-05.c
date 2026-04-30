// ex5-05.c -- implement strncpy, strncat, strncmp

// strncpy: copy t into s
char *strncpy(char *s, const char *t, int n)
{
    char *p;

    for (p = s; *p++ = *t++ && n > 0; --n);
    *p = '\0';
    return s;
}

// strcat: add t to the end of s
char *strncat(char *s, const char *t, int n)
{
    char *p;

    for (p = s; *p++; );
    for (; *p++ = *t++ && n > 0; --n);
    *p = '\0';
    return s;
}

// strncmp: compare two string in dictionary orders
int strncmp(const char *s, const char *t, int n)
{
    for (; *s++ == *t++ && n > 0; --n);
    return *--s - *--t;
}