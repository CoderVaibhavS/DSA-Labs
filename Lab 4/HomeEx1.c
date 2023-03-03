#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    while(i >= 0 && strcmp(person.name, persons[i].name) < 0) {
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

int main() {

    Person* persons = (Person*) malloc(5*sizeof(Person));
    persons[0].id = 1;
    strcpy(persons[0].name, "Sokka");
    persons[0].age = 15;
    persons[0].height = 150;
    persons[0].weight = 45;

    persons[1].id = 2;
    strcpy(persons[1].name, "Aang");
    persons[1].age = 112;
    persons[1].height = 137;
    persons[1].weight = 35;

    persons[2].id = 3;
    strcpy(persons[2].name, "Zuko");
    persons[2].age = 16;
    persons[2].height = 160;
    persons[2].weight = 50;

    persons[3].id = 4;
    strcpy(persons[3].name, "Katara");
    persons[3].age = 14;
    persons[3].height = 145;
    persons[3].weight = 38;

    persons[4].id = 5;
    strcpy(persons[4].name, "Toph");
    persons[4].age = 12;
    persons[4].height = 113;
    persons[4].weight = 30;

    insertionSort(persons, 5);

    for(int i=0; i<5; i++) {
        printf("ID: %d, Name: %s, Age: %d, Height: %d, Weight: %d\n", persons[i].id, persons[i].name, persons[i].age, persons[i].height, persons[i].weight);
    }
}