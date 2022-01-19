#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct date {
    int day;
    int month;
    int year;
};

void displayMenu(void);
void inputDate(struct date * d);