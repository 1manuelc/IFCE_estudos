/*

Escreva um programa que, por meio de uma função, retorne a soma dos números inteiros que existem entre n1 e n2 (inclusive), ambos informados pelo usuário. A função deve funcionar inclusive se o valor de n2 for menor que n1. Ler n1 e n2 no programa principal e passá-los como parâmetro para a função.

*/

#include <stdio.h>

int diferencanumeros(int numero1, int numero2) {
    int acumuladorSoma = 0;

    if(numero1 == numero2)
        acumuladorSoma = numero1 + numero2;
    else if(numero1 > numero2) {
        for(int i = numero2; i <= numero1; i++) {
            acumuladorSoma += i;
        }
        } else {
            for(int i = numero1; i <= numero2; i++) {
                acumuladorSoma += i;
            }
        }
    return acumuladorSoma;
}

int main() {
    int n1, n2;
    scanf("%d%d", &n1, &n2);
    printf("%d", diferencanumeros(n1, n2));

    return 0;
}