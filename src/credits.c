#include <wchar.h>

#include "../headers/credits.h"

void credits()
{
    wprintf(
        L"\n\tAutores do 21 de Console:"
        L"\n"
        L"\n\tEllian Aragão Dias"
        L"\n\tHenrique Tavares Aguiar"
        L"\n\tJoão Vítor de Souza Rezende"
        L"\n");

    wprintf(L"\n\tQuando estiver pronto digite [ENTER] para voltar ao menu\n");
    getwchar();
}