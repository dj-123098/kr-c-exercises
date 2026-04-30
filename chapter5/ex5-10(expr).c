// ex5-10(expr).c -- calculate reverse Polish expression

#include <stdio.h>
#include <stdlib.h>

void push(double f);
double pop(void);

int main(int argc, char *argv[])
{
    double op2;

    while (*++argv)
    {
        switch (**argv)
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
                if (op2 == 0)
                {
                    printf("Error: Zero divisior!\n");
                    push(op2);
                }
                else
                    push(pop() / op2);
                break;
            default:
                push(atof(*argv));
                break;
        }
    }
    printf("%g\n", pop());

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