#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "blinker.h"
#include "input.h"
#include "string.h"
#include <time.h>

#define DEBUGON
#ifdef DEBUGON
#define DEBUG(msg) printf("DEBUG: %s\n", msg)
#else 
#define DEBUG(msg)
#endif

int main(int argc, char * argv[]) {

    list l;
    data dt;

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    int ownDevice = 999;
    int infectedCode = 1234;
    int startcode;

    l = createList();

    readFromFile(&l, dt, tm);
    
    int exit = true;

    if (argc == 4) {
        DEBUG("in 'add'\n");
        int diff = 22;
        while (diff > 21) {
            DEBUG("in 'diff loop'\n");
            dt.ID = atoi(argv[2]);
            sscanf(argv[3], "%d%*[.]%d%*[.]%d", &dt.d.day, &dt.d.month, &dt.d.year);
            
            diff = getDifference(dt.d, tm);

            if (diff <= 21) {
                DEBUG("diff is less than 21 days\n");
                sortedInsert(&l, dt);
                writeToFile(dt);
            }
            else {
                DEBUG("diff is more than 21 days\n");
                printf("Can't be more than 21 days in past.\n\n");
            }
        }  
        printf("Registered interaction with device %d on %d.%d.%d\n", dt.ID, dt.d.day, dt.d.month, dt.d.year);
    }
    else if (argc == 3) {
        if (strcmp(argv[1], "sick") == 0) {
            DEBUG("in 'sick'\n");
            sscanf(argv[2], "%d", &startcode);
            printf("Reporting own device %d to server with opening code %d\n", ownDevice, startcode);
        }
        else if (strcmp(argv[1], "check") == 0) {
            DEBUG("in 'check'\n");
            int nr = atoi(argv[2]);

            bool IDInList = search(l, nr);

            if (IDInList == true) {
                receiveWarningMsg();
            }
            else {
                printf("You have not been exposed.\n");
            }
        }
    }
    else if (argc == 2) {
        if (strcmp(argv[1], "debug") == 0) {
            DEBUG("in 'debug'\n");
            printf("Stored interactions\n");
            printList(l);
        }
        else if (strcmp(argv[1], "help") == 0) {
            DEBUG("in 'help'\n");
            printf("Valid commands are\nblinker add <device id> dd.mm.yyyy\nblinker sick <opening code>\nblinker check <device id>\nblinker debug\n");
        }
    }
    else {
        DEBUG("in 'Main program\n");
        printf("Welcome to the coronablinker app!\n\n");
        printf("Current date: %d.%d.%d\n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);

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
                            sortedInsert(&l, dt);
                            writeToFile(dt);
                        }
                        else {
                            printf("Can't be more than 21 days in past.\n\n");
                        }
                    }   
                }
                else if (choice == 3)
                {
                    bool IDInList = search(l, infectedCode);

                    if (IDInList == true) {
                        receiveWarningMsg();
                    }
                    else {
                        printf("You have not been exposed.\n");
                    }
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
    }
    return 0;
}