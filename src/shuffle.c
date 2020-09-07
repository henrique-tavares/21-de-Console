#include "../headers/shuffle.h"

#define getRandomTime(number) srand(time(NULL) * number / 3);

#define NumeroDeNaipes 4
#define NumeroDeCartas 13

u_int16_t listaSuit[NumeroDeNaipes] = {HEARTS, DIAMONDS, CLUBS, SPADES};

u_int8_t listaCartds[NumeroDeNaipes][NumeroDeCartas] = {
    {ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING},
    {ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING},
    {ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING},
    {ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING}};

static void isNullExitFailure(void *ptr, const char *ErrorMessage)
{
  if (ptr == NULL)
  {
    perror(ErrorMessage);
    exit(EXIT_FAILURE);
  }
}

static int findCardInDeck(u_int8_t *suit, u_int8_t *card)
{
  if (listaCartds[*suit][*card] == 0)
  {
    return 1;
    // if (*card < NumeroDeCartas - 1)
    // {
    //   *card++;
    // }
    // else if (*suit < NumeroDeNaipes - 1)
    // {
    //   *suit++;
    // }
    // else
    // {
    //   *card = 0;
    //   *suit = 0;
    // }
    // findCardInDeck(suit, card);
  }
  return 0;
}

static void selectRandomCard(u_int8_t *suit, u_int8_t *card)
{
  do{
    *suit = rand() % NumeroDeNaipes;
    *card = rand() % NumeroDeCartas;
  } while (findCardInDeck(suit, card));
}

void shuffleCards(Deck *deck)
{
  u_int8_t totalCartas = (NumeroDeCartas * NumeroDeNaipes);
  while (totalCartas--)
  {
    getRandomTime(totalCartas);
    u_int8_t suit, card;
    selectRandomCard(&suit, &card);
    Card *carta = cria_card(listaSuit[suit], listaCartds[suit][card]);
    isNullExitFailure(carta, "Erro ao criar carta para adicionar a mão, shuffle.c");

    deck->push(deck, carta);
    listaCartds[suit][card] = 0;
  }
}
