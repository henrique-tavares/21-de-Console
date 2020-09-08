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
        clean_screen();
        switch (menu())
        {
        case 1:
            game();
            break;

        case 2:
            instructions();
            break;

        case 3:
            credits();
            break;
        case 0:
            exit(EXIT_SUCCESS);
        }
    }
}