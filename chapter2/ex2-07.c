// ex2-07.c -- implement invert

// invert: return x with the n bits that begin at position p inverted
unsigned invert(unsigned x, int p, int n)
{
	return (x & ~(~(~0 << n ) << (p - n))) | ~(x & (~(~0 << n) << (p - n)));
}