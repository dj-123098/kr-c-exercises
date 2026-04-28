// ex4-10.c -- using getline (only revise getop part)

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

#define MAXLEN 100 // max size of line
#define MAXOP 100  // max size of operand or operator
#define NUMBER '0' // signal that a number was found

int getop(char []);
void push(double);
double pop(void);

// reverse Polish calculator
int main(void)
{
    // initialization
    int type;
    double op1, op2;
    char s[MAXOP];
    double vars[26];
    double last_print;
    int i;

    for (i = 0; i < 26; ++i)
        vars[i] = 0.0;
    last_print = 0.0;

    // main loop
    while ((type = getop(s)) != EOF)
    {
        if (islower(type))
        {
            push(vars[type - 'a']);
            continue;
        }
        else if (type == '#')
        {
            push(last_print);
            continue;
        }
        switch (type)
        {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error: zero divisor\n");
                break;
            case '%':
                op2 = pop();
                if (op2 != 0.0)
                    push(fmod(pop(), op2));
                else
                    printf("error: zero divisor\n");
                break;
            case '^':
                op2 = pop();
                op1 = pop();
                if (op1 > 0 || (op1 == 0 && op2 > 0))
                    push(pow(op1, op2));
                else
                    printf("error: invalid base\n");
            case 'S':
                push(sin(pop()));
                break;
            case 'E':
                push(exp(pop()));
                break;
            case '=':
                op2 = pop();
                type = getop(s);
                if (islower(type))
                    vars[type - 'a'] = op2;
                else
                    printf("error: variable name expected");
                push(op2);
                break;
            case '\n':
                last_print = pop();
                printf("\t%.8g\n", last_print);
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }
    return 0;
}



#define MAXVAL 100    // maximum depth of val stack

int sp = 0;           // next free stack position
double val[MAXVAL];   // value stack

// push: push f onto value stack
void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

// pop: pop and return top value from stack
double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else
    {
        printf("error: stack empty\n");
        return 0.0;
    }
}

// print_top: print top value from stack without pop it
void print_top(void)
{
    printf("%f\n", val[sp]);
}

// copy_top: duplicate top element
void copy_top(void)
{
    push(pop());
}

// exchange_top: exchange top two values
void exchange_top(void)
{
    double top1, top2;

    top1 = pop();
    top2 = pop();
    push(top1);
    push(top2);
}

// clear: clear stack
void clear(void)
{
    sp = 0;
}



char line[MAXLEN]; // line buffer
int li = 0;        // line pos

int getline(char s[], int lim);

// getop: get next character or numeric operand
int getop(char s[])
{
    int i, c;

    if (line[li] == '\0')
    {
        if (getline(line, MAXLEN) == 0)
            return EOF;
        li = 0;
    }
    while ((s[0] = c = line[li++]) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if (!isdigit(c) && c != '.')
        return c;
    i = 0;
    if (isdigit(c))
        while (isdigit(s[++i] = c = line[li++]))
            ;
    if (c == '.')
        while (isdigit(s[++i] = c = line[li++]))
            ;
    s[i] = '\0';
    li--;
    
    return NUMBER;
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