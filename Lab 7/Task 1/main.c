#include <stdio.h>
#include <stdlib.h>

char* counting_sort(char *A, char *B, int k, int n) {
    int C[k];
    for(int i=0; i<k; i++) {
        C[i] = 0;
    }

    for(int i=0; i<n; i++) {
        C[A[i] - 'a']++;
    }

    for(int i=1; i<k; i++) {
        C[i] += C[i-1];
    }

    for(int i=n-1; i>=0; i--) {
        B[C[A[i] - 'a']- 1] = A[i];
        C[A[i] - 'a']--;
    }
    return B;
}

int main() {
    char str[10] = "dbamiwnkwv";
    char *sorted_str = (char *) malloc(10*sizeof(char));
    sorted_str = counting_sort(str, sorted_str, 27, 10);

    printf("%s\n", sorted_str);
}