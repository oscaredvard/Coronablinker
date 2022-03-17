#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "blinker.h"

#define TEST_CASE(name) printf("RUNNING CASE: %s", name)
#define VERIFY(cond, msg) if (cond) printf("SUCCESS: %s\n", msg); else printf("FAIL: %s\n", msg);

int main(void) {
    TEST_CASE("Count leap years\n");
    date d;
    d.day = 1;
    d.month = 1; 
    d.year = 2020;
    VERIFY(countLeapYears(d), "COUNTING WORKED\n");

    TEST_CASE("Counting difference between 2 dates\n");
    struct tm tm;
    d.day = 1;
    d.month = 1; 
    d.year = 2020;
    VERIFY(getDifference(d, tm), "DIFFERENCE BETWEEN DATE (1.1.2022) AND TODAY");
    d.day = 9;
    d.month = 3; 
    d.year = 2022;
    VERIFY(getDifference(d, tm), "DIFFERENCE BETWEEN DATE (9.3.2022) AND TODAY");
    d.day = 31;
    d.month = 12;
    d.year = 2022;
    VERIFY(getDifference(d, tm), "DIFFERENCE BETWEEN DATE (31.12.2022) AND TODAY");
}