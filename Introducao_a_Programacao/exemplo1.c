/* 01 - Faça um programa em C que leia o nome da disciplina, a quantidade de alunos e a média de alunos na turma. Em seguida, exiba a seguinte mensagem: A disciplina Programacao possui 30 alunos. A media da turma e 9,5.

Neste exercício, considere que Programação, 30 e 9,5 são os valores informados pelo usuário. Antes da leitura de cada valor, escreva os seguintes textos, respectivamente: Disciplina: Qtde de alunos: Media da turma:

Na exibição dos textos, não utilize acentuação. Exiba a média com uma casa decimal. */

#include <stdio.h>

int main()
{
    int qtdalunos;
    float media;
    char discip[15];

    printf("Disciplina:");
    scanf("%s", discip);

    printf("Qtde de alunos:");
    scanf("%d", &qtdalunos);

    printf("Media da turma:");
    scanf("%f", &media);

    printf("A disciplina %s possui %d alunos. A media da turma e %.1f.", discip, qtdalunos, media);

    return 0;

}
