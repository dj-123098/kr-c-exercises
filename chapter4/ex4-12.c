// ex4-12.c -- implement itoa using recursion

// itoa: convert n to characters in s
void itoa(int n, char s[])
{
    static int i = 0;
    static int sign = 0;

    if (!sign)
    {
        if (n < 0)
        {
            n = -n;
            s[i++] = '-';
        }
        sign = 1;
    }
    if (n / 10)
        itoa(n / 10, s);
    s[i] = n % 10 + '0';
}