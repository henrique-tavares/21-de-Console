#include <unistd.h>
#include "../headers/clean_screen.h"

#include "../headers/game.h"

void loading()
{
    wprintf(L"\nIniciando o jogo [   ]\n");
    sleep(1);
    clean_screen();

    wprintf(L"\nIniciando o jogo [=  ]\n");
    sleep(1);
    clean_screen();

    wprintf(L"\nIniciando o jogo [== ]\n");
    sleep(1);
    clean_screen();

    wprintf(L"\nIniciando o jogo [===]\n");
    sleep(1);
    clean_screen();
}

void game()
{
    Player *player = cria_player();
    Dealer *dealer = cria_dealer();

    void *winner = NULL;

    Deck *deck = cria_deck();

    player->init(player, deck);
    dealer->init(dealer, deck);

    loading();

    do
    {
        dealer->imprime(dealer);
        player->imprime(player);

        if (dealer->on_game)
        {
            dealer->on_game = !dealer->stop(dealer);
        }
        if (dealer->on_game)
        {
            dealer->draw(dealer, deck);

            if (dealer->hand->total >= 21)
            {
                dealer->on_game = false;
            }
        }

        if (player->on_game)
        {
            player->on_game = !player->stop(player);
        }
        if (player->on_game)
        {
            player->draw(player, deck);

            if (player->hand->total >= 21)
            {
                player->on_game = false;
            }
        }

        clean_screen();

    } while (dealer->on_game || player->on_game);

    dealer->imprime(dealer);
    player->imprime(player);

    if (dealer->hand->total > 21 && player->hand->total > 21)
    {
        winner = NULL;
    }
    else if (dealer->hand->total > 21)
    {
        winner = player;
    }
    else if (player->hand->total > 21)
    {
        winner = dealer;
    }
    else if (dealer->hand->total >= player->hand->total)
    {
        winner = dealer;
    }
    else
    {
        winner = player;
    }

    sleep(1);

    if (winner == dealer)
    {
        wprintf(L"\nQue pena que o Dealer ganhou! (T-T)\nQuem sabe na próxima.\n");
    }
    else if (winner == player)
    {
        wprintf(L"\nParabéns! (～￣▽￣)～\nVocê ganhou dessa vez.\n");
    }
    else
    {
        wprintf(L"\nBem, ninguém ganhou. (-_-;)\nJogue mais uma vez.\n");
    }

    wprintf(L"\nQuando estiver pronto digite [ENTER] para voltar ao menu\n");
    getwchar();

    player->libera(player);
    dealer->libera(dealer);
    deck->libera(deck);
}