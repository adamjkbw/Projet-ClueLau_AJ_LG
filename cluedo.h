#ifndef CLUEDO_H
#define CLUEDO_H

typedef struct {
    char name[32];
}card;

typedef struct {
    char name[32];
    card cards[24];

}player;


#endif