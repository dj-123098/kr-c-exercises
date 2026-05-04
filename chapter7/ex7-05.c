// ex7-05.c -- calculator using scanf

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXOP 100  // max size of operand or operator

void push(double);
double pop(void);

// reverse Polish calculator
int main(void)
{
    // initialization
    double temp;
    double op2;
    char s[MAXOP];

    // main loop
    while (scanf("%s", s) != EOF)
    {
        if (sscanf(s, "%f", &temp) == 1)
            push(temp);
        else
            switch (s[0])
            {
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
                case '\n':
                    printf("\t%.8g\n", pop());
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