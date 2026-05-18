#include "cluedo.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void addName(player *self)
{
    // Cette fonction sert a rajouter un nom custom à un joueur
    printf("Quel est le nom du joueur? : ");
    if (scanf("%31s", self->name) == 1)
    {
        system("cls");
        printf("%s a ete ajoute.\n", self->name);
    }
}

player *addPlayer()
{
    // cette fonction sert a creer un joueur
    player *newP = malloc(sizeof(player));
    newP->ai = 0;
    if (newP != NULL)
    {
        addName(newP);
    }

    for (int i = 0; i < 24; i++)
    {
        newP->cards[i].name[0] = '\0';
    }

    return newP;
}

player *createAi()
{
    // cette fonction permet de créer un joueur spécifiquement de type IA

    player *newP = malloc(sizeof(player));
    newP->ai = 1;

    const char *names[] = {
        "Silas", "Elena", "Arthur", "Clara", "Julian", "Beatrix", "Victor", "Lydia", "Sebastian", "Evelyn"};

    int nameCount = sizeof(names) / sizeof(names[0]);

    int randomIndex = rand() % nameCount;
    strncpy(newP->name, names[randomIndex], 31);
    newP->name[31] = '\0';

    for (int i = 0; i < 24; i++)
    {
        newP->cards[i].name[0] = '\0';
    }

    system("cls");
    printf("%s a ete rajoute\n", newP->name);

    return newP;
}

void addParticipants(player *participants[], int *count)
{
    // Cette fonction remplit le tableau de joueurs jusqu'à être au maximum (6) ou jusqu'à ce que l'user décide de l'arrêter
    //  il prend en paramètre un tableau de type joueur
    int loop = 0;
    char choice;
    char choice2;
    while (loop == 0 && *count <= 6)
    {
        printf("Voulez vous rajouter un participant? (O/N)\n");
        scanf(" %c", &choice);
        if (choice == 'O')
        {
            printf("IA ou joueur? (I/J)\n");
            scanf(" %c", &choice2);

            if (choice2 == 'J')
            {
                participants[*count] = addPlayer();
                (*count)++;
            }

            else if (choice2 == 'I')
            {
                participants[*count] = createAi();
                (*count)++;
            }

            choice = ' ';
            choice2 = ' ';
        }
        else if (choice == 'N')
        {
            loop = 1;
        }
    }
}

void initCards(card *cardList[])
{
    const char *nomsCartes[18] = {
        // Suspects
        "Mlle Rose", "Col. Moutarde", "Prof. Violet", "Mme Blanche", "Dr Olive", "Mme Pervenche",
        // Armes
        "Poignard", "Chandelier", "Revolver", "Corde", "Cle Anglaise", "Tuyau de Plomb",
        // Pièces
        "Cuisine", "Grand Salon", "Veranda", "Petit Salon", "Salle a Manger", "Bureau"};

    for (int i = 0; i < 18; i++)
    {
        // Allocation de la mémoire pour UNE carte
        cardList[i] = malloc(sizeof(card));

        if (cardList[i] != NULL)
        {
            strncpy(cardList[i]->name, nomsCartes[i], 31);
            cardList[i]->name[31] = '\0';
        }
        else
        {
            printf("Erreur d'allocation mémoire pour la carte %d\n", i);
        }
    }
}

void melangerCartes(card *listeCartes[18])
{
    for (int i = 17; i > 0; i--)
    {
        // Choisit un index aléatoire entre 0 et i
        int j = rand() % (i + 1);

        // Échange les pointeurs
        card *temp = listeCartes[i];
        listeCartes[i] = listeCartes[j];
        listeCartes[j] = temp;
    }
}

void distribCartes(player *participants[], card *listCards[], int count)
{

    melangerCartes(listCards);

    int indexCarteJoueur[6] = {0};
    int joueurActuel = 0;

    for (int i = 0; i < count * 3; i++)
    {
        player *p = participants[joueurActuel];
        int positionDansSonDeck = indexCarteJoueur[joueurActuel];

        strncpy(p->cards[positionDansSonDeck].name, listCards[i]->name, 31);
        p->cards[positionDansSonDeck].name[31] = '\0';

        indexCarteJoueur[joueurActuel]++;

        joueurActuel = (joueurActuel + 1) % count;
    }
    printf("Toutes les cartes ont ete distribuees !\n");
}

void menu()
{
    int choix;
    printf("===== Menu Cluelau =====\n");
    print("C'est le tour de %s \n", );
    printf("1. Se deplacer (obligatoire)\n");
    printf("2. Formuler une hypothese\n");
    printf("3. Faire une accusation \n");
    scanf("%d", choix);
}