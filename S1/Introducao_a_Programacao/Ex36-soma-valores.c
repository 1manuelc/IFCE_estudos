/*

Soma de valores
Faça um programa para ler 10 números inteiros. Em seguida ler também dois valores X e Y quaisquer correspondentes a duas posições no vetor. Ao final, escrever a soma dos valores das respectivas posições X e Y. (Obs.: Considere que a posição corresponde ao índice do vetor)

Entrada
A primeira linha contém 10 números inteiros. A segunda linha contém dois números inteiros X e Y.

Saída
Um número inteiro, correspondendo a soma dos valores existentes nas posições X e Y do vetor.

Exemplo de entrada	    Exemplo de saída
1 2 3 4 5 6 7 8 9 10	7
0 5	
1 2 3 4 5 6 7 8 9 10	2
0 0	
1 2 3 4 5 6 7 8 9 10	11
0 9	

*/

#include <stdio.h>

int main() {
    int num[10];
    int numX, numY, soma = 0;

    for(int i = 0; i < 10; i++)
        scanf("%d", &num[i]);
    
    scanf("%d%d", &numX, &numY);
    
    soma = num[numX] + num[numY];
    printf("%d", soma);
    
    return 0;
}