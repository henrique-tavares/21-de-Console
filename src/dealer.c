#include "../headers/dealer.h"

Dealer *cria_dealer();
void libera_dealer(Dealer *self);
bool draw_dealer(Dealer *self, Deck *deck);
bool stop_dealer(Dealer *self);

Dealer *cria_dealer()
{
    Dealer *dealer = (Dealer *)malloc(sizeof(Dealer));

    if (!dealer)
    {
        return NULL;
    }

    dealer->hand = cria_hand();

    dealer->libera = &libera_dealer;
    dealer->draw = &draw_dealer;
    dealer->stop = &stop_dealer;

    return dealer;
}

void libera_dealer(Dealer *self)
{
    self->hand->libera(self->hand);

    self->libera = NULL;
    self->draw = NULL;
    self->stop = NULL;

    free(self);
}

bool draw_dealer(Dealer *self, Deck *deck)
{
    self->hand->adiciona(self->hand, deck->pop(deck));

    return (self->hand->total <= 21);
}

bool stop_dealer(Dealer *self)
{
    return (self->hand->total >= 17);
}