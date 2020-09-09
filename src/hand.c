#include "../headers/hand.h"
#include "../headers/failure.h"

void libera_hand_card(HandCard *self);

HandCard *cria_hand_card(Card *carta)
{
    HandCard *hand_card = (HandCard *)malloc(sizeof(HandCard));
    is_null_failure(hand_card, "Erro ao criar HandCard");

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

void libera_hand(Hand *self);
void adiciona_hand(Hand *self, Card *carta);
Card *remove_hand(Hand *self, int index);
void limpa_hand(Hand *self);
void imprime_hand(Hand *self);
bool vazio_hand(Hand *self);

Hand *cria_hand()
{
    Hand *hand = (Hand *)malloc(sizeof(Hand));

    is_null_failure(hand, "Erro ao criar Hand");

    hand->primeiro = NULL;
    hand->ultimo = NULL;
    hand->quantidade = 0;
    hand->total = 0;

    hand->libera = &libera_hand;
    hand->adiciona = &adiciona_hand;
    hand->remove = &remove_hand;
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
    self->remove = NULL;
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

Card *remove_hand(Hand *self, int index)
{
    if (index < 0 || index >= self->quantidade)
    {
        return NULL;
    }

    Card *card_aux = NULL;
    if (index == 0)
    {
        card_aux = self->primeiro->carta;

        HandCard *hand_card_aux = self->primeiro;

        self->total -= self->primeiro->carta->value;
        self->quantidade--;

        self->primeiro = self->primeiro->prox;

        if (self->primeiro == NULL)
        {
            self->ultimo = NULL;
        }

        hand_card_aux->prox = NULL;
        free(hand_card_aux);
    }
    else
    {
        HandCard *ant = self->primeiro;
        HandCard *atual = self->primeiro->prox;

        for (int i = 1; i < index; i++)
        {
            ant = atual;
            atual = atual->prox;
        }

        if (atual == self->ultimo)
        {
            self->ultimo = ant;
        }

        card_aux = atual->carta;
        ant->prox = atual->prox;

        self->total -= atual->carta->value;
        self->quantidade--;

        atual->prox = NULL;
        free(atual);
    }

    return card_aux;
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