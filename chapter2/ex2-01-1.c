// ex2-01-1.c -- display different types' ranges using macros from <limits.h>

#include <stdio.h>
#include <limits.h>

int main(void)
{
	printf("signed char: %d ~ %d\n", SCHAR_MIN, SCHAR_MAX);
	printf("signed short: %d ~ %d\n", SHRT_MIN, SHRT_MAX);
	printf("signed int: %d ~ %d\n", INT_MIN, INT_MAX);
	printf("signed long: %ld ~ %ld\n", LONG_MIN, LONG_MAX);
	printf("unsigned char: 0 ~ %u\n", UCHAR_MAX);
	printf("unsigned short: 0 ~ %u\n", USHRT_MAX);
	printf("unsigned int: 0 ~ %u\n", UINT_MAX);
	printf("unsigned long: 0 ~ %lu\n", ULONG_MAX);
	
	return 0;
}