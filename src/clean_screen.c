#include "../headers/clean_screen.h"
#include <stdlib.h>

void clean_screen()
{
  #ifdef _WIN32
    system("cls");
  #else
    system("clear");
  #endif
}