// ex2-06.c -- implement setbits

// setbits: set n bits of x starting at position p with the rightmost n bits of y
unsigned setbits(unsigned x, int p, int n, unsigned y)
{
	return (x & ~(~(~0 << n ) << (p - n))) | ((y << (p - n)) & ((~0 << p) | ~(~0 << (p - n))));
}