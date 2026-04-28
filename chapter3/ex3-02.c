// ex3-02.c -- implement escape and opp_escape

// escape: convert actual escape sequences into visible escape sequences
void escape(char s[], char t[])
{
	int i, j;
	
	for (i = j = 0; t[j] != '\0'; ++i, ++j)
	{
		switch (t[j])
		{
			case '\n':
				s[i] = '\\';
				s[++i] = 'n';
				break;
			case '\t':
				s[i] = '\\';
				s[++i] = 't';
				break;
			case '\\':
				s[i] = '\\';
				s[++i] = '\\';
				break;
			case '\'':
				s[i] = '\\';
				s[++i] = '\'';
				break;
			case '\"':
				s[i] = '\\';
				s[++i] = '\"';
				break;
			default:
				s[i] = t[j];
				break;
		}
	}
	s[i] = '\0';
}

// opp_escape: convert visible escape sequences into actual escape sequences
void opp_escape(char s[], char t[])
{
	int i, j;
	int flag;
	
	flag = 0;
	for (i = j = 0; t[j] != '\0'; ++i, ++j)
	{
		switch (t[j])
		{
			case '\\':
				if (flag)
				{
					s[i] = '\\';
					flag = 0;
				}
				else
				{
					flag = 1;
					--i;
				}
			case 'n':
				s[i] = '\n';
				if (flag)
					flag = 0;
				break;
			case 't':
				if (flag)
				s[i] = '\t';
				if (flag)
					flag = 0;
				break;
			case '\"':
				s[i] = '\"';
				if (flag)
					flag = 0;
				break;
			case '\'':
				s[i] = '\'';
				if (flag)
					flag = 0;
				break;
			default:
				if (flag)
				{
					s[i] = '\\';
					flag = 0;
					s[++i] = t[j];
				}
				else
					s[i] = t[j];
				break;
		}
	}
	s[i] = '\0';
}