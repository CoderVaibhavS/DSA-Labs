#include "linkedlist.h"
#include <stdio.h>

static node *create_node_for_list(process p);
// Check header files for documentation/ function description
process_linked_list *create_empty_process_linked_list() {
    // COMPLETE
    process_linked_list *list = (process_linked_list *) malloc(sizeof(*list));
    list->head = NULL;
    list->size = 0;
    return list;
}

bool add_first_to_linked_list(process_linked_list *list, process p) {
    return add_at_index_linked_list(list, 0, p);
}

bool add_last_to_linked_list(process_linked_list *list, process p) {
    return add_at_index_linked_list(list, list->size, p);
}

bool add_at_index_linked_list(process_linked_list *list, size_t index, process p) {
   // COMPLETE
    node *n = create_node_for_list(p);
    if(index > list->size)  return false;
    node *temp = list->head;
    if(n == NULL)   return false;
    if(list->size == 0) {
        list->head = n;
    }
    else if(index == 0) {
        list->head = n;
        n->next = temp;
        temp->previous = list->head;
    }
    else {
        for(int i=1; i<index; i++) {
            temp = temp->next;
        }
        n->next = temp->next;
        n->previous = temp;
        temp->next = n;
        if(n->next != NULL) {
            n->next->previous = n;
        }
    }
    list->size++;
    return true;
}

bool remove_first_linked_list(process_linked_list *list, process *p) {
    if (list->size == 0) {
        return false;
    }
    // COMPLETE
    node *temp = list->head;
    *p = *(temp->process);
    list->head = temp->next;
    if(list->head != NULL) {
     list->head->previous = NULL;
    }

    free(temp);
    list->size--;
    return true;
}

bool remove_last_linked_list(process_linked_list *list, process *p) {
    if (list->size == 0) {
        return false;
    }
    // COMPLETE
    node *temp = list->head;
    while(temp->next != NULL) {
     temp = temp->next;
    }
    *p = *(temp->process);
    if(temp->previous != NULL) {
     temp->previous->next = NULL;
     free(temp);
     list->size--;
    }
    else {
     remove_first_linked_list(list, p);
    }
    return true;
}

size_t get_size_linked_list(process_linked_list *list) {
    return list->size;
}

void print_linked_list(process_linked_list *list) {
    node *tracker = list->head;
    for (int i = 0; i < list->size; ++i) {
        printf("%d => ", tracker->process->pid);
        tracker = tracker->next;
    }
    printf("%s", "\n");
}

static node *create_node_for_list(process p) {
    process *to_add_process = malloc(sizeof(process));
    if (!to_add_process) {
        return NULL;
    }
    *to_add_process = p;
    node *new_node = malloc(sizeof(node));
    if (!new_node) {
        return NULL;
    }
    new_node->process = to_add_process;
    new_node->next = NULL;
    new_node->previous = NULL;
    return new_node;
}


void destroy_linked_list(process_linked_list *list) {
    node *current = list->head->next;
    for (int i = 0; i < list->size; ++i) {
        node *next = current->next;
        free(current->process);
        current = next;
    }
    free(list->head);
    free(list);
}
