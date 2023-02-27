#include <stdio.h>
#include <stdlib.h>

typedef struct Person
{
    int id;
    char name[100];
    int age;
    int height;
    int weight;
} Person;

void insertInOrder(Person person, Person *persons, int last) {
    int i = last-1;
    while(i >= 0 && person.height < persons[i].height) {
        persons[i+1] = persons[i];
        i--;
    }
    persons[i+1] = person;
}

void insertionSort(Person *persons, int n) {
    for(int i=0; i<n; i++) {
        insertInOrder(persons[i], persons, i);
    }
}

int main()
{

    Person *persons = (Person*) malloc(1000 * sizeof(Person));
    FILE *fptr;

    fptr = fopen("dat1000.csv", "r");
    if (fptr == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }
    else
    {
        printf("File opened!\n");
    }

    for (int i = 0; i < 1000; i++)
    {
        fscanf(fptr, "%d,%[^,],%d,%d,%d\n", &persons[i].id, persons[i].name, &persons[i].age, &persons[i].height, &persons[i].weight);
    }
    insertionSort(persons, 1000);

    for (int i = 0; i < 1000; i++)
    {
        printf("%d ,%s ,%d ,%d ,%d\n", persons[i].id, persons[i].name, persons[i].age, persons[i].height, persons[i].weight);
    }
}