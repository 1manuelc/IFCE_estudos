#include <stdio.h>
#include <stdlib.h>
#define diasEvento 3

void alocar(int **matriculas, int *alunosDia) {
    matriculas = (int**)malloc(diasEvento * sizeof(int*));  // matriculas[i]
    alunosDia = (int*)malloc(diasEvento * sizeof(int));     // alunosDia[i]

    // preencher qtde de alunos e matriculas em cada dia
    for(int i = 0; i < diasEvento; i++) {
        printf("Alunos no dia %d: ", i);
        scanf("%d", &alunosDia[i]);
        matriculas[i] = (int*)malloc(alunosDia[i] * sizeof(int));
    }
}

void obterMatriculas(int **matriculas, int *alunosDia) {
    for(int i = 0; i < diasEvento; i++) {
        for(int j = 0; j < alunosDia[i]; j++) {
            printf("Dia %d Aluno: %d: ", i, j);
            scanf("%d", &matriculas[i][j]);
        }
    }
}

void exibirMatriculas(int **matriculas, int *alunosDia, int escolha) {
    printf("\n\n");
    for(int i = 0; i < alunosDia[escolha]; i++) {
        printf("\n%d\n", matriculas[escolha][i]);
    }
}

void liberarMatriculas(int **matriculas) {
    for(int i = 0; i < diasEvento; i++)
        free(matriculas[i]);
    free(matriculas);
}

void main() {
    int **matriculas, *alunosDia, escolha = 0;

    alocar(matriculas, alunosDia);

    obterMatriculas(matriculas, alunosDia);

    printf("Digite um dia p exibir as matriculas: ");
    scanf("%d", &escolha);

    exibirMatriculas(matriculas, alunosDia, escolha);

    liberarMatriculas(matriculas);

    system("pause");
}