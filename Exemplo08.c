/*

Escreva um programa modularizado com duas funções (uma iterativa e a outra recursiva) onde cada uma deve ser capaz de calcular o n-ésimo termo de Fibonacci (recebido como parâmetro).

*/

#include <stdio.h>
#include <stdlib.h>

int fibonacciRec(int num) {
    if(num < 2)
        return 1;
    else
        return fibonacciRec(num - 1) + fibonacciRec(num - 2);
}

int fibonacciIt(int num) {
    
    return num;
}

int main() {
    int n;
    printf("Digite um numero: ");
    scanf("%d", &n);

    printf("\nF(%d) = %d", n, fibonacciRec(n));
    printf("\nF(%d) = %d", n, fibonacciIt(n));

    system("pause");
    return 0;
}