/*
Faça um programa para ler dois inteiros X e Y representando um ponto em um plano cartesiano. Imprima qual quadrante esse ponto se encontra. Caso o ponto não esteja em algum eixo, imprima apenas a mensagem "eixos".

Entrada
A entrada consiste de duas linhas. A primeira linha contém o inteiro X. A segunda linha contém o inteiro Y.

Saída
A saída consiste de uma linha contendo a mensagem indicando qual o quadrante que o ponto está.

Exemplo de entrada	Exemplo de saída
1 2	                Q1
-2 2	            Q2
-5 -6	            Q3
4 -1	            Q4
7 0	                eixos
*/
#include <stdio.h>

int main() {
    int x, y;
    
    scanf("%i%i", &x, &y);
    
    if(x > 0 && y > 0)
        printf("Q1");
    
    if(x > 0 && y < 0)
        printf("Q4");
        
    if(x < 0 && y > 0)
        printf("Q2");
        
    if(x < 0 && y < 0)
        printf("Q3");
        
    if(x == 0 || y == 0)
        printf("eixos");
    
    return 0;
}
