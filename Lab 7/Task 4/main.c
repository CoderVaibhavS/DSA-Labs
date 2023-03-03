#include <stdio.h>

int power(int n) {
    if(n==0)    return 1;
    return 2*power(n-1);
}

int partition(int arr[], int lo, int hi, int div) {
    int pivot = 1, pivPos;
    int left = lo, right = hi;
    while(left < right) {
        for(; left<=hi && (arr[left]/div)%2<pivot; left++);
        for(; (arr[right]/div)%2==pivot; right--);

        if(left < right) {
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
            left++;
            right--;
        }
    }
    if((arr[left]/div)%2 == 1)  pivPos = left-1;
    else    pivPos = left;

    return pivPos;
}

void radix_exchange(int arr[], int lo, int hi, int bit) {
    if(bit < 0) return;
    if(lo < hi) {
        int p = partition(arr, lo, hi, power(bit));
    for(int i=0; i<7; i++) {
        printf("%d ", (arr[i]/power(bit))%2);
    }
    printf("\n");
    for(int i=0; i<7; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
        radix_exchange(arr, lo, p, bit-1);
        radix_exchange(arr, p+1, hi, bit-1);
    }
}

int main() {
    int arr[9] = {29, 75, 57, 39, 36, 20, 55, 12, 100};
    radix_exchange(arr, 0, 8, 9);    // assuming max no of bits 8

    for(int i=0; i<9; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}