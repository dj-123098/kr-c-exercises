// ex7-09.c -- implement isupper

// save space
int isupper(int c)
{
    return (c >= 'A' && c <= 'Z');
}

// save time
#define UPPER 0x01
static const unsigned char upper_table[256] =
{
    ['A'] = UPPER, ['B'] = UPPER, ['C'] = UPPER, ['D'] = UPPER,
    ['E'] = UPPER, ['F'] = UPPER, ['G'] = UPPER, ['H'] = UPPER,
    ['I'] = UPPER, ['J'] = UPPER, ['K'] = UPPER, ['L'] = UPPER,
    ['M'] = UPPER, ['N'] = UPPER, ['O'] = UPPER, ['P'] = UPPER,
    ['Q'] = UPPER, ['R'] = UPPER, ['S'] = UPPER, ['T'] = UPPER,
    ['U'] = UPPER, ['V'] = UPPER, ['W'] = UPPER, ['X'] = UPPER,
    ['Y'] = UPPER, ['Z'] = UPPER
};

#define isupper(c) (upper_table[(unsigned)(c)] & UPPER)