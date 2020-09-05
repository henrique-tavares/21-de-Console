#include "../headers/player.h"

Player *cria_player();
void libera_player(Player *self);
bool draw_player(Player *self, Deck *deck);
bool stop_player(Player *self);

Player *cria_player()
{
    Player *player = (Player *)malloc(sizeof(Player));

    if (!player)
    {
        return NULL;
    }

    player->hand = cria_hand();

    player->libera = &libera_player;
    player->draw = &draw_player;
    player->stop = &stop_player;

    return player;
}

void libera_player(Player *self)
{
    self->hand->libera(self->hand);

    self->libera = NULL;
    self->draw = NULL;
    self->stop = NULL;

    free(self);
}

bool draw_player(Player *self, Deck *deck)
{
    self->hand->adiciona(self->hand, deck->pop(deck));

    return (self->hand->total <= 21);
}

bool stop_player(Player *self)
{
    char response;

    wprintf(L"\n\tDeseja continuar comprando (s/n)? ");
    wscanf(L"%c", &response);

    switch (response)
    {
    case 'y':
        return true;

    case 'Y':
        return true;

    case 'n':
        return false;

    case 'N':
        return false;

    default:
        return stop_player(self);
    }
}