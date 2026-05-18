#include "cluedo.h"

#include <time.h>
#include <stdlib.h>

int main()
{
    srand(time(NULL));

    player *listeParticipants[6] = {NULL};
    card *listeCartes[18] = {NULL};
    initCards(listeCartes);
    int nbJoueurs = 0;
    const char *pieces[6] = {
        "1.Cuisine",
        "2.Grand Salon",
        "3.Veranda",
        "4.Petit Salon",
        "5.Salle a Manger",
        "6.Bureau"};

    addParticipants(listeParticipants, &nbJoueurs);
    distribCartes(listeParticipants, listeCartes, nbJoueurs);

    for (int i = 0; i < nbJoueurs; i++)
    {
        free(listeParticipants[i]);
    }

    return 0;
}
