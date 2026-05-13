#ifndef CLUEDO_H
#define CLUEDO_H

typedef struct {
    char name[32];
}card;

typedef struct {
    char name[32];
    card cards[24];

}player;

typedef struct {
    char name[32];
    card cards[24];
}ai;

void addName(player* self);
player* addPlayer ();
ai* createAi();
void addParticipants();

#endif
