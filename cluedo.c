#include "cluedo.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void addName(player* self) {
    printf("Quel est le nom du joueur? : ");
    if (scanf("%31s", self->name) == 1) {
        system("cls");
        printf("%s a ete ajoute.\n", self->name);
    }
}

player* addPlayer () {
    player* newP = malloc(sizeof(player));
    if (newP != NULL) {
        addName(newP);
    }

    for(int i = 0; i < 24; i++) {
            newP->cards[i].name[0] = '\0';
        }

    return newP;

}

ai* createAi() {

    ai* newP = malloc(sizeof(ai));

    const char* names[] = {
        "Silas", "Elena", "Arthur", "Clara", "Julian", "Beatrix", "Victor", "Lydia", "Sebastian", "Evelyn"
    };

    int nameCount = sizeof(names) / sizeof(names[0]);

    int randomIndex = rand() % nameCount;
        strncpy(newP->name, names[randomIndex], 31);
        newP->name[31] = '\0';


    for(int i = 0; i < 24; i++) {
            newP->cards[i].name[0] = '\0';
        }

    system("cls");
    printf("%s a ete rajoute\n", newP->name);


    return newP;
}

void addParticipants () {
    int loop = 0;
    char choice;
    char choice2;
    while (loop == 0) {
        printf("Voulez vous rajouter un participant? (O/N)\n");
        scanf(" %c", &choice);
        if (choice == 'O') {
            printf("IA ou joueur? (I/J)\n");
            scanf(" %c", &choice2);

            if (choice2 == 'J') {
                player* p = addPlayer();
            }

            else if (choice2 == 'I') {
                ai* a = createAi();
            }

            choice = ' ';
            choice2 = ' ';

        }
        else if (choice == 'N') {
            loop = 1;
        }

    }

}
