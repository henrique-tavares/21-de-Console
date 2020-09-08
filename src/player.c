#include "../headers/player.h"
#include "../headers/failure.h"

Player *cria_player();
void libera_player(Player *self);
void init_player(Player *self, Deck *deck);
void imprime_player(Player *self);
bool draw_player(Player *self, Deck *deck);
bool stop_player(Player *self);

Player *cria_player()
{
    Player *player = (Player *)malloc(sizeof(Player));
    is_null_failure(player, "Erro ao criar Player");

    player->hand = cria_hand();

    player->libera = &libera_player;
    player->init = &init_player;
    player->imprime = &imprime_player;
    player->draw = &draw_player;
    player->stop = &stop_player;

    return player;
}

void libera_player(Player *self)
{
    self->hand->libera(self->hand);

    self->libera = NULL;
    self->init = NULL;
    self->imprime = NULL;
    self->draw = NULL;
    self->stop = NULL;

    free(self);
}

void init_player(Player *self, Deck *deck)
{
    self->draw(self, deck);
    self->draw(self, deck);
}

void imprime_player(Player *self)
{
    wprintf(L"\n(ಠ_ಠ) Player:\n");
    self->hand->imprime(self->hand);
    wprintf(L"\nValor total: %d\n", self->hand->total);
}

bool draw_player(Player *self, Deck *deck)
{
    self->hand->adiciona(self->hand, deck->pop(deck));

    return (self->hand->total <= 21);
}

bool stop_player(Player *self)
{
    char response;

    wprintf(L"\nVocê deseja parar (s/n)? ");
    wscanf(L"%c", &response);
    getwchar();

    if (response == 's' || response == 'S')
    {
        return true;
    }
    else if (response == 'n' || response == 'N')
    {
        return false;
    }
    else
    {
        return stop_player(self);
    }
}