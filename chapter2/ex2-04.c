// ex2-04.c -- implement squeeze

// squeeze: delete each character in s1 which matches any character in the string s2
void squeeze(char s1[], const char s2[])
{
	int i, j, k;
	
	for (i = 0; s1[i] != '\0'; ++i)
	{
		for (j = 0; s2[j] != '\0'; ++j)
			if (s1[i] == s2[j])
			{
				for (k = i; s1[k] != '\0'; )
					s1[k] = s1[++k];
				i--;
				break;
			}
	}
}