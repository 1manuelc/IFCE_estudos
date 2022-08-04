/*

Escreva um algoritmo em C que solicite como entrada um número que represente a quantidade de horas e outro número que represente a quantidade de minutos. O algoritmo deve converter esses números para segundos. Por exemplo, caso o usuário digite hora = 1 e minuto = 1, o algoritmo deve gerar 3660 segundos.

*/

#include <stdio.h>

int main()
{
    int horas, minutos, total;

    scanf("%d%d", &horas, &minutos);

    horas *= 60 * 60;
    minutos *= 60;
    total = horas + minutos;

    printf("%d", total);


}
