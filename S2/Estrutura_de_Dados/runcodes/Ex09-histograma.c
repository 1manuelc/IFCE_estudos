/*

Faça um programa modularizado que leia e construa a seguinte tabela de histogramas:

Elemento   Valor   Histograma
A          4       ∗∗∗∗
B          2       ∗∗
C          8       ∗∗∗∗∗∗∗∗
D          12      ∗∗∗∗∗∗∗∗∗∗∗∗
E          1       ∗

A quantidade de elementos deve ser lida no programa principal. A quantidade de elementos será o parâmetro para uma alocação dinâmica do histograma. Dica: Use um vetor de ponteiros.


Ao final, sua estrutura deve permitir o cálculo da soma dos valores para exibir o histograma da soma (veja a saída esperada no caso de teste). Dica: faça funções para cada "mini problema".

Obs: Todas as impressões devem ser feitas em função(ões) específica(s) para impressão na tela. Jamais dentro da função que constrói ou lê dados. A(s) função(ões) para impressão devem receber a estrutura de dados como parâmetro para então percorrer e imprimir os dados.

*/

#include <stdio.h>
#include <stdlib.h>

int obterLinhas() {
    int linhas;
    scanf("%d", &linhas);

    return linhas;
}

int *alocarColunas(int linhas) {
    int *colunas;
    colunas = (int*)malloc(linhas * sizeof(int));

    return colunas;
}

int *povoarColunas(int *colunas, int linhas) {
    for(int i = 0; i < linhas; i++)
        scanf("%d", &colunas[i]);

    return colunas;
}

int **alocarMatriz(int *colunas, int linhas) {
    int **mat;
    mat = (int**)malloc(linhas * sizeof(int*));

    for(int i = 0; i < linhas; i++)
        mat[i] = (int*)malloc(colunas[i] * sizeof(int));

    return mat;
}

int **povoarMatriz(int **mat, int *colunas, int linhas) {
    for(int i = 0; i < linhas; i++) {
        for(int j = 0; j < colunas[i]; j++) {
            mat[i][j] = colunas[i];
        }
    } return mat;
}

int exibirMatriz(int acmSoma, int **mat, int *colunas, int linhas) {
    for(int i = 0; i < linhas; i++) {
        printf("%c %d ", (65 + i), colunas[i]);
        acmSoma += colunas[i];

        for(int j = 0; j < colunas[i]; j++) {
            if(mat[i][j] > 0) {
                printf("*");
            }
        } printf("\n");
    } return acmSoma;
}

void exibirSoma(int acmSoma) {
    printf("Soma: %d ", acmSoma);
    for(int i = 0; i < acmSoma; i++) {
        printf("*");
    }
}

void liberarColunas(int *colunas) {
    free(colunas);
}

void liberarMatriz(int **mat, int linhas) {
    for(int i = 0; i < linhas; i++) {
        free(mat[i]);
    } free(mat);
}

int main() {
    int **matriz, *col, lin, acmSoma = 0;

    // obter qtd de elementos
    lin = obterLinhas();

    // aloca ponteiro p qtd de elementos
    col = alocarColunas(lin);

    // povoa as posicoes do ponteiro
    col = povoarColunas(col, lin);
    
    // aloca linhas da matriz
    // aloca colunas da matriz com base no valor armazenado no ponteiro
    matriz = alocarMatriz(col, lin); 
        
    // povoa a matriz com os valores armazenados no ponteiro
    matriz = povoarMatriz(matriz, col, lin);

    // exibe a matriz formatada + acumula a soma do histograma
    acmSoma = exibirMatriz(acmSoma, matriz, col, lin);

    // exibe a soma
    exibirSoma(acmSoma);

    // libera as colunas
    liberarColunas(col);

    // libera a matriz
    liberarMatriz(matriz, lin);

    return 0;
}