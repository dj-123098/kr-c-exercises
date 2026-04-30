// ex5-14.c -- add -r

#include <stdio.h>
#include <string.h>

#define MAXLINES 5000       // max #lines to be sorted
char *lineptr[MAXLINES];    // pointers to text lines

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
void my_qsort(void *lineptr[], int left, int right,
           int (*comp)(void *, void *), int reverse);
int numcmp(const char *, const char *);

int main(int argc, char *argv[])
{
    // initialization
    int nlines;
    int numeric, reverse;
    int c;

    // check command line arguments
    numeric = 0;
    reverse = 1;
    while (--argc > 0 && (*++argv)[0] == '-')
        while ((c = *++argv[0]))
            switch (c)
            {
                case 'n':
                    numeric = 1;
                    break;
                case 'r':
                    reverse = -1;
                    break;
                default:
                    break;
            }

    // main logic
    if ((nlines = readlines(lineptr, MAXLINES)) >= 0)
    {
        my_qsort((void**) lineptr, 0, nlines - 1,
              (int (*)(void*,void*))(numeric ? numcmp : strcmp), reverse);
        writelines(lineptr, nlines);
        return 0;
    }
    else
    {
        printf("input too big to sort\n");
        return 1;
    }
}



void swap(void *v[], int i, int j);

// my_qsort: sort v[left]...v[right] into increasing order
void my_qsort(void *v[], int left, int right,
           int (*comp)(void *, void *), int reverse)
{
    int i, last;

    if (left >= right)
        return;
    swap(v, left, (left + right) / 2);
    last = left;
    for (i = left + 1; i <= right; i++)
        if ((*comp)(v[i], v[left]) * reverse < 0)
            swap(v, ++last, i);
    swap(v, left, last);
    my_qsort(v, left, last - 1, comp, reverse);
    my_qsort(v, last + 1, right, comp, reverse);
}



#include <stdlib.h>

// numcmp: compare s1 and s2 numerically
int numcmp(const char *s1, const char *s2)
{
    double v1, v2;

    v1 = atof(s1);
    v2 = atof(s2);
    if (v1 < v2)
        return -1;
    else if (v1 > v2)
        return 1;
    else
        return 0;
}



#define MAXLEN 1000 // max length of any input line
int getline(char *, int);
char *alloc(int);

// readlines: read input lines
int readlines(char *lineptr[], int maxlines)
{
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    while ((len = getline(line, MAXLEN)) > 0)
        if (nlines >= maxlines || (p = alloc(len)) == NULL)
            return -1;
        else
        {
            line[len-1] = '\0';
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    return nlines;
}

// writelines: write output lines
void writelines(char *lineptr[], int nlines)
{
    int i;

    for (i = 0; i < nlines; i++)
        printf("%s\n", lineptr[i]);
}



#define ALLOCSIZE 10000          // size of available space

static char allocbuf[ALLOCSIZE]; // storage for alloc
static char *allocp = allocbuf;  // next free position

// alloc: return pointer to n characters
char *alloc(int n)
{
    if (allocbuf + ALLOCSIZE - allocp >= n)
    {
        allocp += n;
        return allocp - n;
    }
    else
        return 0;
}

// afree: free storage pointed to by p
void afree(char *p)
{
    if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
        allocp = p;
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



// swap: interchange v[i] and v[j]
void swap(void *v[], int i, int j)
{
    void *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}