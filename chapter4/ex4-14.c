// ex4-14.c -- implement macro swap

// swap: swap two variables of any type
#define swap(t, x, y) {t temp = x; x = y; y = temp;}