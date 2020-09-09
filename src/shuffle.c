#include "../headers/shuffle.h"

#define get_random_time() srand(time(NULL));

#define qtd_suits 4
#define qtd_display_values 13

const int lista_suits[qtd_suits] = {HEARTS, DIAMONDS, CLUBS, SPADES};

const int lista_display_values[qtd_display_values] = {ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING};

int randomize_hand_index(Hand *hand)
{
    return rand() % hand->quantidade;
}

void fill_all_cards(Hand *hand)
{
    for (int suit = 0; suit < qtd_suits; suit++)
    {
        for (int display_values = 0; display_values < qtd_display_values; display_values++)
        {
            get_random_time();
            hand->adiciona(hand, cria_card(lista_suits[suit], lista_display_values[display_values]));
        }
    }
}

void shuffle_deck(Deck *deck)
{
    Hand *hand = cria_hand();
    fill_all_cards(hand);

    while (!(hand->vazio(hand)))
    {
        deck->push(deck, hand->remove(hand, randomize_hand_index(hand)));
    }
}
