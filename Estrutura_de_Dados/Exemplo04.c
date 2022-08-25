/*

Imagine que você precise armazenar últimos 10 dias de chuva.
Escreva um programa capaz de ler os dados pluviométricos e armazene-os em um vetor de tamanho fixo (10 elementos).
Ao final, mostre o dia que mais choveu elemento.

*/

#include <stdio.h>

int main() {
    int chuvas[10], maiorChuva = 0;

    for(int i = 0; i < 10; i++) {
        scanf("%d", &chuvas[i]);

        if(chuvas[i] > maiorChuva)
        maiorChuva = chuvas[i];
    }

    printf("%d", maiorChuva);

    return 0;
}