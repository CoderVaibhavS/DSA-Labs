#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "Element.h"

struct node {
    Element data;
    struct node *next;
};

typedef struct node node;
typedef node * NODE;

struct linked_list {
    int count;
    NODE head;
};

typedef struct linked_list linked_list;
typedef linked_list * LIST;

LIST createNewList();

NODE createNewNode(int data);

void insertNodeIntoList(NODE node, LIST list);

void removeFirstNode(LIST list);

void insertNodeAtEnd(NODE node, LIST list);

#endif