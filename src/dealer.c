#include "../headers/dealer.h"
#include "../headers/failure.h"

Dealer *cria_dealer();
void libera_dealer(Dealer *self);
void imprime_dealer(Dealer *self);
void init_dealer(Dealer *self, Deck *deck);
bool draw_dealer(Dealer *self, Deck *deck);
bool stop_dealer(Dealer *self);

Dealer *cria_dealer()
{
    Dealer *dealer = (Dealer *)malloc(sizeof(Dealer));
    is_null_failure(dealer, "Erro ao criar Dealer");

    dealer->hand = cria_hand();

    dealer->on_game = true;

    dealer->libera = &libera_dealer;
    dealer->init = &init_dealer;
    dealer->imprime = &imprime_dealer;
    dealer->draw = &draw_dealer;
    dealer->stop = &stop_dealer;

    return dealer;
}

void libera_dealer(Dealer *self)
{
    self->hand->libera(self->hand);

    self->libera = NULL;
    self->init = NULL;
    self->imprime = NULL;
    self->draw = NULL;
    self->stop = NULL;

    free(self);
}

void imprime_dealer(Dealer *self)
{
    wprintf(L"\n(⌐■_■) Dealer:\n");
    self->hand->imprime(self->hand);
    wprintf(L"\nValor total: %d\n", self->hand->total);
}

void init_dealer(Dealer *self, Deck *deck)
{
    self->draw(self, deck);
    self->draw(self, deck);
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