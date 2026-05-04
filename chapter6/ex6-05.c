// ex6-05.c -- add undef

#include <stdlib.h>
#include <string.h>

// struct nlist: the table entry
struct nlist
{
    struct nlist *next; // next entry in chain
    char *name;         // defined name
    char *defn;         // replacement text
};

#define HASHSIZE 101
static struct nlist *hashtab[HASHSIZE]; // pointer table

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

// undef: delete (name, defn) in hashtab
void undef(char *name)
{
    struct nlist *np, *prev;

    if ((np = lookup(name)) == NULL)
        return;
    for (np = hashtab[hash(name)], prev = NULL; np != NULL; prev = np, np = np->next)
        if (strcmp(name, np->name) == 0)
        {
            if (prev == NULL)
                hashtab[hash(name)] = np->next;
            else
                prev->next = np->next;
            free((void *)np->name);
            free((void *)np->defn);
            free((void *)np);
            return;
        }
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