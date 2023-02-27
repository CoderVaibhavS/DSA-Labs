#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>

LIST createNewList() {
    LIST mylist;
    mylist = (LIST) malloc(sizeof(linked_list));
    mylist->count = 0;
    mylist->head = NULL;
    return mylist;
}

NODE createNewNode(int data) {
    NODE mynode;
    mynode = (NODE) malloc(sizeof(node));
    mynode->data = itoe(data);
    mynode->next = NULL;
    return mynode;
}

void insertNodeIntoList(NODE node, LIST list) {
    node->next = list->head;
    list->head = node;
    list->count++;
}

void removeFirstNode(LIST list) {
    if(list->count == 0)
        return;
    NODE temp = list->head;
    list->head = temp->next;
    list->count--;
    free(temp);
}

void insertNodeAtEnd(NODE node, LIST list) {
    NODE temp = list->head;
    if(temp == NULL)
        list->head = node;
    while(temp->next != NULL) 
        temp = temp->next;
    temp->next = node;
    list->count++;
}

Element itoe(int i) {
    Element e;
    e.int_value = i;
    e.float_value = i;
}