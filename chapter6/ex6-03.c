// ex6-03.c -- print words and their lines

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 100

// struct lnode: the line node
struct lnode
{
    int line;           // line number
    struct lnode *next; // points to the next line
};

// struct tnode: the tree node
struct tnode
{
    char *word;           // points to the text
    struct lnode *lines;  // lines of occurrences
    struct tnode *left;   // left child
    struct tnode *right;  // right child
};

struct tnode *addtree(struct tnode *, char *, int);
void treeprint(struct tnode *);
int getword(char *, int, int *);

int main(void)
{
    // initialization
    struct tnode *root;
    char word[MAXWORD];
    int line = 1;

    // main loop
    root = NULL;
    while (getword(word, MAXWORD, &line) != EOF)
        if (isalpha(word[0]))
            root = addtree(root, word, line);

    // print result
    treeprint(root);

    return 0;
}



#include <stdlib.h>

struct tnode *talloc(void);
char *my_strdup(char *);

// addtree: add a node with w, at or below p
struct tnode *addtree(struct tnode *p, char *w, int line)
{
    int cond;
    struct lnode *l;

    if (p == NULL)
    {
        p = talloc();
        p->word = my_strdup(w);
        p->lines = (struct lnode *)malloc(sizeof(struct lnode));
        p->lines->line = line;
        p->lines->next = NULL;
        p->left = p->right = NULL;
    }
    else if ((cond = strcmp(w, p->word)) == 0)
    {
        for (l = p->lines; l->next; l = l->next)
            ;
        l->next = (struct lnode *)malloc(sizeof(struct lnode));
        l->next->line = line;
        l->next->next = NULL;
    }
    else if (cond < 0)
        p->left = addtree(p->left, w, line);
    else
        p->right = addtree(p->right, w, line);

    return p;
}

// treeprint: in-order print of tree p
void treeprint(struct tnode *p)
{
    struct lnode *l;

    if (p != NULL)
    {
        treeprint(p->left);
        printf("[%d", p->lines->line);
        for (l = p->lines->next; l; l = l->next)
            printf(", %d", l->line);
        printf("] %s\n", p->word);
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
int getword(char *word, int lim, int *line)
{
    int c;
    char *w = word;

    while (isspace(c = getch()))
        if (c = '\n')
            ++*line;
    if (c != EOF)
        *w++ = c;
    if (!isalpha(c))
    {
        *w = '\0';
        return c;
    }
    for ( ; --lim > 0; w++)
        if (!isalnum(*w = getch()))
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