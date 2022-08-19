/* Escreva um programa que solicite dois números ao usuário e que apresente na tela o
resultado da sua soma e o dobro de cada um deles. Esse programa deve possuir duas
funções, uma para calcular a soma e outro para calcular o dobro desses números. */

#include <stdio.h>
#include <stdlib.h>

int somar(int numero1, int numero2) {
    int soma = numero1 + numero2;
    return(soma);
}

int dobrar(int numero) {
    return (numero * 2);
}

int main() {
    int numero1, numero2, soma, dobro1, dobro2;
    printf("Digite o primeiro numero: ");
    scanf("%d", &numero1);

    printf("Digite o segundo numero: ");
    scanf("%d", &numero2);

    soma = somar(numero1, numero2);
    printf("\nSoma dos dois numeros: %d\n", soma);

    dobro1 = dobrar(numero1);
    printf("\nDobro do numero 1: %d\n", dobro1);
    dobro2 = dobrar(numero2);
    printf("\nDobro do numero 2: %d\n\n", dobro2);

    system("pause");
    return 0;
}