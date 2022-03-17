#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "blinker.h"

#define TEST_CASE(name) printf("RUNNING CASE: %s", name)
#define VERIFY(cond, msg) if (cond) printf("SUCCESS: %s\n", msg); else printf("FAIL: %s\n", msg);

int main(void) {
    list l;
    data dt;

    TEST_CASE("Creating list\n");
    l = createList();

    VERIFY(isEmpty(l), "List is empty\n")

    TEST_CASE("Inserting date and ID into list\n");
    dt.d.day = 1;
    dt.d.month = 1;
    dt.d.year = 2022;
    dt.ID = 1234;
    VERIFY(sortedInsert(&l, dt), "INSERTION OF ID (1234) AND DATE (1.1.2022) WORKED\n");
    dt.d.day = 10;
    dt.d.month = 3;
    dt.d.year = 2022;
    dt.ID = 999;
    VERIFY(sortedInsert(&l, dt), "INSERTION OF ID (999) AND DATE (10.3.2022) WORKED");
    dt.d.day = 1;
    dt.d.month = 3;
    dt.d.year = 2022;
    dt.ID = 50;
    VERIFY(sortedInsert(&l, dt), "INSERTION OF ID (50) AND DATE (1.3.2022) WORKED");

    TEST_CASE("Printing list\n");
    VERIFY(printList(l), "PRINTING OF LIST\n");

    TEST_CASE("Deleting list\n");
    VERIFY(deleteList(l), "DELETION OF LIST\n");

    return 0;
}