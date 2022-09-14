/*
Faça um programa para ler dois valores inteiros A e B, e imprima todos os valores inteiros entre os números lidos em ordem crescente. Por exemplo, ao receber os valores 2 e 5, devem ser impressos os valores 2, 3, 4 e 5. Caso receba os valores 4 e -1, devem ser impressos os valores -1, 0, 1, 2, 3 e 4.

Entrada
A entrada consiste de dois números inteiros.

Saída
A saída é composta de uma linha contendo todos os inteiros no intervalo fechado dos inteiros recebidos
*/
#include <stdio.h>

int main()
{
    int numeroA, numeroB;
    scanf("%d%d", &numeroA, &numeroB);
    
    if(numeroB > numeroA) {
        for(int i = numeroA; i <= numeroB; i++)
            printf("%d ", i);
    } else if(numeroA > numeroB) {
        for(int i = numeroB; i <= numeroA; i++)
            printf("%d ", i);
    }
    
    return 0;
}
