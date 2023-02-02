/*
Bino está tentando contar até 100000. Porém quando ele estava no número XX, ele não se lembrou dos próximos números. Para ajudar Bino, imprima os próximos 10 valores inteiros maiores que XX.

Entrada
A entrada consiste de uma linha contendo um inteiro XX.

Saída
A saída consiste de uma linha contendo os 10 próximos números maiores que XX separados por um espaço.

Exemplo de entrada	Exemplo de saída
10	                11 12 13 14 15 16 17 18 19 20
22	                23 24 25 26 27 28 29 30 31 32
*/

#include <stdio.h>

int main() {
    int num = 0;
    scanf("%i", &num);
    
    for(int i = 0; i < 10; i++)
    {
        num += 1;
        printf("%d ", num);
    }

    return 0;
}
