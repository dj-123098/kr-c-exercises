// ex8-01.c -- rewrite cat

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

void filecopy(int, int);

int main(int argc, char *argv[])
{
    int f1;
    char *prog = argv[0];

    if (argc == 1)
        filecopy(0, 1);
    else
        while (--argc > 0)
        {
            if ((f1 = open(*++argv, O_RDONLY, 0)) == -1)
            {
                fprintf(stderr, "%s: can't open %s\n",
                        prog, *argv);
                exit(1);
            }
            else
            {
                filecopy(f1, 1);
                close(f1);
            }
        }

    exit(0);
}

// filecopy: copy f1 into f2
void filecopy(int f1, int f2)
{
    char buf[BUFSIZ];
    int n;

    while ((n = read(f1, buf, BUFSIZ)) > 0)
        write(f2, buf, n);
}