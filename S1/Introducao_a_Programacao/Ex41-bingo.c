/*

Bino é muito amigo de Cino e gostam muito de brincar de Bingo. O Bingo ocorre da seguinte forma: Cino possui um cartãozinho com N números. Enquanto que, Bino sorteia um número X. Se o número X estiver presente no cartãozinho de Cino, Cino ganha o bingo, caso contrário, não. Bino e Cino pediram sua ajuda para construir um programa para ajudar na brincadeira do Bingo. (3 pts)

Entrada
A primeira linha terá um inteiro, correspondendo a quantidade de números (N) do cartãozinho de Cino. A segunda linha terá N inteiros, que são os números do cartãozinho. A terceira linha terá o número sorteado por Bino.

Saída
A saída será os números do cartãozinho do Cino em uma linha e, na próxima linha, o texto GANHOU, caso o número que Bino sorteou esteja no cartãozinho de Cino e, PERDEU, caso contrário.

*/

#include <stdio.h>

int main() {
    int espacosCartao;
    scanf("%d", &espacosCartao);

    int cartela[espacosCartao];

    for(int i = 0; i < espacosCartao; i++)
        scanf("%d", &cartela[i]);

    int numeroAtual, contadorResultado = 0;
    scanf("%d", &numeroAtual);

    for(int i = 0; i < espacosCartao; i++) {
        // condicao para exibicao //
        printf("%d ", cartela[i]);

        // contador para o resultado //
        if(cartela[i] == numeroAtual)
            contadorResultado +=1;
    }

    // resultado final //
    if(contadorResultado > 0)
        printf("\nGANHOU");
    else
        printf("\nPERDEU");
        
    return 0;
}