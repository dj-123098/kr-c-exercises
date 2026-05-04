// ex6-04.c -- print word in decreasing order

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 100

// struct tnode: the tree node
struct tnode
{
    char *word;           // points to the text
    int count;            // number of occurrences
    struct tnode *left;   // left child
    struct tnode *right;  // right child
};

struct tnode *addtree(struct tnode *, char *);
int countnodes(struct tnode *);
void treetoarray(struct tnode *, struct tnode **);
int my_compare(const void *, const void *);
void arrayprint(struct tnode **);
int getword(char *, int);

int main(void)
{
    // initialization
    struct tnode *root;
    char word[MAXWORD];
    struct tnode **nodes;
    int cnt;

    // main loop
    root = NULL;
    while (getword(word, MAXWORD) != EOF)
        if (isalpha(word[0]))
            root = addtree(root, word);
    
    // sort
    cnt = countnodes(root);
    nodes = (struct tnode **)malloc(cnt * sizeof(struct tnode *));
    treetoarray(root, nodes);
    qsort(nodes, cnt, sizeof(struct tnode *), my_compare);

    // print result
    arrayprint(nodes);

    return 0;
}



struct tnode *talloc(void);
char *my_strdup(char *);

// addtree: add a node with w, at or below p
struct tnode *addtree(struct tnode *p, char *w)
{
    int cond;

    if (p == NULL)
    {
        p = talloc();
        p->word = my_strdup(w);
        p->count = 1;
        p->left = p->right = NULL;
    }
    else if ((cond = strcmp(w, p->word)) == 0)
        p->count++;
    else if (cond < 0)
        p->left = addtree(p->left, w);
    else
        p->right = addtree(p->right, w);

    return p;
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



// countnodes: count nodes
int countnodes(struct tnode *p)
{
    if (p == NULL)
        return 0;
    else
        return 1 + countnodes(p->left) + countnodes(p->right);
}

// treetoarray: transform tree to array
void treetoarray(struct tnode *p, struct tnode *nodes[])
{
    static int i = 0;

    if (p != NULL)
    {
        treetoarray(p->left, nodes);
        nodes[i++] = p;
        treetoarray(p->right, nodes);
    }
}

// arrayprint: in-order print of array a
void arrayprint(struct tnode *a[])
{   
    for (; *a; ++a)
        printf("%4d %s\n", (*a)->count, (*a)->word);
}



// my_compare: qsort's helper function
int my_compare(const void *a, const void *b)
{
    struct tnode *p1 = *(struct tnode **)a;
    struct tnode *p2 = *(struct tnode **)b;

    return (p2->count - p1->count);
}



int getch(void);
void ungetch(int c);

// getword: get next word or character from input
int getword(char *word, int lim)
{
    int c;
    char *w = word;

    while (isspace(c = getch()))
        ;
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