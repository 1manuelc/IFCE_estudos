/*

Implemente funções que recebam por parâmetro uma matriz capaz de armazenar valores reais e seu tamanho. As funções devem seguir a seguinte assinatura: (int linha, int coluna, float **mat).
O programa deve:

- Alocar dinamicamente a matriz;
- Ler os valores da matriz (as dimensões devem ser lidas no programa principal);
- Multiplicar a matriz por um valor escalar (lido após a leitura de todos os dados da matriz);
- Exibir a matriz em um formato apropriado (observe a saída esperada).


*/

#include <stdio.h>
#include <stdlib.h>

float **alocaMatriz(int lin, int col) {
    float **mat;
    mat = (float**)calloc(lin, sizeof(float*));

    if(mat) {
        for(int i = 0; i < lin; i++) {
            mat[i] = (float*)calloc(col, sizeof(float));
        }
    }

    return mat;
}

float **povoaMatriz(float **mat, int lin, int col) {
    for(int i = 0; i < lin; i++) {
        for(int j = 0; j < col; j++) {
            scanf("%f", &mat[i][j]);
        }
    } return mat;
}

void exibirMatriz(float **mat, int lin, int col) {
    for(int i = 0; i < lin; i++) {
        for(int j = 0; j < col; j++) {
            printf("%.1f ", mat[i][j]);
        } printf("\n");
    }
}

float **modificarMatriz(float **mat, float lin, float col, float multp) {
    for(int i = 0; i < lin; i++) {
        for(int j = 0; j < col; j++)
            mat[i][j] *= multp;
    } return mat;
}

void exibirMatMult(float **mat, float lin, float col, float multp) {
    printf("Mx%.1f\n", multp);

    for(int i = 0; i < lin; i++) {
        for(int j = 0; j < col; j++) {
            if(mat[i][j] < 10) {
                printf("0%.2f ", mat[i][j]);
            } else if(mat[i][j] >= 10)
                printf("%.2f ", mat[i][j]);
        } printf("\n");
    }
}
void liberarMatriz(float **mat, float lin) {
    for(int i = 0; i < lin; i++)
        free(mat[i]);
    free(mat);
}

int main() {
    float multiplicador;
    int lin, col;

    scanf("%d%d", &lin, &col);

    float **matriz;
    matriz = alocaMatriz(lin, col);

    matriz = povoaMatriz(matriz, lin, col);

    scanf("%f", &multiplicador);

    exibirMatriz(matriz, lin, col);

    matriz = modificarMatriz(matriz, lin, col, multiplicador);

    exibirMatMult(matriz, lin, col, multiplicador);

    liberarMatriz(matriz, lin);

    return 0;
}
