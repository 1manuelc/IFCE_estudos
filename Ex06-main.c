#include <stdio.h>
#include <stdlib.h>
#define diasEvento 3

void main() {
    int **matriculas, *alunosDia, escolha = 0;

    matriculas = (int**)malloc(diasEvento * sizeof(int*));  // matriculas[i]
    alunosDia = (int*)malloc(diasEvento * sizeof(int));     // alunosDia[i]

    // preencher qtde de alunos e matriculas em cada dia
    for(int i = 0; i < diasEvento; i++) {
        printf("Alunos no dia %d: ", i);
        scanf("%d", &alunosDia[i]);
        matriculas[i] = (int*)malloc(alunosDia[i] * sizeof(int));
    }

    //preencher as matriculas de cada aluno
    for(int i = 0; i < diasEvento; i++) {
        for(int j = 0; j < alunosDia[i]; j++) {
            printf("Dia %d Aluno: %d: ", i, j);
            scanf("%d", &matriculas[i][j]);
        }
    }

    //dia para mostrar as matriculas
    printf("Digite um dia para mostrar as matriculas armazenadas: ");
    scanf("%d", &escolha);

    for(int i = 0; i < alunosDia[escolha]; i++) {
        printf("\n%d\n", matriculas[escolha][i]);
    }

    system("pause");
}