// ex7-07.c -- print lines that match pattern from 1st arg

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

int getline(char *line, int max);

int main(int argc, char *argv[])
{
    // initialization
    char line[MAXLINE];
    int found = 0, i;
    FILE *fp;
    char *prog = argv[0];

    // check argv
    if (argc < 2)
    {
        fprintf(stderr, "Usage: find pattern\n");
        exit(-2);
    }
    if (argc == 2)
        while (getline(line, MAXLINE) > 0)
            if (strstr(line, argv[1]) != NULL)
            {
                printf("%s", line);
                found++;
            }
    else
    {
        // main loop
        for (i = 2; i < argc; ++i)
        {
            fp = fopen(argv[i], "r");
            if (!fp)
            {
                fprintf(stderr, "%s can't open %s\n", prog, argv[i]);
                exit(-1);
            }
            while (fgets(line, MAXLINE, fp))
                if (strstr(line, argv[1]) != NULL)
                {
                    printf("%s:\n%s", argv[i], line);
                    found++;
                }
            fclose(fp);
        }
    }

    return found;
}

// getline: get line within lim
int getline(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n') 
	{
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}