#include "partitioning.h"

void swap(Person persons[], int pInd, int lo) {
    Person temp = persons[pInd];
    persons[pInd] = persons[lo];
    persons[lo] = temp;
}

int part(Person persons[], int lo, int hi, int pInd) {
    swap(persons, pInd, lo);
    int left, right, pivPos;
    Person pivot = persons[lo]; // isolate pivot to the leftmost position
    left = lo + 1;
    right = hi;

    while(left < right) {
        for(; left <= hi && persons[left].height <= pivot.height; left++);

        for(; persons[right].height > pivot.height; right--);

        if(left < right) {
            swap(persons, left, right); // int the left partition element is greater and vice versa
            left++;
            right--;
        }
    }

    if(persons[left].height < pivot.height && left <= hi) {
        pivPos = left;
    }
    else {
        pivPos = left-1;
    }
    swap(persons, lo, pivPos);

    return pivPos;
}

int lomuto(Person persons[], int lo, int hi, int pInd) {
    swap(persons, hi, pInd);
    int i, j;
    Person pivot = persons[hi];
    i = lo;
    j = lo;

    while(j < hi) {
        if(persons[j].height < pivot.height) {
            swap(persons, i, j);
            i++;
            j++;
        }

        else {
            j++;
        }
    }
    
    swap(persons, i, j);
    return i;
}

int threePart(Person persons[], int lo, int hi, int pInd) {
    swap(persons, pInd, hi);
    int left, right, mid;
    Person pivot = persons[hi];
    left = lo;
    right = hi - 1;
    mid = lo;

    while(mid <= right) {
        if(persons[mid].height < pivot.height) {
            swap(persons, left, mid);
            left++;
            mid++;
        }

        else if(persons[mid].height > pivot.height) {
            swap(persons, mid, right);
            right--;
        }

        else {
            mid++;
        }
    }
    
    swap(persons, mid, hi);

    return mid;
}