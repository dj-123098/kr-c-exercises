// ex2-10.c -- implement lower

// lower: convert c to lower case
int lower(int c)
{
	return (c >= 'A' && c <= 'Z') ? (c + 'a' - 'A') : c;
}