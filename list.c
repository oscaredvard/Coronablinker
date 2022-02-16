#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "blinker.h"

list createList(void) {
    return NULL;
}

bool isEmpty(list l)
{
    if (l == NULL) {
        return true;
    }
    else {
        return false;
    }
}

void insertIntoList(list * headptr, data dt) {
    node * new_node;

    //Allocate data to the node
    new_node = (node *) malloc(sizeof(node));

    //Add data to node
    new_node->dt = dt;

    //Insert node into list
    //Case 1: List is empty
    if (*headptr == NULL) {
        *headptr = new_node;
        new_node->next = NULL;
    }
    //Case 2: List has content
    else {
        new_node->next = *headptr;
        *headptr = new_node;
    }
}

void printNode(data dt) {
    printf("Date: %d.%d.%d\n", dt.d.day, dt.d.month, dt.d.year);
    printf("ID Code: %d\n\n", dt.ID);
}

void printList(list l) {
    node * current_node;
    current_node = l;

    while(current_node != NULL) {
        //Print content of current node
        printNode(current_node->dt);
        //Go to next node
        current_node = current_node->next;
    }
}

void deleteList(list l)
{
   node * current_node = l;
   node * next;
 
   while (current_node != NULL)
   {
       next = current_node->next;
       free(current_node);
       current_node = next;
   }
   
   l = NULL;
}
 