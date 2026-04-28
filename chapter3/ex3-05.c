// ex3-05.c -- implement itob	

// itob's help function
void reverse(char s[]);

// itob: convert n to characters in s based on b
void itob(int n, char s[], int b)
{
    int i, sign;
	unsigned un;

    un = ((sign = n) > 0)? n : -n;

    i = 0;
    do
        s[i++] = (b > 10 && un % b > 9) ? (un % b + 'a' - 10) : (un % b + '0');
	while ((un /= b) > 0);
    if (sign < 0)
        s[i++] = '-';
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