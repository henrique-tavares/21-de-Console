#include "../headers/hand.h"

void libera_hand_card(HandCard *self);

void libera_hand(Hand *self);
void adiciona_hand(Hand *self, Card *carta);
void limpa_hand(Hand *self);
void imprime_hand(Hand *self);
bool vazio_hand(Hand *self);

HandCard *cria_hand_card(Card *carta)
{
    HandCard *hand_card = (HandCard *)malloc(sizeof(HandCard));

    if (!hand_card)
    {
        return NULL;
    }

    hand_card->carta = carta;
    hand_card->prox = NULL;

    hand_card->libera = &libera_hand_card;

    return hand_card;
}

void libera_hand_card(HandCard *self)
{
    self->carta->libera(self->carta);
    self->prox = NULL;

    free(self);
}

Hand *cria_hand()
{
    Hand *hand = (Hand *)malloc(sizeof(Hand));

    if (!hand)
    {
        return NULL;
    }

    hand->primeiro = NULL;
    hand->ultimo = NULL;
    hand->quantidade = 0;
    hand->total = 0;

    hand->libera = &libera_hand;
    hand->adiciona = &adiciona_hand;
    hand->limpa = &limpa_hand;
    hand->imprime = &imprime_hand;
    hand->vazio = &vazio_hand;

    return hand;
}

void libera_hand(Hand *self)
{
    self->limpa(self);

    self->libera = NULL;
    self->adiciona = NULL;
    self->limpa = NULL;
    self->imprime = NULL;
    self->vazio = NULL;

    free(self);
}

void adiciona_hand(Hand *self, Card *carta)
{
    HandCard *hand_card = cria_hand_card(carta);

    if (self->vazio(self))
    {
        self->primeiro = hand_card;
        self->ultimo = hand_card;
    }
    else
    {
        self->ultimo->prox = hand_card;
        self->ultimo = self->ultimo->prox;
    }

    self->quantidade++;
    self->total += hand_card->carta->value;
}

void limpa_hand(Hand *self)
{
    for (HandCard *hand_card = NULL; self->primeiro != NULL; hand_card->libera(hand_card))
    {
        hand_card = self->primeiro;
        self->primeiro = self->primeiro->prox;
        self->quantidade--;
        self->total -= hand_card->carta->value;
    }

    self->ultimo = NULL;
}

void imprime_hand(Hand *self)
{
    for (HandCard *hand_card = self->primeiro; hand_card != NULL; hand_card = hand_card->prox)
    {
        hand_card->carta->print_upper(hand_card->carta);
    }
    wprintf(L"\n");
    for (HandCard *hand_card = self->primeiro; hand_card != NULL; hand_card = hand_card->prox)
    {
        hand_card->carta->print_middle(hand_card->carta);
    }
    wprintf(L"\n");
    for (HandCard *hand_card = self->primeiro; hand_card != NULL; hand_card = hand_card->prox)
    {
        hand_card->carta->print_lower(hand_card->carta);
    }
}

bool vazio_hand(Hand *self)
{
    return (self->primeiro == NULL && self->ultimo == NULL);
}