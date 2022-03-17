#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "blinker.h"

#define TEST_CASE(name) printf("RUNNING CASE: %s", name)
#define VERIFY(cond, msg) if (cond) printf("SUCCESS: %s\n", msg); else printf("FAIL: %s\n", msg);

int main(void) {
    TEST_CASE("Displaying the menu\n");
    displayMenu();

    TEST_CASE("Inputing a startcode\n");
    VERIFY(inputStartcode(), "STARTCODE (1) WORKED\n");
    VERIFY(inputStartcode(), "STARTCODE (1234) WORKED\n");
    VERIFY(inputStartcode(), "STARTCODE (9999) WORKED\n");

    TEST_CASE("Inputing an ID\n");
    VERIFY(inputIDcode(), "ID CODE (1) WORKED\n");
    VERIFY(inputIDcode(), "ID CODE (1234) WORKED\n");
    VERIFY(inputIDcode(), "ID CODE (9999) WORKED\n");


    //"Arithmetic or pointer type required ???"
    TEST_CASE("Inputing date\n");
    inputDate();

    TEST_CASE("Displaying warning message");
    receiveWarningMsg();

    return 0;
}