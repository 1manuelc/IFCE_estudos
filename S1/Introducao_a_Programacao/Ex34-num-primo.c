/*

Número Primo
Faça um programa que verifica se um determinado número é primo. Matematicamente, considera-se como número primo aquele número que é divisível apenas por 1 e por ele mesmo.

Entrada
Um número inteiro

Saída
S indicando que o número é primo ou N, caso contrário.

*/

#include <stdio.h>
int main() {
    int numero, resultado = 0;
    scanf("%d", &numero);
    
    for(int i = 2; i <= numero / 2; i++) {
        if(numero % i == 0)
            resultado++;
    }
    
    if(resultado == 0)
        printf("S");
    else
        printf("N");

    return 0;
}