#pragma once

#include <stdlib.h>
#include <wchar.h>

typedef enum CardSuit CardSuit;
typedef enum CardDisplay CardDisplay;
typedef struct Card Card;

enum CardSuit
{
    HEARTS = 0x2665,
    DIAMONDS = 0x2666,
    CLUBS = 0x2663,
    SPADES = 0x2660,
};

enum CardDisplay
{
    ACE = 'A',
    TWO = '2',
    THREE = '3',
    FOUR = '4',
    FIVE = '5',
    SIX = '6',
    SEVEN = '7',
    EIGHT = '8',
    NINE = '9',
    TEN = '0',
    JACK = 'J',
    QUEEN = 'Q',
    KING = 'K',

};

struct Card
{
    CardSuit suit;
    CardDisplay display;
    int value;

    void (*libera)(Card *self);

    void (*print_upper)(Card *self);
    void (*print_middle)(Card *self);
    void (*print_lower)(Card *self);
};

Card *cria_carta(CardSuit suit, CardDisplay display);
