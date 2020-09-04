#include "../headers/hand.h"

#include <locale.h>

int main()
{
    setlocale(LC_CTYPE, "");

    Hand *hand1 = cria_hand();

    hand1->adiciona(hand1, cria_card(HEARTS, ACE));
    hand1->adiciona(hand1, cria_card(HEARTS, TWO));
    hand1->adiciona(hand1, cria_card(HEARTS, THREE));
    hand1->adiciona(hand1, cria_card(HEARTS, FOUR));
    hand1->adiciona(hand1, cria_card(HEARTS, FIVE));
    hand1->adiciona(hand1, cria_card(HEARTS, SIX));
    hand1->adiciona(hand1, cria_card(HEARTS, SEVEN));
    hand1->adiciona(hand1, cria_card(HEARTS, EIGHT));
    hand1->adiciona(hand1, cria_card(HEARTS, NINE));
    hand1->adiciona(hand1, cria_card(HEARTS, TEN));
    hand1->adiciona(hand1, cria_card(HEARTS, JACK));
    hand1->adiciona(hand1, cria_card(HEARTS, QUEEN));
    hand1->adiciona(hand1, cria_card(HEARTS, KING));

    wprintf(L"\n");
    hand1->imprime(hand1);
    wprintf(L"\n");

    wprintf(L"Quatidade: %d, Valor total: %d\n", hand1->quantidade, hand1->total);

    wprintf(L"\nLimpando a mão...\n");
    hand1->limpa(hand1);

    wprintf(L"\n");
    hand1->imprime(hand1);
    wprintf(L"\n");

    wprintf(L"Quatidade: %d, Valor total: %d\n", hand1->quantidade, hand1->total);

    hand1->adiciona(hand1, cria_card(DIAMONDS, TWO));
    hand1->adiciona(hand1, cria_card(SPADES, ACE));
    hand1->adiciona(hand1, cria_card(HEARTS, ACE));
    hand1->adiciona(hand1, cria_card(DIAMONDS, SEVEN));
    hand1->adiciona(hand1, cria_card(CLUBS, JACK));

    wprintf(L"\n");
    hand1->imprime(hand1);
    wprintf(L"\n");

    wprintf(L"Quatidade: %d, Valor total: %d\n", hand1->quantidade, hand1->total);

    hand1->libera(hand1);

    return 0;
}