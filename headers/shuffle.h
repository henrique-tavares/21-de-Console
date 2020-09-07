#pragma once

#include <stdio.h>
#include <time.h>

#include "card.h"
#include "deck.h"

// Recebe o endereço de memória do deck e adiciona as cartas embaralhadas
void shuffleHandCards(Deck *deck);