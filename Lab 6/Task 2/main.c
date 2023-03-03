#include <stdio.h>

void swap(int arr[], int pInd, int lo) {
    int temp = arr[pInd];
    arr[pInd] = arr[lo];
    arr[lo] = temp;
}

int part(int arr[], int lo, int hi, int pInd) {
    swap(arr, pInd, lo);
    int left, right, pivPos;
    int pivot = arr[lo]; // isolate pivot to the leftmost position
    left = lo + 1;
    right = hi;

    while(left < right) {
        for(; left <= hi && arr[left] <= pivot; left++);

        for(; arr[right] > pivot; right--);

        if(left < right) {
            swap(arr, left, right); // int the left partition element is greater and vice versa
            left++;
            right--;
        }
    }

    if(arr[left] < pivot && left <= hi) {
        pivPos = left;
    }
    else {
        pivPos = left-1;
    }
    swap(arr, lo, pivPos);

    return pivPos;
}

int main() {

    int arr[10] = {0, 1, 1, 1, 0, 1, 0, 0, 1, 0};
    part(arr, 0, 9, 9);
    for(int i=0; i<10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}