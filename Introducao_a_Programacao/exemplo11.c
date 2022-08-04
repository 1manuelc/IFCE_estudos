/*

Leia um valor inteiro. A seguir, calcule o menor número de notas possíveis (cédulas) no qual o valor pode ser decomposto. As notas consideradas são de 100, 50, 20, 10, 5, 2 e 1. A seguir mostre o valor lido e a relação de notas necessárias.

Entrada
O arquivo de entrada contém um valor inteiro N (0 < N < 1000000).

Saída
Imprima o valor lido e, em seguida, a quantidade mínima de notas de cada tipo necessárias, conforme o exemplo fornecido.

Exemplo de entrada	Exemplo de saída
576	                576
                    5 nota(s) de R$ 100
                    1 nota(s) de R$ 50
                    1 nota(s) de R$ 20
                    0 nota(s) de R$ 10
                    1 nota(s) de R$ 5
                    0 nota(s) de R$ 2
                    1 nota(s) de R$ 1

*/

#include<stdio.h>

int main()
{
    int quantia, notas100, notas50, notas20, notas10, notas5, notas2, notas1;
    scanf("%d", &quantia);
    
    notas100 = quantia / 100;
    notas50 = (quantia % 100) / 50;
    notas20 = (quantia % 100 % 50) / 20;
    notas10 = (quantia % 100 % 50 % 20) / 10;
    notas5 = (quantia % 100 % 50 % 20 % 10) / 5;
    notas2 = (quantia % 100 % 50 % 20 % 10 % 5) / 2;
    notas1 = (quantia % 100 % 50 % 20 % 10 % 5 % 2);
    
    printf("%d\n", quantia);
    printf("%d nota(s) de R$ 100\n", notas100);
    printf("%d nota(s) de R$ 50\n", notas50);
    printf("%d nota(s) de R$ 20\n", notas20);
    printf("%d nota(s) de R$ 10\n", notas10);
    printf("%d nota(s) de R$ 5\n", notas5);
    printf("%d nota(s) de R$ 2\n", notas2);
    printf("%d nota(s) de R$ 1", notas1);
    
    return 0;
}