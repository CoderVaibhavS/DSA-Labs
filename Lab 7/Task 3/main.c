#include <stdio.h>
#include <stdlib.h>

int power(int n) {
    if(n == 0)  return 1;
    return 10*power(n-1);
}

int *counting_sort(int *A, int *B, int n, int place) {

    int C[10] = {0,0,0,0,0,0,0,0,0,0};
    int p = power(place-1);

    for(int i=0; i<n; i++) {
        C[(A[i]/p)%10]++;
    }

    for(int i=1; i<10; i++) {
        C[i] += C[i-1];
    }

    for(int i=n-1; i>=0; i--) {
        B[C[(A[i]/p)%10]-1] = A[i];
        C[(A[i]/p)%10]--;
    }

    return B;
}

int *straight_radix(int *A, int *B, int n) {
    for(int i=1; i<=3; i++) {    // assuming max no of digits to be 3
        B = counting_sort(A, B, n, i);
        for(int i=0; i<n; i++) {
            A[i] = B[i];
        }
    }
    return B;
}

int main() {

    int arr[7] = {329, 457, 657, 839, 436, 720, 355};
    int *sorted_arr = (int *) malloc(7*sizeof(int));
    sorted_arr = straight_radix(arr, sorted_arr, 7);

    for(int i=0; i<7; i++) {
        printf("%d ", sorted_arr[i]);
    }
    printf("\n");
}