#include "../headers/shuffle.h"

#define get_random_time() srand(time(NULL));
#define get_random_index(max) rand() % max
#define numero_naipes 4
#define numero_cartas 13


Hand *create_hand_all_cards()
{
    short int lista_suit[numero_naipes] = {HEARTS, DIAMONDS, CLUBS, SPADES};
    short int lista_cards[numero_cartas] = {ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING};

    Hand *h = cria_hand();
    for (short int i = 0; i < numero_naipes; i++)
        for (short int j = 0; j < numero_cartas; j++)
            h->adiciona(h, cria_card(lista_suit[i], lista_cards[j]));
    return h;
}

void shuffle_deck(Deck *deck)
{
    Hand *hand = create_hand_all_cards();
    for (short int total_cartas = (numero_cartas * numero_naipes); total_cartas > 0; total_cartas--)
    {
        seed_get_random_time();
        short int random_index = get_random_index(hand->total);
        // deck->push(deck, hand->removePorIndex(cards, random_index)));
    }
}
