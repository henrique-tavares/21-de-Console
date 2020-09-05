#pragma once

#include "./hand.h"
#include "./deck.h"

typedef struct Player Player;

struct Player
{
    Hand *hand;

    void (*libera)(Player *self);

    bool (*draw)(Player *self, Deck *deck);
    bool (*stop)(Player *self);
};

Player *cria_player();