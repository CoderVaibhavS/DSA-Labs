#include "array_deque.h"

// Use these functions if you find them helpful or define other static helper functions that might assist you.
// One possible implementation:
// Assume that next_first decrements (or moves left) and rolls back from the other end of the array.
// Assume that next_last increments (or moves right).
// So at any instant, during add_first the element is added to next-first position and next_first is updated accordingly
// Or an element is added at next_last which is then updated accordingly


static unsigned int get_first_index(array_deque *ad);

static unsigned int get_last_index(array_deque *ad);

static unsigned int decrement_index(array_deque *d, size_t index);

static unsigned int increment_index(array_deque *d, size_t index);

static void resize_if_needed(array_deque *d);

static process *create_process(process p);

array_deque *create_empty_process_array_deque() {
    // COMPLETE
    array_deque *ad = (array_deque *) malloc(sizeof(array_deque));
    ad->processes = (process **) calloc(INITIAL_SIZE_ARRAY_DEQUE, sizeof(process *));
    ad->next_first = 0;
    ad->next_last = 1;
    ad->size = 0;
    ad->capacity = INITIAL_SIZE_ARRAY_DEQUE;
    return ad;
}

static unsigned int decrement_index(array_deque *ad, size_t index) {
    index = index - 1;
    if (index == -1) {
        index = ad->capacity - 1;
    }
    return index;
}

static unsigned int increment_index(array_deque *d, size_t index) {
    return (index + 1) % d->capacity;
}

static unsigned int get_first_index(array_deque *ad) {
    return increment_index(ad, ad->next_first);
}

static unsigned int get_last_index(array_deque *ad) {
    return decrement_index(ad, ad->next_last);
}

bool add_first_array_deque(array_deque *ad, process p) {
    // COMPLETE
    if(ad->capacity == 0)   return false;
    resize_if_needed(ad);
    ad->size++;
    ad->processes[ad->next_first] = create_process(p);
    ad->next_first = decrement_index(ad, ad->next_first);
    return true;
}

static process *create_process(process p) {
    process *pro = malloc(sizeof(process));
    if (!pro) return NULL;
    *pro = p;
    return pro;
}

bool add_last_array_deque(array_deque *ad, process p) {
    // COMPLETE
    if(ad->capacity == 0)   return false;
    resize_if_needed(ad);
    ad->size++;
    ad->processes[ad->next_last] = create_process(p);
    ad->next_last = increment_index(ad, ad->next_last);
    return true;
}

bool remove_first_array_deque(array_deque *ad, process *p) {
    // COMPLETE
    if(ad->size == 0)   return false;
    resize_if_needed(ad);
    ad->size--;
    free(ad->processes[get_first_index(ad)]);
    ad->next_first = increment_index(ad, ad->next_first);
    return true;
}

bool remove_last_array_deque(array_deque *ad, process *p) {
    // COMPLETE
    if(ad->size == 0)   return false;
    resize_if_needed(ad);
    ad->size--;
    free(ad->processes[get_last_index(ad)]);
    ad->next_last = decrement_index(ad, ad->next_last);
    return true;
}

size_t get_size_array_deque(array_deque *ad) {
    return ad->size;
}

static void resize_if_needed(array_deque *ad) {
    if (ad->size < ad->capacity) {
        return;
    }
    // COMPLETE
    if(ad->size == ad->capacity) {
        process **temp = ad->processes;
        ad->processes = (process **) calloc(2*ad->capacity, sizeof(process*));
        int idx = 0;
        for(int i=get_first_index(ad); i<get_size_array_deque(ad); i++) {
            ad->processes[idx++] = temp[i];
        }
        if(get_first_index(ad) >= get_last_index(ad)) {
            for(int i=0; i<=get_last_index(ad); i++) {
                ad->processes[idx++] = temp[i];
            }
        }
        ad->capacity *= 2;
        ad->next_first = ad->capacity - 1;
        ad->next_last = idx;
    }
}

void print_array_deque(array_deque *ad) {
    if(get_first_index(ad) <= get_last_index(ad)) {
        for(int i=get_first_index(ad); i<=get_last_index(ad); i++) {
            printf("%d => ", ad->processes[i]->pid);
        }
    }
    else {
        for(int i=get_first_index(ad); i < ad->capacity; i++) {
            printf("%d => ", ad->processes[i]->pid);
        }
        for(int i=0; i<= get_last_index(ad); i++) {
            printf("%d => ", ad->processes[i]->pid);
        }
    }
    printf("\n");
}
