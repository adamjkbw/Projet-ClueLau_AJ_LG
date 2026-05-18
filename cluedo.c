#include "cluedo.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void addName(player* self) {
    //Cette fonction sert a rajouter un nom custom à un joueur
    printf("Quel est le nom du joueur? : ");
    if (scanf("%31s", self->name) == 1) {
        system("cls");
        printf("%s a ete ajoute.\n", self->name);
    }
}

player* addPlayer () {
    // cette fonction sert a creer un joueur
    player* newP = malloc(sizeof(player));
    newP->ai = 0;
    if (newP != NULL) {
        addName(newP);
    }

    for(int i = 0; i < 24; i++) {
            newP->cards[i].name[0] = '\0';
        }

    return newP;

}

player* createAi() {
    //cette fonction permet de créer un joueur spécifiquement de type IA

    player* newP = malloc(sizeof(player));
    newP->ai = 1;

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

void addParticipants (player* participants[], int* count) {
    //Cette fonction remplit le tableau de joueurs jusqu'à être au maximum (6) ou jusqu'à ce que l'user décide de l'arrêter
    // il prend en paramètre un tableau de type joueur
    int loop = 0;
    char choice;
    char choice2;
    while (loop == 0 && *count <= 6) {
        printf("Voulez vous rajouter un participant? (O/N)\n");
        scanf(" %c", &choice);
        if (choice == 'O') {
            printf("IA ou joueur? (I/J)\n");
            scanf(" %c", &choice2);

            if (choice2 == 'J') {
                participants[*count] = addPlayer();
                (*count)++;
            }

            else if (choice2 == 'I') {
                participants[*count] = createAi();
                (*count)++;
            }

            choice = ' ';
            choice2 = ' ';

        }
        else if (choice == 'N') {
            loop = 1;
        }

    }

}

distribCartes(player* participants, int* count) {

}
