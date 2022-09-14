/*

Bino vai viajar e gostaria de saber qual o tempo em segundos que vai durar sua viajem. O vôo de ida está marcado para o dia D1 do ano, às H1 horas e M1 minutos. O vôo de volta vai chegar no dia D2, às H2 horas e M2 minutos. Imprima quantos segundos se passaram deste a saída de Bino até sua chegada. É garantido que Bino volta em um momento posterior do que sai. Também é garantido que a viajem de Bino não passa de um ano para outro.

Entrada
A entrada consiste de 6 linhas. Primeira linha contém um inteiro D1. Segunda linha contém um inteiro H1. Terceira linha contém um inteiro M1. Quarta linha contém um inteiro D2. Quinta linha contém em um inteiro H2. Terceira linha contém um inteiro M2.

Saída
Seu programa deve imprimir uma linha com a quantidade de segundos igual ao tempo da viagem de Bino.

Exemplo de Entrada	Exemplo de Saída
5 10 25 5 11 25	    3600
5 10 25 6 11 15	    89400

*/

#include <stdio.h>

int main()
{
    int dia1, hr1, min1;
    int dia2, hr2, min2;
    int inicioTot, fimTot, segsDelta;

    scanf("%d%d%d", &dia1, &hr1, &min1);
    scanf("%d%d%d", &dia2, &hr2, &min2);
    
    // dia1 * 12h * 60min * 60s
    dia1 *= 24 * 3600;
    // hr1 * 60min * 60s
    hr1 *= 3600;
    // min1 * 60s
    min1 *= 60;
    
    // dia2 * 12h * 60min * 60s
    dia2 *= 24 * 3600;
    // hr2 * 60min * 60s
    hr2 *= 3600;
    // min2 * 60s
    min2 *= 60;
    
    // calculo do total de segs p ocasiao
    inicioTot = dia1 + hr1 + min1;
    fimTot = dia2 + hr2 + min2;
    
    // calculo do total de segundos
    segsDelta = fimTot - inicioTot;
    
    printf("%d", segsDelta);
    
    return 0;
}