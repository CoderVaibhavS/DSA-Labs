#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

void swap(int arr[], int pInd, int lo) {
    int temp = arr[pInd];
    arr[pInd] = arr[lo];
    arr[lo] = temp;
}

int randomPivot(int a, int b) {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    srand(tv.tv_usec * 1000000 + tv.tv_sec);
    return (rand() % (b - a)) + a;
}


int lomuto_part(int arr[], int lo, int hi, int pInd) {
    swap(arr, hi, pInd);
    int i, j;
    int pivot = arr[hi];
    i = lo;
    j = lo;

    while(j < hi) {
        if(arr[j] < pivot) {
            swap(arr, i, j);
            i++;
            j++;
        }

        else {
            j++;
        }
    }
    
    swap(arr, i, j);
    return i;
}

void qs(int arr[], int lo, int hi) {
    if(lo < hi) {
        int p = randomPivot(lo, hi);
        p = lomuto_part(arr, lo, hi, p);
        qs(arr, lo, p-1);
        qs(arr, p+1, hi);
    }
}

int main() {

    FILE *fptr;
    fptr = fopen("../int0.txt", "r");

    if(fptr == NULL) {
        printf("Error opening file\n");
    }

    int arr[1000];
    for(int i=0; i<1000; i++) {
        fscanf(fptr, "%d\n", &arr[i]);
    }

    qs(arr, 0, 999);

    for(int i=0; i<1000; i++) {
        printf("%d\n", arr[i]);
    }
}