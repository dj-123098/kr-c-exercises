// ex6-06.c -- #define processor

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 100

// struct nlist: the table entry
struct nlist
{
    struct nlist *next; // next entry in chain
    char *name;         // defined name
    char *defn;         // replacement text
};

#define HASHSIZE 101
static struct nlist *hashtab[HASHSIZE]; // pointer table

struct nlist *install(char *name, char *defn);
struct nlist *lookup(char *s);
int getword(char *word, int lim);

int main(void)
{
    // initialization
    int c;
    char *w, *name, *defn;
    struct nlist *np;

    // main loop
    while ((c = getword(w, LEN)) != EOF)
    {
        if (c == '#')
        {
            c = getword(w, LEN);
            if (strcmp(w, "define") == 0)
            {
                c = getword(name, LEN);
                c = getword(defn, LEN);
                install(name, defn);
            }
        }
        if (np = lookup(w))
            printf("%s ", np->defn);
        else
            printf("%s ", w);
    }

    return 0;
}



// hash: form hash value for string s
unsigned hash(char *s)
{
    unsigned hashval;

    for (hashval = 0; *s != '\0'; s++)
        hashval = *s + 31 * hashval;

    return hashval % HASHSIZE;
}



struct nlist *lookup(char *);
char *my_strdup(char *);

// install: put (name, defn) in hashtab
struct nlist *install(char *name, char *defn)
{
    struct nlist *np;
    unsigned hashval;

    if ((np = lookup(name)) == NULL)
    {
        np = (struct nlist *)malloc(sizeof(*np));
        if (np == NULL || (np->name = strdup(name)) == NULL)
            return NULL;
        hashval = hash(name);
        np->next = hashtab[hashval];
        hashtab[hashval] = np;
    }
    else
        free((void *)np->defn);
    if ((np->defn = strdup(defn)) == NULL)
        return NULL;
    return np;
}

// lookup: look for s in hashtab
struct nlist *lookup(char *s)
{
    struct nlist *np;

    for (np = hashtab[hash(s)]; np != NULL; np = np->next)
        if (strcmp(s, np->name) == 0)
            return np;

    return NULL;
}



// make a duplicate of s
char *my_strdup(char *s)
{
    char *p;

    p = (char *)malloc(strlen(s) + 1);
    if (p != NULL)
        strcpy(p, s);
        
    return p;
}



#include <ctype.h>

int getch(void);
void ungetch(int c);

// getword: get next word or character from input
int getword(char *word, int lim)
{
    int c;
    char *w = word;
    int prev;

    while (isspace(c = getch()))
        ;
    if (c != EOF)
        *w++ = c;
    if (!isalpha(c) && c != '_')
    {
        *w = '\0';
        return c;
    }
    for ( ; --lim > 0; w++)
        if (!isalnum(*w = getch()) && *w != '_')
        {
            ungetch(*w);
            break;
        }
    *w = '\0';
    return word[0];
}

#define BUFSIZE 100

int buf[BUFSIZE];     // buffer for ungetch
int bufp = 0;         // next free position in buf

// getch: get a (possibly pushed-back) character
int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

// ungetch: push character back on input
void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}