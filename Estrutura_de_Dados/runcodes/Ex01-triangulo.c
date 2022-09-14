/*

Escreva um programa capaz de ler um valor n e mostre na tela conforme exemplificado abaixo (para n = 5):

1
2 2
3 3 3
4 4 4 4
5 5 5 5 5

*/

#include <stdio.h>

void triangular(int n) {
    if(n == 1)
        printf("1\n");
    else {
        triangular(n - 1);
        for(int i = 0; i < n; i++) {
            printf("%d ", n);
        }
        printf("\n");
    }
}

int main() {
    int n;
    scanf("%d", &n);

    triangular(n);

    return 0;
}