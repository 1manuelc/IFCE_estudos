/*
1) Crie um programa que leia um arquivo contendo o nome e o preço de diversos produtos
(separados por linha), e calcule o total da compra.
*/

#include <stdio.h>
#include <stdlib.h>

void main() {
    FILE *arquivo;
    char letraAtual, produto[26];
    float acumTotal = 0, numAtual = 0;

    arquivo = fopen("produtos.txt", "r");

    while(!feof(arquivo)) {
        fscanf(arquivo, "%s \n %f", produto, &numAtual);
        acumTotal += numAtual;
    }
    
    fclose(arquivo);
    printf("%.2f\n", acumTotal);

    system("pause");
}