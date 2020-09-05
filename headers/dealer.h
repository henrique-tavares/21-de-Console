#pragma once

#include "./hand.h"
#include "./deck.h"

typedef struct Dealer Dealer;

struct Dealer
{
    Hand *hand;

    void (*libera)(Dealer *self);

    bool (*draw)(Dealer *self, Deck *deck);
    bool (*stop)(Dealer *self);
};

Dealer *cria_dealer();