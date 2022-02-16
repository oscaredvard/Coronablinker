#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "blinker.h"
#include "input.h"
#include <time.h>

int main(void)
{
    list l;
    data dt;

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    printf("Current date: %d.%d.%d\n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);

    l = createList();

    readFromFile(&l, dt, tm);
    
    int exit = true;

    printf("\nWelcome to the coronablinker app!\n\n");

    while (exit)
    {
        int choice = -1;
        displayMenu();
        while (choice < 0 || choice > 4)
        {
            choice = readInt();
            if (choice == 1)
            {
                inputStartcode();
                printList(l);
            }
            else if (choice == 2)
            {
                int diff = 22;
                while (diff > 21) {
                    dt.ID = inputIDcode();
                    dt.d = inputDate();
                    diff = getDifference(dt.d, tm);

                    if (diff <= 21) {
                        insertIntoList(&l, dt);
                        writeToFile(dt);
                    }
                    else {
                        printf("Can't be more than 21 days in past.\n\n");
                    }
                }   
            }
            else if (choice == 3)
            {
                receiveWarningMsg();
            }
            else if (choice == 4)
            {
                choice = 0;
                exit = false;
            }
            else
            {
                printf("Choose one of the given alternatives.\n");
                choice = 0;
            }
        }
    }
    deleteList(l);
    return 0;
}