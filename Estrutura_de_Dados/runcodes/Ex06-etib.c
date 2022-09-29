/*
Esse ano teremos mais uma edição do ETIB (Encontro de Tecnologia da Informação da Ibiapaba), organizado e promovido pelo nosso campus.

O evento irá acontecer ao longo de 3 dias e precisamos de uma estrutura de dados para armazenar as matrícuças dos estudantes que participaram do evento em cada dia. Como não sabemos quantos estudantes em cada dia irão participar do evento, então precisamos de uma estrutura que armazene uma quantidade distinta de dados para cada um dos três dias do evento. Que estrutura seria essa?

Definida a estrutura, agora faça um programa com as seguintes funcionalidades:

Ler a quantidade de participantes para cada um dos três dias do evento
Ler as respectivas matrículas de cada participante para cada dia, realizada após a leitura das quantidades
Apresentar a lista de participantes (matrícula) de um dia específico, lido novamente
Obs: faça o programa modularizado

Veja os parâmetros de entreada e saída esperada nos casos de teste.
*/

#include <stdio.h>
#include <stdlib.h>

int *povoarAlunos(int alunosDia[]) {
    for(int i = 0; i < 3; i++) {
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
    }

    return matriculas;
}

int **obterMatriculas(int **matriculas, int alunosDia[]) {
    for(int i = 0; i < 3; i++) {
        if(alunosDia[i] != 0) {
            for(int j = 0; j < alunosDia[i]; j++) {
                scanf("%d", &matriculas[i][j]);
            }
        }
    }

    return matriculas;
}

void exibirMatriculas(int **matriculas, int alunosDia[], int escolha) {
    printf("Lista do dia: %d\n", escolha);
    if(alunosDia[escolha - 1] == 0)
        printf("Sem participantes no dia\n");
    else {
        for(int i = 0; i < alunosDia[escolha - 1]; i++) {
            printf("%d\n", matriculas[escolha - 1][i]);
        }
    }
}

void liberarMatriculas(int **matriculas, int alunosDia[]) {
    for(int i = 0; i < 3; i++)
        free(matriculas[i]);
    free(matriculas);
}

int main() {
    int alunosDia[3], escolha = 0;
    
    povoarAlunos(alunosDia);
    int **matriculas = alocarMatriculas(alunosDia);

    alocarMatriculas(alunosDia);

    obterMatriculas(matriculas, alunosDia);

    scanf("%d", &escolha);

    exibirMatriculas(matriculas, alunosDia, escolha);

    liberarMatriculas(matriculas, alunosDia);

    return 0;
}