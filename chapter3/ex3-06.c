//ex6.c -- implement itoa

// itoa's help function
void reverse(char s[]);

// itoa: convert n to characters in s with at least min length
void itoa(int n, char s[], int min)
{
    int i, sign;
	unsigned un;

    un = ((sign = n) > 0)? n : -n;

    i = 0;
    do
		s[i++] = un % 10 + '0';
	while ((un /= 10) > 0);
    if (sign < 0)
        s[i++] = '-';
	for (; i < min; ++i)
		s[i] = ' ';
    s[i] = '\0';
    reverse(s);
}

// reverse: reverse string s
void reverse(char s[])
{
	int i, j;
	char c;
	
	for (i = 0, j = strlen(s) - 1; i < j; ++i, --j)
		c = s[i], s[i] = s[j], s[j] = c;
}