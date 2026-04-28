// ex2-08.c -- implement rightrot

// rightrot: rotate x to the right by n positions
unsigned rightrot(unsigned x, int n)
{
	return (x >> n) | ((x & ~(~0 << n)) << (sizeof(unsigned int) * 8 - n));
}