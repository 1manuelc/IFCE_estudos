/*

Escreva um programa modularizado com duas funções (uma iterativa e a outra recursiva) onde cada uma deve ser capaz de calcular o fatorial de N (recebido como parâmetro). 

*/

#include <stdio.h>
#include <stdlib.h>

int fatorialRec(int num) {
    if(num == 0 || num == 1)
        return 1;
    else
        return (num * fatorialRec(num - 1));
}

int fatorialIt(int num) {
    int acumuladorFatorial = 1;
    for(int i = num; i > 0; i--)
        acumuladorFatorial *= i;
    return acumuladorFatorial;
}

int main() {
    int n;
    char escolha;
    printf("Digite um valor acima de 1: ");
    scanf("%d", &n);

    printf("%d! = %d\n", n, fatorialRec(n));
    printf("%d! = %d\n", n, fatorialIt(n));

    system("pause");
    return 0;
}