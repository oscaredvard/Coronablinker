#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "blinker.h"
#include "input.h"
#include <time.h>

void displayMenu(void)
{
    printf("Choose alternative:\n");
    printf("1. Register infection\n");
    printf("2. Register phone nearby\n");
    printf("3. Receive warning message\n");
    printf("4. Exit program\n");
    printf("Choice? ");
}

int inputStartcode(void) {
    printf("Put in startcode: ");
    int startcode = 0;
    while (startcode <= 0) {
        startcode = readInt();
        if (startcode <= 0) {
            printf("Please input positive number: ");
        }
    }
    printf("\nStartcode received. Sending information to server.\n\n");
    return startcode;
}

int inputIDcode(void) {
    int ID;
    printf("Put in identification code: ");
    ID = 0;
    while (ID <= 0) {
        ID = readInt();
        if (ID <= 0) {
            printf("Please input positive number: ");
        }
    }
    printf("\nIdentification code received. Sending information to server.\n\n");
    return ID;
}

date inputDate(void)
{
    date d;
    printf("Input date (DD.MM.YYYY): ");
    while (d.day < 1 || d.day > 31 || d.month < 1 || d.month > 12 || d.year > 2022 || (d.month == 2 && d.day > 28) || (d.month == 4 && d.day == 31) || (d.month == 6 && d.day == 31) || (d.month == 9 && d.day == 31) || (d.month == 11 && d.day == 31)) {
        d.day = readIntAnd('.');
        d.month = readIntAnd('.');
        d.year = readInt();
        if (d.day > 31 || d.day < 1) {
            printf("Day should be between 1-31.\n");
        }
        if (d.month < 1 || d.month > 12) {
            printf("Month should be between 1-12.\n");
        }
        if (d.month == 4 || d.month == 6 || d.month == 9 || d.month == 11)
        {
            if (d.day == 31)
            {
                printf("This month only has 30 days.\n");
            }
        }
        if (d.year != 2022) {
            printf("You can't input year(s) in the future or past.\n");
        }
        if (d.month == 2) {
                if (d.day > 28) {
                    printf("Since month is 2, input a date between 1-28.\n");
                }
        }
        if (d.day < 1 || d.day > 31 || d.month < 1 || d.month > 12 || d.year > 2022 || (d.month == 2 && d.day > 28) || (d.month == 4 && d.day == 31) || (d.month == 6 && d.day == 31) || (d.month == 9 && d.day == 31) || (d.month == 11 && d.day == 31)) {
            printf("Please input correct date: ");
        }
    }
    printf("\nDate received. Sending information to server.\n\n");
    return d;
}

void receiveWarningMsg(void) {
    printf("\nWARNING: You've been close to somebody infected with COVID-19.\n");
    printf("Quarantine for a minimum of 2 weeks is recommended.\n\n");
}