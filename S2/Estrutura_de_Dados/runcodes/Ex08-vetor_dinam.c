/*

Escreva um programa em que leia uma sequência de código de operação e valor, onde o código de operação é um inteiro com os seguintes valores:

0 (zero): fim
1 (um): inserção
2 (dois): remoção
O valor lido é do tipo float e deve ser inserido em um vetor (caso a operação seja 1), ou removido do vetor (caso a operação seja 2). No final do programa o vetor resultante deve ser impresso.

Exemplo (leituras):
1
34.5
1
60.1
1
43.2
2
1
10.2
0
(saída esperada):
{34.5, 60.1, 10.2}

*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    float *vetor;
    int opcao = 0, i = 0;

    scanf("%d", &opcao);
    while(opcao != 0) {
        if(opcao == 1) {
            // inserir uma posicao no ponteiro vetor
            if(i == 0)
                vetor = (float*)malloc((i + 1) * sizeof(float));
            else
                vetor = realloc(vetor, i + 1);
            
            scanf("%f", &vetor[i]);
            i++;
        } else if(opcao == 2) {
            vetor = (float*)realloc(vetor, i - 1);
            i--;
        }
        scanf("%d", &opcao);
    }

    printf("{");
    for(int j = 0; j < i; j++) {
        if(j == i - 1)
            printf("%.1f", vetor[j]);
        else
            printf("%.1f, ", vetor[j]);
    }
    printf("}\n");

    return 0;
}