#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct date {
    int day;
    int month;
    int year;
};

void displayMenu(void)
{
    printf("V%clj alternativ:\n", 132);
    printf("1. Meddela din smitta\n");
    printf("2. Ta emot smittlarm\n");
    printf("3. St%cng program\n", 132);
}

void inputDate(struct date * d)
{
    printf("S%ctt in ett datum (dd.mm.%c%c%c%c): ", 132, 134, 134, 134, 134);
    scanf("%d.%d.%d", &d->day, &d->month, &d->year);
}