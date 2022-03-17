#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "blinker.h"
#include <time.h>

int countLeapYears(date d)
{
    int years = d.year;

    if (d.month <= 2)
        years--;
 
    return years / 4 - years / 100 + years / 400;
}
 
int getDifference(date d, struct tm tm)
{
    date t;
    t.day = tm.tm_mday;
    t.month = tm.tm_mon + 1;
    t.year = tm.tm_year + 1900;

    int monthDays[12] = { 31, 28, 31, 30, 31, 30,
                      31, 31, 30, 31, 30, 31 };
 
    int n1 = d.year * 365 + d.day;
 
    for (int i = 0; i < d.month - 1; i++)
        n1 += monthDays[i];
 
    n1 += countLeapYears(d);
 
    int n2 = t.year * 365 + t.day;
    for (int i = 0; i < t.month - 1; i++)
        n2 += monthDays[i];
    n2 += countLeapYears(t);
 
    return (n2 - n1);
}