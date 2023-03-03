#include <stdio.h>
#include <stdlib.h>
#include "partitioning.h"

int main() {

    Person *persons = (Person *) malloc(1000*sizeof(Person));
    FILE *fptr;

    fptr = fopen("../dat1000.csv", "r");
    if(fptr == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    for(int i=0; i<1000; i++) {
        persons[i].name = (char *) malloc(sizeof(char)*20);
        fscanf(fptr, "%d,%[^,],%d,%d,%d\n", &persons[i].id, persons[i].name, &persons[i].age, &persons[i].height, &persons[i].weight);
    }

    printf("%d\n", part(persons, 0, 999, 999));
    printf("%d\n", lomuto(persons, 0, 999, 999));
    printf("%d\n", threePart(persons, 0, 999, 999));

    // for (int i = 0; i < 1000; i++) {
    //     printf("%d, %s ,%d ,%d ,%d\n", persons[i].id, persons[i].name, persons[i].age, persons[i].height, persons[i].weight);
    // }
}