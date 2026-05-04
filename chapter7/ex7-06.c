// ex7-06.c -- print first different lines in two files

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAXLEN 100

int main(int argc, char *argv[])
{
    // initialization
    FILE *fp1, *fp2;
    char *line1, *line2;

    // main loop
    fp1 = fopen(argv[1], "r");
    if (!fp1) exit(-1);
    fp2 = fopen(argv[2], "r");
    if (!fp2) exit(-1);
    while (fgets(line1, MAXLEN, fp1) && fgets(line2, MAXLEN, fp2))
        if (strcmp(line1, line2))
        {
            printf("%s\n%s", line1, line2);
            exit(1);
        }

    return 1;
}