#include <stdio.h>
#include <stdlib.h>

void mergeAux(int L1[], int s1, int e1, int L2[], int s2, int e2, int L3[], int s3, int e3) {
    
    int i = s1, j = s2, k = s3;

    while(i <= e1 && j <= e2) {
        if(L1[i] < L2[j])
            L3[k++] = L1[i++];
        else
            L3[k++] = L2[j++];
    }

    while(i <= e1)
        L3[k++] = L1[i++];

    while(j <= e2)
        L3[k++] = L2[j++];
}

void merge(int A[], int s, int mid, int e) {
    int *C = (int *) malloc((sizeof(int)) * (e-s+1));
    mergeAux(A, s, mid, A, mid+1, e, C, 0, e-s);
    for(int i=0; i<e-s+1; i++) {
        A[s+i] = C[i];
    }
    free(C);
}

void mergeSort(int arr[], int s, int e) {
    int mid = s + (e-s)/2;
    if(e-s > 1) {
    mergeSort(arr, s, mid);
    mergeSort(arr, mid+1, e);
    }
    merge(arr, s, mid, e);
}

int main() {

    int arr[5] = {32,5,4,12,7};
    mergeSort(arr, 0, 4);
    for(int i=0; i<5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}