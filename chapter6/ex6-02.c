// ex6-02.c -- print words in group

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAXWORD 100

// struct wnode: the word node
struct wnode
{
    char *word;         // points to the word
    struct wnode *next; // points to the next word
};

// struct tnode: the tree node
struct tnode
{
    struct wnode *words;   // points to the words
    struct tnode *left;   // left child
    struct tnode *right;  // right child
};

struct tnode *addtree(struct tnode *, char *, int);
void treeprint(struct tnode *);
int getword(char *, int);

int main(int argc, char *argv[])
{
    // initialization
    struct tnode *root;
    char word[MAXWORD];
    int n;

    // address argv
    n = 6;
    if (argc > 1)
        n = *++(argv[1]);

    // main loop
    root = NULL;
    while (getword(word, MAXWORD) != EOF)
        if (isalpha(word[0]))
            root = addtree(root, word, n);

    // print result
    treeprint(root);

    return 0;
}



struct tnode *talloc(void);
char *my_strdup(char *);

// addtree: add a node with w, at or below p
struct tnode *addtree(struct tnode *p, char *w, int n)
{
    int cond, flag;
    struct wnode *wp;

    if (p == NULL)
    {
        p = talloc();
        p->words = (struct wnode *)malloc(sizeof(struct wnode));
        p->words->word = my_strdup(w);
        p->words->next = NULL;
        p->left = p->right = NULL;
    }
    else if ((cond = strncmp(w, p->words->word, n)) == 0)
    {
        flag = 0;
        for (wp = p->words; wp->next; wp = wp->next)
            if (strcmp(w, wp->word) == 0)
                flag = 1;
        if (strcmp(w, wp->word) == 0)
            flag = 1;
        if (!flag)
        {
            wp->next = (struct wnode *)malloc(sizeof(struct wnode));
            wp->next->word = my_strdup(w);
            wp->next->next = NULL;
        }
    }
    else if (cond < 0)
        p->left = addtree(p->left, w, n);
    else
        p->right = addtree(p->right, w, n);

    return p;
}

// treeprint: in-order print of tree p
void treeprint(struct tnode *p)
{   
    struct wnode *w;

    if (p != NULL)
    {
        treeprint(p->left);
        for (w = p->words; w; w = w->next)
            printf("%s ", w->word);
        printf("\n");
        treeprint(p->right);
    }
}

// talloc: make a tnode
struct tnode *talloc(void)
{
    return (struct tnode *)malloc(sizeof(struct tnode));
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



int getch(void);
void ungetch(int c);

// getword: get next word or character from input
int getword(char *word, int lim)
{
    int c, d;
    char *w = word;
    int prev;

    while (isspace(c = getch()))
        ;
    if (c != EOF)
        *w++ = c;
    if (c == '"')
    {
        while ((c = getch()) != '"' && c != EOF)
            if (c == '\\')
                getch();
        return getword(word, lim);
    }
    else if (c == '/')
    {
        d = getch();
        if (d == '*')
        {
            prev = 0;
            while ((c = getch()) != EOF)
            {
                if (prev == '*' && c == '/')
                    break;
                prev = c;
            }
            if (c == EOF)
                ungetch(c);
            return getword(word, lim);
        } 
        else
            ungetch(d);
    }
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