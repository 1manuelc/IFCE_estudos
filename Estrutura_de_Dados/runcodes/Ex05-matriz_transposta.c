/*
Escreva uma função capaz de ler uma matriz 2x3 (a matriz é repassada como parâmetro). Uma outra função deve recebe essa matriz, gerar e devolver sua transposta (matriz 3x2). Ao final, o programa principal deve exibir as duas matrizes.
*/

#include <stdio.h>

void invert(int mat[2][3], int matInv[3][2]) {
    for(int lin = 0; lin < 2; lin++)
        for(int col = 0; col < 3; col++)
            matInv[col][lin] = mat[lin][col];
}

void write (int matrix[2][3]) {
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 3; j++)
            scanf("%d", &matrix[i][j]);
}

int main() {
    int matriz[2][3], matrizInv[3][2];
    write(matriz);
    invert(matriz, matrizInv);

    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 3; j++) {
            if(j == 2)
                printf("%d\n", matriz[i][j]);
            else
                printf("%d ", matriz[i][j]);
        }

    printf("\n");
    
    for(int j = 0; j < 3; j++)
        for(int i = 0; i < 2; i++) {
            if(i != 1)
                printf("%d ", matrizInv[j][i]);
            else
                printf("%d\n", matrizInv[j][i]);
        }
    return 0;
}