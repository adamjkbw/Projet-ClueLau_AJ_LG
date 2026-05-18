#ifndef CLUEDO_H
#define CLUEDO_H

typedef struct {
    char name[32];
}card;

typedef struct player{
    char name[32];
    card cards[24];
    int ai;

}player;

void addName(player* self);
player* addPlayer ();
player* createAi();
void addParticipants(player* participants[], int* count);
void initCards (card* list[18]);
void melangerCartes(card* listeCartes[18]);
void distribCartes(player* participants[], card* listCards[], int count);


#endif
