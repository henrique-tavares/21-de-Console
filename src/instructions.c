#include <wchar.h>

#include "../headers/instructions.h"

void instructions()
{
    wprintf(
        L"\n\tINSTRUÇÕES:"
        L"\n"
        L"\n\tValores das cartas:"
        L"\n\t\t'A' = 1"
        L"\n\t\t'2' = 2"
        L"\n\t\t'3' = 3"
        L"\n\t\t'4' = 4"
        L"\n\t\t'5' = 5"
        L"\n\t\t'6' = 6"
        L"\n\t\t'7' = 7"
        L"\n\t\t'8' = 8"
        L"\n\t\t'9' = 9"
        L"\n\t\t'0' = 10"
        L"\n\t\t'J' = 10"
        L"\n\t\t'Q' = 10"
        L"\n\t\t'K' = 10"
        L"\n"
        L"\n\tO objetivo do jogo é tentar ter o mais próximo possível de 21, pois caso passe de 21 pontos, você"
        L"\n\tautomaticamente já não pode mais ganhar."
        L"\n"
        L"\n\tA cada rodada o jogador (player) e o dealer terão a escolha de comprar mais uma carta ou de parar,"
        L"\n\tquem optar por parar, não pode mais comprar cartas até o fim do jogo."
        L"\n\tOs dois fazem a escolha ao mesmo tempo (mesma rodada), logo eles só sabem a carta que o outro comprou,"
        L"\n\tou se ele parou, após fazerem sua escolha, ou seja, é possível que os dois percam ao mesmo tempo."
        L"\n"
        L"\n\tO jogo acaba quando os dois decidirem parar, ou se os dois estourarem (passarem de 21), neste último caso"
        L"\n\tos dois perdem. Caso apenas um tenha estourado, a vitória é do outro. Por fim, se nenhum dos dois estourou"
        L"\n\to ganhador é quem tiver mais pontos, porém menor ou igual a 21 consequentemente."
        L"\n"
        L"\n\tBom jogo! (⌐■_■)ノ"
        L"\n");

    wprintf(L"\n\tQuando estiver pronto digite [ENTER] para voltar ao menu\n");
    getwchar();
}