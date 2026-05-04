// ex7-08.c -- print a set of files

#include <stdlib.h>
#include <stdio.h>

#define MAXLINE 100

void printfile(FILE *fp, int max);

int main(int argc, char *argv[])
{
    // initialization
    FILE *fp;
    char *prog = argv[0];

    // main loop
    while (--argc > 0)
    {
        fp = fopen(*++argv, "r");
        if (!fp)
        {
            fprintf(stderr, "%s can't open %s\n", prog, *argv);
            exit(-1);
        }
        printf("------------%s-----------\n", *argv);
        printfile(fp, MAXLINE);
        fclose(fp);
    }
    fclose(fp);

    return 0;
}

#define MAXLEN 100

// printfile: print file
void printfile(FILE *fp, int lim)
{
    int papers = 1, lines;
    char *line;

    lines = 0;
    while (fgets(line, MAXLEN, fp))
    {
        fputs(line, stdout);
        lines++;
        if (lines == lim)
        {
            putchar('\f');
            lines = 0;
            papers++;
        }
    }
    printf("papers: %d\f", papers);
}