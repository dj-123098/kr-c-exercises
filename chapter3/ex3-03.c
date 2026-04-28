// ex3-03.c -- implement expand

#include <ctype.h>

// expand: expand x-y form
void expand(const char s1[], char s2[])
{
	int i, j;
	char c, prev, next;
	
	i = j = 0;
	while ((c = s1[i]) != '\0')
	{
		if (c == '-' && i > 0)
		{
			prev = s1[i - 1];
			next = s2[i + 1];
			if (prev < next)
			{
				if ((islower(prev) && islower(next)) ||
					(isupper(prev) && isupper(next)) ||
					(isdigit(prev) && isdigit(next)))
				{
					for (c = prev + 1; c <= next; ++c)
						s2[j++] = c;
					i += 2;
				}
				else
					s2[j++] = s1[i++];
			}
			else
				s2[j++] = s1[i++];
		}
		else
			s2[j++] = s1[i++];
	}
	s2[j] = '\0';
}