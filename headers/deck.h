#pragma once

#include "./card.h"

typedef struct Deck Deck;
typedef struct DeckCard DeckCard;

struct DeckCard
{
    Card *card;
    DeckCard *prox;

    void (*libera)(DeckCard *self);
};

struct Deck
{
    DeckCard *topo;
    int tamanho;

    void (*libera)(Deck *self);

    Card *(*pop)(Deck *self);
    void (*push)(Deck *self, Card *card);
    Card *(*peek)(Deck *self);

    bool *(*vazio)(Deck *self);
};

Deck *cria_deck();