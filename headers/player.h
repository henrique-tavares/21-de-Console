#pragma once

#include "./hand.h"
#include "./deck.h"

typedef struct Player Player;

struct Player
{
    Hand *hand;
    bool on_game;

    void (*libera)(Player *self);

    void (*init)(Player *self, Deck *deck);

    void (*imprime)(Player *self);

    bool (*draw)(Player *self, Deck *deck);
    bool (*stop)(Player *self);
};

Player *cria_player();