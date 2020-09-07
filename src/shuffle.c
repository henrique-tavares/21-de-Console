#include "../headers/shuffle.h"

#define get_random_time() srand(time(NULL));
#define card_not_in_deck(suit, value) lista_cards[suit][value] == 0

#define numero_naipes 4
#define numero_cartas 13

short int lista_suit[numero_naipes] = {HEARTS, DIAMONDS, CLUBS, SPADES};

short int lista_cards[numero_naipes][numero_cartas] = {
    {ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING},
    {ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING},
    {ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING},
    {ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING}};

void is_null_exit_failure(void *ptr, const char *message)
{
    if (ptr == NULL)
    {
        wprintf(L"%s", message);
        exit(EXIT_FAILURE);
    }
}

void randomize_card(short int *suit, short int *display_value)
{
    do
    {
        *suit = rand() % numero_naipes;
        *display_value = rand() % numero_cartas;
    } while (card_not_in_deck(*suit, *display_value));
}

void shuffle_deck(Deck *deck)
{
    for (short int total_cartas = (numero_cartas * numero_naipes); total_cartas > 0; total_cartas--)
    {
        get_random_time();

        short int suit, display_value;
        randomize_card(&suit, &display_value);

        Card *carta = cria_card(lista_suit[suit], lista_cards[suit][display_value]);
        is_null_failure(carta, "Erro ao criar carta para adicionar ao deck, shuffle.c");

        deck->push(deck, carta);
        lista_cards[suit][display_value] = 0;
    }
}
