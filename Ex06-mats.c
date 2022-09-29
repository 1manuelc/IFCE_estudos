#include <stdio.h>
#include <stdlib.h>

int *povoarAlunos(int alunosDia[]) {
    for(int i = 0; i < 3; i++) {
        printf("Alunos no dia %d: ", i);
        scanf("%d", &alunosDia[i]);
    }

    return alunosDia;
}

int **alocarMatriculas(int alunosDia[]) {
    int **matriculas;
    matriculas = (int**)calloc(3, sizeof(int*));  // matriculas[i]

    if(matriculas != NULL) {
        for(int i = 0; i < 3; i++)
            matriculas[i] = (int*)calloc(alunosDia[i], sizeof(int));
    } else
        printf("Erro ao alocar");

    return matriculas;
}

int **obterMatriculas(int **matriculas, int alunosDia[]) {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < alunosDia[i]; j++) {
            printf("Dia %d Aluno: %d: ", i, j);
            scanf("%d", &matriculas[i][j]);
        }
    }

    return matriculas;
}

void exibirMatriculas(int **matriculas, int alunosDia[], int escolha) {
    printf("\n\n");
    for(int i = 0; i < alunosDia[escolha]; i++) {
        printf("\n%d\n", matriculas[escolha][i]);
    }
}

void liberarMatriculas(int **matriculas) {
    for(int i = 0; i < 3; i++)
        free(matriculas[i]);
    free(matriculas);
}

void main() {
    int **matriculas, alunosDia[3], escolha = 0;

    povoarAlunos(alunosDia);

    alocarMatriculas(alunosDia);

    obterMatriculas(matriculas, alunosDia);

    printf("Digite um dia p exibir as matriculas: ");
    scanf("%d", &escolha);

    exibirMatriculas(matriculas, alunosDia, escolha);

    liberarMatriculas(matriculas);

    system("pause");
}