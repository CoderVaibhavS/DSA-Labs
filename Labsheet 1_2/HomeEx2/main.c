#include <stdio.h>
#include <stdlib.h>

typedef struct occupant {
    char name[20];
    int age;
    char address[100];
} Occupant;

typedef struct hotel {
    char name[20];
    char address[100];
    int rooms;
    Occupant** occupants;
} Hotel;

int main() {

    char option;
    Hotel TGH = {"", "", 0};
    printf("Enter hotel name: ");
    scanf("%s", TGH.name);
    printf("Enter hotel address: ");
    scanf("%s", TGH.address);

    int flag = 0;
    while(!flag) {
        printf("Press 1, 2, 3, 4 or q.\n");
        scanf(" %c", &option);
        Occupant* occ = (Occupant*) malloc(sizeof(Occupant));

        switch(option) {
            case '1':
                (TGH.rooms)++;
                TGH.occupants = (Occupant**) realloc(TGH.occupants, (TGH.rooms)*sizeof(Occupant*));
                printf("Enter name: ");
                scanf("%s", occ->name);
                printf("Enter age: ");
                scanf("%d", &(occ->age));
                printf("Enter address: ");
                scanf("%s", occ->address);
                TGH.occupants[TGH.rooms-1] = occ;
                printf("%d", TGH.rooms);
                break;

            case '2':
                (TGH.rooms)++;
                TGH.occupants = (Occupant**) realloc(TGH.occupants, (TGH.rooms)*sizeof(Occupant*));
                printf("Enter name: ");
                scanf("%s", occ->name);
                printf("Enter age: ");
                scanf("%d", &(occ->age));
                printf("Enter address: ");
                scanf("%s", occ->address);
                for(int i=TGH.rooms-1; i>0; i--) {
                    TGH.occupants[i] = TGH.occupants[i-1];
                }
                TGH.occupants[0] = occ;
                break;
        }
    }
}