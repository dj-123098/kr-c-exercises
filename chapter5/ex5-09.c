// ex5-09.c -- implement day_of_year, month_day using pointer

#include <stdio.h>

static char daytab[2][13] =
{
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

// day_of_year: set day of year from month & day
int day_of_year(int year, int month, int day) 
{
    int i, leap;

    // error check
    leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    if (month > 12 || month <= 0)
    {
        printf("error: invalid month\n");
        return 0;
    }
    if (day <= 0 || day > *(*(daytab + leap) + month))
    {
        printf("error: invalid day\n");
        return 0;
    }

    for (i = 1; i < month; i++)
        day += *(*(daytab + leap) + i);
    return day;
}

// month_day: set month, day from day of year
void month_day(int year, int yearday, int *pmonth, int *pday) 
{
    int i, leap;

    // error check
    leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    if ((yearday - leap) > 365 || yearday <= 0)
    {
        printf("error: invalid yearday\n");
        return 0;
    }

    for (i = 1; yearday > *(*(daytab + leap) + i); i++)
        yearday -= *(*(daytab + leap) + i);
    *pmonth = i;
    *pday = yearday;
}