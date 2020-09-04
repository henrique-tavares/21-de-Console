#pragma once

#include "./card.h"

typedef struct HandCard HandCard;
typedef struct Hand Hand;

struct HandCard
{
    Card *carta;
    HandCard *prox;

    void (*libera)(HandCard *self);
};

struct Hand
{
    HandCard *primeiro;
    HandCard *ultimo;
    int quantidade;
    int total;

    void (*libera)(Hand *self);

    void (*adiciona)(Hand *self, Card *carta);
    void (*limpa)(Hand *self);
    void (*imprime)(Hand *self);
    bool (*vazio)(Hand *self);
};

Hand *cria_hand();