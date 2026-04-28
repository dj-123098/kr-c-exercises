// ex4-02.c -- implement atof

#include <ctype.h>

// atof: convert string s to double
double atof(char s[])
{
    double val, power;
    int i, sign, exp;

    i = 0;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++)
	{
        val = 10.0 * val + (s[i] - '0');
        power *= 10;
    }
	if (s[i] == 'e' || s[i] == 'E')
	{
		exp = atoi(s + i + 1);
		for (i = 0; i < exp; ++i)
			power /= 10;
		for (i = 0; i > exp; --i)
			power *= 10;
	}
    return sign * val / power;
}