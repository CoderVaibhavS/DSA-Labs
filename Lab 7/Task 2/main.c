#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int max_ele(int arr[], int n) {
    int k = arr[0];
    for(int i=1; i<n; i++) {
        k = k > arr[i] ? k : arr[i];
    }
    return k;
}

int *preprocess_count(int arr[], int n, int count[], int k) {

    for(int i=0; i<k; i++) {
        count[i] = 0;
    }

    for(int i=0; i<n; i++) {
        count[arr[i]]++;
    }
    return count;
}

bool search(int count[], int k, int key) {
    if(key > k) return false;
    return count[key] > 0 ? true : false;
}

int main() {

    int n;
    FILE *fptr;
    fptr = fopen("../n_integers.txt", "r");

    if(fptr == NULL)    printf("Error opening file\n");
    fscanf(fptr, "%d,[", &n);

    int arr[n];
    for(int i=0; i<n; i++) {
        fscanf(fptr, "%d", &arr[i]);
    }

    int k = max_ele(arr, n);
    int *count = (int *) malloc((k+1)*sizeof(int));
    count = preprocess_count(arr, n, count, k+1);

    int key;
    printf("Enter key to be searched: ");
    scanf("%d", &key);
    if(search(count, k+1, key) == true)   printf("Found\n");
    else    printf("Not found\n");
}