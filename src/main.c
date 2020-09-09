#include <locale.h>

#include "../headers/menu.h"
#include "../headers/game.h"
#include "../headers/instructions.h"
#include "../headers/credits.h"
#include "../headers/clean_screen.h"

int main()
{
    setlocale(LC_CTYPE, "");

    while (true)
    {
        switch (menu())
        {
        case 1:
            clean_screen();
            game();
            break;

        case 2:
            clean_screen();
            instructions();
            break;

        case 3:
            clean_screen();
            credits();
            break;
        case 0:
            exit(EXIT_SUCCESS);
        }
    }
}