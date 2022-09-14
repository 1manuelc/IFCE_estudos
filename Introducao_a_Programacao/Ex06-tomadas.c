/* 

O time da Universidade conseguiu a classificação para a Final Nacional da Maratona de Programação da SBC. Os três membros do time e o técnico estão ansiosos para bem representar a Universidade. Eles planejam levar os seus equipamentos eletrônicos: celular, tablet, notebook, etc, e sabem que necessitarão de várias tomadas de energia para conectar esses equipamentos. Eles foram informados de que ficarão no mesmo quarto de hotel, mas já foram alertados de que no quarto há apenas uma tomada de energia. Precavidos, os membros do time compraram cada um uma régua de tomadas, permitindo ligar vários aparelhos e também podem ligar uma régua em outra para aumentar o número de tomadas disponíveis. No entanto, como as réguas têm muitas tomadas, eles pediram para você escrever um programa que, dado o número de tomadas em cada régua, determine o número máximo de aparelhos que podem ser conectados à energia num mesmo instante.

Entrada
A entrada consiste de quatro números inteiros T1, T2, T3, T4, indicando o número de tomadas de cada régua.

Saída
Uma única linha contendo um número inteiro, indicando o número máximo de aparelhos que podem ser conectados à energia num mesmo instante.

Exemplo de Entrada	Exemplo de Saída
2 4 3 2	            8
6 6 6 6	            21
2 2 2 2	            5

*/

#include<stdio.h>

int main()
{
    int tomada1, tomada2, tomada3, tomada4, total;
// qtde de tomadas pra cada régua
    scanf("%d%d%d%d", &tomada1, &tomada2, &tomada3, &tomada4);
    
// subtração de 1 tomada nas 3 primeiras réguas
    tomada1 -= 1;
    tomada2 -= 1;
    tomada3 -= 1;
    
    total = tomada1 + tomada2 + tomada3 + tomada4;
    printf("%d", total);

    return 0;
}