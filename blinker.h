#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct date_struct {
    int day;
    int month;
    int year;
} date;

typedef struct data {
    date d;
    int ID;
} data;

typedef struct node {
    data dt;
    struct node * next;
} node;

//Blinker functions
void displayMenu(void);
void inputStartcode(void);
int inputIDcode(void);
date inputDate(void);
void receiveWarningMsg(void);

//List functions
typedef node * list;
list createList(void);
bool isEmpty(list l);
void insertIntoList(list * headptr, data dt);
void printNode(data dt);
void printList(list l);
