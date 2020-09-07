#include "../headers/deck.h"
#include "../headers/shuffle.h"

DeckCard *cria_deck_card(Card *card);
void libera_deck_card(DeckCard *self);

DeckCard *cria_deck_card(Card *card)
{
    DeckCard *deck_card = (DeckCard *)malloc(sizeof(DeckCard));

    if (!deck_card)
    {
        return NULL;
    }

    deck_card->card = card;
    deck_card->prox = NULL;

    deck_card->libera = &libera_deck_card;

    return deck_card;
}

void libera_deck_card(DeckCard *self)
{
    self->card = NULL;
    self->prox = NULL;
    self->libera = NULL;

    free(self);
}

void libera_deck(Deck *self);
Card *pop_deck(Deck *self);
void push_deck(Deck *self, Card *card);
Card *peek_deck(Deck *self);
bool vazio_deck(Deck *self);

Deck *cria_deck()
{
    Deck *deck = (Deck *)malloc(sizeof(Deck));

    if (!deck)
    {
        return NULL;
    }

    deck->topo = NULL;
    deck->tamanho = 0;

    deck->libera = &libera_deck;
    deck->pop = &pop_deck;
    deck->push = &push_deck;
    deck->peek = &peek_deck;
    deck->vazio = &vazio_deck;

    shuffle_deck(deck);

    return deck;
}

void libera_deck(Deck *self)
{
    while (!self->vazio(self))
    {
        Card *card_aux = self->pop(self);
        card_aux->libera(card_aux);
    }

    self->libera = NULL;
    self->pop = NULL;
    self->push = NULL;
    self->peek = NULL;
    self->vazio = NULL;

    free(self);
}

Card *pop_deck(Deck *self)
{
    if (self->vazio(self))
    {
        return NULL;
    }

    DeckCard *old_deck_card = self->topo;

    self->topo = self->topo->prox;
    self->tamanho--;

    Card *card = old_deck_card->card;

    old_deck_card->libera(old_deck_card);

    return card;
}

void push_deck(Deck *self, Card *card)
{
    DeckCard *deck_card = cria_deck_card(card);

    if (!deck_card)
    {
        return;
    }

    deck_card->prox = self->topo;
    self->topo = deck_card;

    self->tamanho++;
}

Card *peek_deck(Deck *self)
{
    if (self->vazio(self))
    {
        return NULL;
    }

    return self->topo->card;
}

bool vazio_deck(Deck *self)
{
    return (self->topo == NULL);
}
