/*
Leia um número inteiro X. Em seguida mostre os números ímpares de 1 até X, um valor por linha, inclusive o X, se for o caso.

Entrada
Um número inteiro.

Saída
Os números ímpares de 1 até X, inclusive X, se for o caso (um número em cada linha).

Exemplo de entrada	Exemplo de saída
8	                1 3 5 7
9	                1 3 5 7 9
*/

#include <stdio.h>

int main() {
    int num = 0;
    scanf("%d", &num);
    
    // se for ímpar //
    if(num % 2 == 1) {
        for(int i = 1; i <= num; i += 2)
            printf("%d\n", i);
    }
    // se for par //
    if(num % 2 == 0) {
        for(int i = 1; i < num; i += 2)
            printf("%d\n", i);
    }
    return 0;
}
