#include <wchar.h>
#include <stdlib.h>

#include "../headers/menu.h"

int menu()
{
    system("clear");

    int response;

    wprintf(
        L"\t__                 __                  \n"
        L"\t _)/|     _| _    /   _ __  _  _  |  _ \n"
        L"\t/__ |    (_|(/_   \\__(_)| |_> (_) | (/_\n");

    wprintf(L"\n\t1 - Começar o jogo");
    wprintf(L"\n\t2 - Instruções");
    wprintf(L"\n\t3 - Créditos");
    wprintf(L"\n\t0 - Sair");

    wprintf(L"\n\n\tEscolha uma opção: ");
    wscanf(L"%d", &response);
    getwchar();

    return (response >= 0 && response <= 3) ? response : menu();
}