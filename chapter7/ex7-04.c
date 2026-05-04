// ex7-04.c -- implement minscanf

#include <stdio.h>
#include <stdarg.h>

// minscanf: minimal scanf with variable argument list
void minscanf(char *fmt, ...)
{
    va_list ap;
    char *p, **sp, *cp;
    int *ip;
    double *dp;
    unsigned *up;
    char str[2];

    va_start(ap, fmt);
    for (p = fmt; *p; p++)
    {
        if (*p != '%')
        {
            str[0] = *p;
            str[1] = '\0';
            scanf(str);
            continue;
        }
        switch (*++p)
        {
            case 'd':
                ip = va_arg(ap, int *);
                scanf("%d", ip);
                break;
            case 'u':
                up = va_arg(ap, unsigned *);
                scanf("%u", up);
                break;
            case 'f':
                dp = va_arg(ap, double *);
                scanf("%f", dp);
                break;
            case 'c':
                cp = va_arg(ap, char *);
                scanf("%c", cp);
                break;
            case 's':
                sp = va_arg(ap, char **);
                scanf("%s", sp);
                break;
            case '%':
                scanf("%");
                break;
            default:
                scanf("%");
                str[0] = *p;
                str[1] = '\0';
                scanf(str);
                break;
        }
    }
    va_end(ap);
}