#include <locale.h>

#include "../headers/menu.h"
#include "../headers/game.h"
#include "../headers/instructions.h"
#include "../headers/credits.h"

int main()
{
    setlocale(LC_CTYPE, "");

    while (true)
    {
        switch (menu())
        {
        case 1:
            system("clear");
            game();
            break;

        case 2:
            system("clear");
            instructions();
            break;

        case 3:
            system("clear");
            credits();
            break;

        case 0:
            exit(EXIT_SUCCESS);
        }
    }
}