#pragma once

#include <time.h>

#include "./failure.h"
#include "./hand.h"
#include "./deck.h"

// Recebe o endereço de memória do deck e adiciona as cartas embaralhadas
void shuffle_deck(Deck *deck);