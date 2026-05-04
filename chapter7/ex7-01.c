// ex7-01.c -- convert case

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    // initialization
    int c;
    int (*f)(int);

    // address argv[0]
    if (strcmp(argv[0], "lower") == 0)
        f = tolower;
    else
        f = toupper;

    // main loop
    while ((c = getchar()) != EOF)
        putchar(f(c));
        
    return 0;
}