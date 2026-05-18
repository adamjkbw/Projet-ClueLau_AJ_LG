#include "cluedo.h"

#include <time.h>
#include <stdlib.h>

int main() {
    srand(time(NULL));

    player* listeParticipants[6] = {NULL};
    card*
    int nbJoueurs = 0;

    addParticipants(listeParticipants, &nbJoueurs);

    for (int i = 0; i < nbJoueurs; i++) {
        free(listeParticipants[i]);
    }

    return 0;
}
