#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "blinker.h"
#include "time.h"

#define TEST_CASE(name) printf("RUNNING CASE: %s", name)
#define VERIFY(cond, msg) if (cond) printf("SUCCESS: %s\n", msg); else printf("FAIL: %s\n", msg);
#define FILE_NAME "list.txt"

int main(void) {
    data dt;
    list l;

    TEST_CASE("Initializing current time\n");
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    TEST_CASE("Writing to file: " FILE_NAME " (ID: 1234, Date: 1.1.2022)\n");
    dt.d.day = 1;
    dt.d.month = 1;
    dt.d.year = 2022;
    dt.ID = 1234;
    writeToFile(dt);

    TEST_CASE("Reading from file: " FILE_NAME);
    readFromFile(&l, dt, tm);

    return 0;
}