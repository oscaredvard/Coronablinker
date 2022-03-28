#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "blinker.h"
#include "input.h"

#define DEBUGON
#ifdef DEBUGON
#define DEBUG(msg) printf("DEBUG: %s\n", msg)
#else 
#define DEBUG(msg)
#endif

void writeToFile() {
    char * fname = "list.bin";
    FILE * fptr;
    fptr = fopen(fname, "wb");
    fclose(fptr);
}

void appendFile(list l) {
    char * fname = "list.bin";
    FILE * fptr;
    fptr = fopen(fname, "ab");
    
    if (fptr==NULL)
    {
        printf("File couldn't be opened/doesn't exist.");
    }
    else
    {
        node * current_node;
        current_node = l;

        while (current_node != NULL) {
        fwrite(&current_node->dt, sizeof(data), 1, fptr);
        current_node = current_node->next;
        }
    }
    fclose(fptr);
}

void readFromFile(list * headptr, struct tm tm)
{
    DEBUG("in 'readFromFile'");
    char * fname = "list.bin";
    FILE * fptr;
    fptr = fopen(fname, "rb");

    int fresult = 1;

    date tmp;

    while(fresult != 0)
    {
        DEBUG("in 'readFromFile': main loop");
        node * new_node;
        new_node = (node *) malloc(sizeof(node));
        node * last = *headptr;
        fresult = fread(&new_node->dt, sizeof(data), 1, fptr);
        printf("fresult: %d\n", fresult);

        if (fresult != 0) {
            DEBUG("in 'readFromFile': main loop: if (fread)");
            fscanf(fptr, "%d.%d.%d\n", &tmp.day, &tmp.month, &tmp.year);

            if (getDifference(tmp, tm) <= 21) {
                DEBUG("in 'readFromFile': main loop: if (getDifference)");
                new_node->dt.d.day = tmp.day;
                new_node->dt.d.month = tmp.month;
                new_node->dt.d.year = tmp.year;
            }

            if (*headptr == NULL) {
                DEBUG("in 'readFromFile': main loop: if (*headptr == NULL)");
                *headptr = new_node;
                new_node->next = NULL;
                new_node->prev = NULL;
            }
            else {
                DEBUG("in 'readFromFile': main loop: else");
                while (last->next != NULL) {
                    last = last->next;
                }
                last->next = new_node;
                new_node->prev = last;
            }
        }
    }
    fclose(fptr);
}