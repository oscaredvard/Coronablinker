#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

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
    struct node * prev;
    data dt;
    struct node * next;
} node;

//Blinker functions
void displayMenu(void);
int inputStartcode(void);
int inputIDcode(void);
date inputDate(void);
void receiveWarningMsg(void);

//Date functions
int countLeapYears(date d);
int getDifference(date d, struct tm tm);

//List functions
typedef node * list;
list createList(void);
bool isEmpty(list l);
bool sortedInsert(list * headptr, data dt);
void printNode(data dt);
bool printList(list l);
bool printReverse(list l);
bool deleteList(list l);
bool search(list l, int x);
int cmpData(data x, data y);

//File functions
void writeToFile(void);
void appendFile(list l);
void readFromFile(list * headptr, struct tm tm);