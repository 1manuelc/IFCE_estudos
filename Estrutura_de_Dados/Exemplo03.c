/*

Escreva um programa capaz de ler uma matriz de tamanho variável (leia: a quantidade de linhas, depois as colunas).
Depois de lida a dimensão da matriz, o algoritmo deve ler todos os elementos da matriz, um a um.
Ao final, o algoritmo deve exibir toda a matriz.

*/

#include <stdio.h>

int main(){

    int qtdeLinhas, qtdeColunas;
    scanf("%d", &qtdeLinhas);
    scanf("%d", &qtdeColunas);

    int matriz[qtdeLinhas][qtdeColunas];

    for(int i = 0; i < qtdeLinhas; i++) {
        for(int j = 0; j < qtdeColunas; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    for(int i = 0; i < qtdeLinhas; i++) {
        for(int j = 0; j < qtdeColunas; j++) {
            if(matriz[i][j] < 10) {
                if(j == (qtdeColunas - 1))
                    printf("0%d\n", matriz[i][j]);
                else
                    printf("0%d ", matriz[i][j]);
            } else {
                if(j == (qtdeColunas - 1))
                    printf("%d\n", matriz[i][j]);
                else
                    printf("%d ", matriz[i][j]);
            }
        }
    }

    return 0;
}