/*

2) Escreva um programa que solicite dois números inteiros ao usuário e que apresente na tela
como resultado o dobro desses números.

*/

#include <stdio.h>
#include <stdlib.h>

int dobro(int num) {
    int dobro;
    dobro = num * 2;
    return(dobro);
}

int main() {
    int num;
    scanf("%d", &num);

    num = dobro(num);
    printf("%d\n", num);

    scanf("%d", &num);

    num = dobro(num);
    printf("%d\n", num);

    system("pause");
    return 0;
}