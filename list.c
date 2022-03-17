#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "blinker.h"

#define DEBUGON
#ifdef DEBUGON
#define DEBUG(msg) printf("DEBUG: %s\n", msg)
#else 
#define DEBUG(msg)
#endif

list createList(void) {
    
    return NULL;
}

bool isEmpty(list l)
{
    if (l == NULL) {
        DEBUG("List is empty\n");
        return true;
    }
    else {
        DEBUG("List is not empty\n");
        return false;
    }
}

bool sortedInsert(list * headptr, data dt) {
    DEBUG("in 'sortedInsert'\n");
    node * new_node;

    new_node = (node *) malloc(sizeof(node));

    new_node->dt = dt;

    node * current;

    if (*headptr == NULL || (cmpData((*headptr)->dt, new_node->dt) == 1 || cmpData((*headptr)->dt, new_node->dt) == 2)) {
        DEBUG("Special case\n");
        new_node->next = *headptr;
        *headptr = new_node;
        return 1;
    }
    else {    
        DEBUG("Locating node\n");
        current = *headptr;
        while (current->next != NULL && cmpData(current->next->dt, new_node->dt) == -1) {
            DEBUG("in loop\n");
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
        return 1;
    }
    return 0;
}

int cmpData(data x, data y) {
    DEBUG("in 'cmpData'\n");
    if (x.d.month > y.d.month) {
        DEBUG("Month is larger (1)\n");
        return 1;
    }
    else if (x.d.month < y.d.month) {
        DEBUG("Month is smaller (-1)\n");
        return -1;
    }
    else if (x.d.month == y.d.month) {
        DEBUG("Months are the same\n");
        if (x.d.day > y.d.day) {
            DEBUG("Day is larger (1)\n");
            return 1;
        }
        else if (x.d.day < y.d.day) {
            DEBUG("Day is smaller (-1)\n");
            return -1;
        }
        else if (x.d.day == y.d.day) {
            DEBUG("Days are the same (2)\n");
            return 2;
        }
    }
    return 0;
}

void printNode(data dt) {
    DEBUG("in 'printNode'\n");
    printf("Date: %d.%d.%d\n", dt.d.day, dt.d.month, dt.d.year);
    printf("ID Code: %d\n\n", dt.ID);
}

bool printList(list l) {
    DEBUG("in 'printList'\n");
    node * current_node;
    current_node = l;

    while(current_node != NULL) {
        //Print content of current node
        printNode(current_node->dt);
        //Go to next node
        current_node = current_node->next;
    }
    return 1;
}

bool deleteList(list l)
{
   DEBUG("in 'deleteList\n");
   node * current_node = l;
   node * next;
 
   while (current_node != NULL)
   {
       next = current_node->next;
       free(current_node);
       current_node = next;
   }
   
   l = NULL;

   return 1;
}

bool search(list l, int x)
{
    DEBUG("in 'search'\n");
    node * current_node;
    current_node = l;
    
    while (current_node != NULL)
    {
        if (current_node->dt.ID == x) {
            DEBUG("Found matching ID\n");
            return true;
        }
        current_node = current_node->next;
    }
    DEBUG("Didn't find matching ID\n");
    return false;
}