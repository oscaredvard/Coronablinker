#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "blinker.h"
#include "input.h"

int main(void)
{
    list l;
    data dt;

    l = createList();
    
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
                dt.ID = inputIDcode();
                dt.d = inputDate();
                insertIntoList(&l, dt);
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
    return 0;
}