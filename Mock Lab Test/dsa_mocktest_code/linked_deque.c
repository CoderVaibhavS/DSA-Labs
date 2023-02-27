#include "linked_deque.h"
// REFER Corresponding header for documentation of functions. 
linked_deque *create_linked_process_deque() {
   // COMPLETE
   linked_deque *ld = (linked_deque *) malloc(sizeof(*ld));
   ld->list = (process_linked_list *) malloc(sizeof(process_linked_list));
}

bool add_first_linked_deque(linked_deque *ld, process p) {
    return add_first_to_linked_list(ld->list, p);
}

bool add_last_linked_deque(linked_deque *ld, process p) {
    // COMPLETE
    return add_last_to_linked_list(ld->list, p);
}

bool remove_first_linked_deque(linked_deque *ld, process *p) {
    // COMPLETE
    return remove_first_linked_list(ld->list, p);
}

bool remove_last_linked_deque(linked_deque *ld, process *p) {
    // COMPLETE
    return remove_last_linked_list(ld->list, p);
}

size_t get_size_linked_deque(linked_deque *ld) {
    // COMPLETE
    return get_size_linked_list(ld->list);
}

bool is_empty_linked_deque(linked_deque *ld) {
    // COMPLETE
    return get_size_linked_deque == 0;
}

void print_linked_deque(linked_deque *ld) {
    print_linked_list(ld->list);
}

void destroy_linked_deque(linked_deque *ld) {
    destroy_linked_list(ld->list);
    free(ld);
}
