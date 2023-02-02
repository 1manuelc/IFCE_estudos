/*

1) Escreva um programa que solicite dois números do tipo inteiro distintos ao usuário e que
apresente na tela o maior deles. Esse programa deve possuir uma função para verificar qual é
o maior número.

*/

#include <stdio.h>
#include <stdlib.h>

int greater(int num1, int num2) {
    int numGreater;
    if(num1 > num2) {
        numGreater = num1;
    } else {
        numGreater = num2;
    }
    return(numGreater);
}

int main() {
    int num1, num2, numGreater;
    scanf("%d%d", &num1, &num2);
    numGreater = greater(num1, num2);
    printf("%d\n", numGreater);

    system("pause");
    return 0;
}