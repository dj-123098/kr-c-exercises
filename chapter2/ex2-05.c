// ex2-05.c -- implement any

// any: return the first index in s1 where any character from s2 occurs, or -1 if s1 contains no characters from s2
int any(const char s1[], const char s2[])
{
	int i, j;
	
	for (i = 0; s1[i] != '\0'; ++i)
		for (j = 0; s2[j] != '\0'; ++j)
			if (s1[i] == s2[j])
				return i;
	return -1;
}