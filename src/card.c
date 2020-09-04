#include "../headers/card.h"

Card *cria_card(CardSuit suit, CardDisplay display);
void libera_card(Card *self);
void print_upper_card(Card *self);
void print_middle_card(Card *self);
void print_lower_card(Card *self);

const char *COLOR_RESET = "\033[0m";
const char *TEXT_RED = "\033[0;31m";
const char *TEXT_BLACK = "\033[0;30m";
const char *TEXT_WHITE = "\033[0;47m";
const char *CARD_BACKGOUND = "\033[47m";
const char *CARD_BACK = "\033[41m";

Card *cria_card(CardSuit suit, CardDisplay display)
{
    Card *carta = (Card *)malloc(sizeof(Card));

    if (!carta)
    {
        return NULL;
    }

    carta->suit = suit;
    carta->display = display;

    switch (display)
    {
    case ACE:
        carta->value = 1;
        break;

    case TWO:
        carta->value = 2;
        break;

    case THREE:
        carta->value = 3;
        break;

    case FOUR:
        carta->value = 4;
        break;

    case FIVE:
        carta->value = 5;
        break;

    case SIX:
        carta->value = 6;
        break;

    case SEVEN:
        carta->value = 7;
        break;

    case EIGHT:
        carta->value = 8;
        break;

    case NINE:
        carta->value = 9;
        break;

    case TEN:
        carta->value = 10;
        break;

    case JACK:
        carta->value = 10;
        break;

    case QUEEN:
        carta->value = 10;
        break;

    case KING:
        carta->value = 10;
        break;
    }

    carta->libera = &libera_card;

    carta->print_upper = &print_upper_card;
    carta->print_middle = &print_middle_card;
    carta->print_lower = &print_lower_card;

    return carta;
}

void libera_card(Card *self)
{
    self->libera = NULL;

    self->print_upper = NULL;
    self->print_middle = NULL;
    self->print_lower = NULL;

    free(self);
}

void print_upper_card(Card *self)
{
    if (self->suit == HEARTS || self->suit == DIAMONDS)
    {
        wprintf(L" %s%s%lc    %s ", TEXT_RED, CARD_BACKGOUND, self->suit, COLOR_RESET);
    }
    else
    {
        wprintf(L" %s%s%lc    %s ", TEXT_BLACK, CARD_BACKGOUND, self->suit, COLOR_RESET);
    }
}

void print_middle_card(Card *self)
{
    wprintf(L" %s%s  %c  %s ", TEXT_BLACK, CARD_BACKGOUND, self->display, COLOR_RESET);
}

void print_lower_card(Card *self)
{
    if (self->suit == HEARTS || self->suit == DIAMONDS)
    {
        wprintf(L" %s%s    %lc%s ", TEXT_RED, CARD_BACKGOUND, self->suit, COLOR_RESET);
    }
    else
    {
        wprintf(L" %s%s    %lc%s ", TEXT_BLACK, CARD_BACKGOUND, self->suit, COLOR_RESET);
    }
}