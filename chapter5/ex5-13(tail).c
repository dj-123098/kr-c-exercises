// ex5-13(tail).c -- display last n lines in input

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 1000

int getline(char *line, int lim);
void printline(char **lines, int cnt);

int main(int argc, char *argv[])
{
    // initialization
    int n, cnt, i;
    char line[MAXLEN];
    char **lines, *p;

    // define n
    n = 10;
    if (argc > 1)
        n = atoi(++(*++argv));

    // main loop
    lines = malloc(n * sizeof(char *));
    cnt = 0;
    while (getline(line, MAXLEN) > 0)
    {
        p = malloc((strlen(line) + 1) * sizeof(char));
        strcpy(p, line);
        if (cnt == n)
        {
            free(lines[0]);
            for (i = 0; i < n - 1; ++i)
                lines[i] = lines[i + 1];
            lines[i] = p;
        }
        else
            lines[cnt++] = p;
    }

    // print result
    printline(lines,cnt);
    free(lines);

    return 0;
}

// getline: get line within lim
int getline(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n') 
        s[i++] = c;
    s[i] = '\0';
    return i;
}

// printline: print lines and free space
void printline(char **lines, int cnt)
{
    int i;

    for (i = 0; i < cnt; ++i)
    {
        printf("%s", lines[i]);
        free(lines[i]);
    }
}