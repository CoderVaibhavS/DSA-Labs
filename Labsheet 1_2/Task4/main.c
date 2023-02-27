#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void incrementSize(char** stringsArr, int* n) {
    stringsArr = realloc(stringsArr, ((*n)+1)*sizeof(char*));
    (*n)++;
    stringsArr[(*n)-1] = (char*) malloc(100);
}

void fun_a(char** stringsArr, int* n) {
    incrementSize(stringsArr, n);
    printf("Enter the string: ");
    scanf("%s", stringsArr[(*n)-1]);
}

void fun_b(char** stringsArr, int* n) {
    incrementSize(stringsArr, n);
    for(int i=(*n)-1; i>=1; i--) {
        strcpy(stringsArr[i], stringsArr[i-1]);
    }
    printf("Enter the string: ");
    scanf("%s", stringsArr[0]);
}

void fun_c(char** stringsArr, int* n) {
    int x;
    printf("Enter the value of x: ");
    scanf("%d", &x);

    if(x >= *n)   printf("Not a valid index!\n");
    else {
        for(int i=x; i<(*n)-1; i++) {
            strcpy(stringsArr[i], stringsArr[i+1]);
        }
        free(stringsArr[(*n)-1]);
        (*n)--;
    }
}

int main() {

    char option;
    int n;
    printf("Enter the length of the array: ");
    scanf("%d", &n);
    char** stringsArr = (char**) malloc(n*sizeof(char*));

    for(int i=0; i<n; i++) {
        stringsArr[i] = (char*) malloc(100);
        printf("Enter the string: ");
        scanf("%s", stringsArr[i]);
    }
    int flag = 0;

    while(!flag) {
        printf("Choose any of these options - a, b, c, d, e, q: ");
        scanf(" %c", &option);

        switch(option) {
            case 'a':
                fun_a(stringsArr, &n);
                break;

            case 'b':
                fun_b(stringsArr, &n);
                break;

            case 'c':
                fun_c(stringsArr, &n);
                break;

            case 'd':
                printf("Length of array is: %d\n", n);
                break;

            case 'e':
                for(int i=0; i<n; i++) {
                    printf("%s\n", stringsArr[i]);
                }
                break;

            case 'q':
                flag = 1;
                break;

            default:
                printf("Please choose a valid option.\n");
                break;
        }
    }

    return 0;
}