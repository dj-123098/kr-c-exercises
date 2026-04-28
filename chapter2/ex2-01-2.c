// ex2-01-2.c -- display different types' ranges using bitwise operations

#include <stdio.h>

int main(void)
{
	printf("signed char: %d ~ %d\n", -(1 << (sizeof(char) * 8 - 1)), (1 << (sizeof(char) * 8 - 1)) - 1);
	printf("signed short: %d ~ %d\n", -(1 << (sizeof(short) * 8 - 1)), (1 << (sizeof(short) * 8 - 1)) - 1);
	printf("signed int: %d ~ %d\n", (1 << (sizeof(int) * 8 - 1)), (int)(1 << (sizeof(int) * 8 - 1)) - 1);
	printf("signed long: %ld ~ %ld\n", -(1L << (sizeof(long) * 8 - 1)), (1L << (sizeof(long) * 8 - 1)) - 1);
	printf("unsigned char: 0 ~ %u\n", (unsigned)(1 << (sizeof(char) * 8)) - 1);
	printf("unsigned short: 0 ~ %u\n", (unsigned)(1 << (sizeof(short) * 8)) - 1);
	printf("unsigned int: 0 ~ %u\n", (unsigned)(1 << (sizeof(int) * 8)) - 1);
	printf("unsigned long: 0 ~ %lu\n", (unsigned long)(1UL << (sizeof(long) * 8)) - 1);

	return 0;
}