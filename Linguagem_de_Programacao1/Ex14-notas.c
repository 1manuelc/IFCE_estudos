/*
2) Elabore um programa que receba do usuário um arquivo que contenha o nome e a nota
de diversos alunos (da seguinte forma: NOME: MARIA NOTA: 8), um aluno por linha. Mostre
na tela o nome e a nota do aluno que possui a maior nota.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main() {
    FILE *arquivo;
    char nomeAtual[26], nomeMaior[26];
    float ultMaior = 0, maiorNota = 0, notaAtual;

    arquivo = fopen("notas.txt", "r+");

    while(!feof(arquivo)) {
        fscanf(arquivo, "NOME: %s NOTA: %f\n", nomeAtual, &notaAtual);
        if(notaAtual > ultMaior) {
            maiorNota = notaAtual;
            strcpy(nomeMaior, nomeAtual);
            ultMaior = maiorNota;
        }
    }

    printf("A maior nota foi de %s: %.2f\n", nomeMaior, maiorNota);
    
    fclose(arquivo);
    system("pause");
}