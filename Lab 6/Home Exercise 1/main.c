#include <stdio.h>
#include <stdlib.h>
#include "bitsian.h"

void swap(Bitsian bitsians[], int pInd, int lo) {
    Bitsian temp = bitsians[pInd];
    bitsians[pInd] = bitsians[lo];
    bitsians[lo] = temp;
}

int part(Bitsian bitsians[], int lo, int hi, int pInd) {
    swap(bitsians, pInd, lo);
    int left, right, pivPos;
    Bitsian pivot = bitsians[lo]; // isolate pivot to the leftmost position
    left = lo + 1;
    right = hi;

    while(left < right) {
        for(; left <= hi && bitsians[left].rollno[4] == 'A' && (bitsians[left].rollno[5] != 'A' || bitsians[left].rollno[5] != 'B'); left++);

        for(; bitsians[right].rollno[4] == 'B'; right--);

        if(left < right) {
            swap(bitsians, left, right); // int the left partition element is greater and vice versa
            left++;
            right--;
        }
    }

    if(pivot.rollno[4] == 'A' && (bitsians[left].rollno[5] != 'A' || bitsians[left].rollno[5] != 'B') && left <= hi) {
        pivPos = left;
    }
    else {
        pivPos = left-1;
    }
    swap(bitsians, lo, pivPos);

    return pivPos;
}

int main() {

    FILE *fptr;
    fptr = fopen("../bitsians.csv", "r");

    if(fptr == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    char str[10] = "";
    int n = 1028;
    fscanf(fptr, "%s\n", str);


    Bitsian *bitsians = (Bitsian *) malloc(n*sizeof(Bitsian));
    for(int i=0; i<n; i++) {
        fscanf(fptr, "%[^,],%[^\n]\n", bitsians[i].rollno, bitsians[i].name);
    }

    printf("%d\n", part(bitsians, 0, n-1, n-1));

    for(int i=0; i<n; i++) {
        printf("%s %s\n", bitsians[i].rollno, bitsians[i].name);
    }
}