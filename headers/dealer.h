#pragma once

#include "./hand.h"
#include "./deck.h"

typedef struct Dealer Dealer;

struct Dealer
{
    Hand *hand;
    bool on_game;

    void (*libera)(Dealer *self);

    void (*imprime)(Dealer *self);

    void (*init)(Dealer *self, Deck *deck);

    bool (*draw)(Dealer *self, Deck *deck);
    bool (*stop)(Dealer *self);
};

Dealer *cria_dealer();