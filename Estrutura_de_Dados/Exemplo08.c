/*

Escreva um programa modularizado com duas funções (uma iterativa e a outra recursiva) onde cada uma deve ser capaz de calcular o n-ésimo termo de Fibonacci (recebido como parâmetro).

*/

#include <stdio.h>
#include <stdlib.h>

int fibonacciRec(int num) {
    if(num <= 2)
        return 1;
    else
        return fibonacciRec(num - 1) + fibonacciRec(num - 2);
}

int fibonacciIt(int num) {
    int a = 0, b = 1, c;

    while(num - 2 >= 0) {
        // c (novo termo) é a soma dos anteriores (a+b)
        c = a + b;
        /*
            a   b   c(a+b)
            0   1   1
            <----
            a   b   c(a+b novos)
            1   1   2
        */
        a = b;
        b = c;
        // diminui o número de repetições até chegar ao caso base F(2) = 1
        num = num - 1;
    }
    return c;
}

int main() {
    int n;
    printf("Digite um numero: ");
    scanf("%d", &n);

    printf("F(%d) = %d", n, fibonacciRec(n));
    printf("\nF(%d) = %d\n", n, fibonacciIt(n));

    system("pause");
    return 0;
}