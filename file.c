#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "blinker.h"
#include "input.h"

void writeToFile(data dt)
{
    char * fname = "list.txt";
    FILE * fptr;
    fptr = fopen(fname, "a");
    
    if (fptr==NULL)
    {
        printf("File couldn't be opened/doesn't exist.");
    }
    else
    {
        fprintf(fptr, " %d\n", dt.ID);
        fprintf(fptr, "%d.%d.%d\n", dt.d.day, dt.d.month, dt.d.year);
    }
    fclose(fptr);
}

void readFromFile(list * headptr, data dt, struct tm tm)
{
    char * fname = "list.txt";
    FILE * fptr;
    fptr = fopen(fname, "r");

    date tmp;

    int c;
    while((c = getc(fptr)) != EOF)
    {
        node * new_node;
        new_node = (node *) malloc(sizeof(node));
        fscanf(fptr, "%d", &new_node->dt.ID);
        fscanf(fptr, "%d.%d.%d\n", &tmp.day, &tmp.month, &tmp.year);
        
        if (getDifference(tmp, tm) <= 21)
        {
            new_node->dt.d.day = tmp.day;
            new_node->dt.d.month = tmp.month;
            new_node->dt.d.year = tmp.year;
        }

        if (*headptr == NULL) {
        *headptr = new_node;
        new_node->next = NULL;
        }
        else {
        new_node->next = *headptr;
        *headptr = new_node;
        }
    }
    fclose(fptr);
}