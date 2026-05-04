// ex7-03.c -- add function

#include <stdio.h>
#include <stdarg.h>

// minprintf: minimal printf with variable argument list
void minprintf(char *fmt, ...)
{
    va_list ap;
    char *p, *sval, cval;
    int ival;
    double dval;
    unsigned uval;

    va_start(ap, fmt);
    for (p = fmt; *p; p++)
    {
        if (*p != '%')
        {
            putchar(*p);
            continue;
        }
        switch (*++p)
        {
            case 'd': case 'i':
                ival = va_arg(ap, int);
                printf("%d", ival);
                break;
            case 'u':
                uval = va_arg(ap, unsigned);
                printf("%u", uval);
                break;
            case 'f':
                dval = va_arg(ap, double);
                printf("%f", dval);
                break;
            case 'c':
                cval = va_arg(ap, int);
                putchar(cval);
                break;
            case 's':
                for (sval = va_arg(ap, char *); *sval; sval++)
                    putchar(*sval);
                break;
            case '%':
                putchar('%');
                break;
            default:
                putchar('%');
                putchar(*p);
                break;
        }
    }
    va_end(ap);
}