#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "utils.h"

int main(void)
{
    int startkod, id = 0;
    int exit = 0;
    struct date *d;

    printf("V%clkommen till coronablinkern.\n", 132);

    while (exit == false)
    {
        int choice = 0;
        displayMenu();
        while (choice < 1 || choice > 3)
        {
            printf("Val: ");
            scanf("%d", &choice);
            if (choice == 1)
            {
                printf("S%ctt in startkod: ", 132);
                scanf("%d", &startkod);
                printf("Startkod mottagen. S%cnder information till servern.\n", 132);
            }
            else if (choice == 2)
            {
                printf("S%ctt in inmatningskod: ", 132);
                scanf("%d", &id);
                inputDate(d);
                printf("Du har varit i n%crkontakt med n%cgon som %cr smittad av covid-19. Du uppmanas vara i karant%cn tillsvidare.\n", 132, 134, 132, 132);
            }
            else if (choice == 3)
            {
                exit = true;
            }
            else
            {
                printf("V%clj ett av de givna alternativen.\n", 132);
            }
        }
    }
    return 0;
}