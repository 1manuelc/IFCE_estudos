#include <stdio.h>
#include <stdlib.h>

int somar(int numero1, int numero2) {
    
    int soma = numero1 + numero2;
    return(soma);
}

int main() {
    int numero1, numero2, soma;
    scanf("%d%d", &numero1, &numero2);

    soma = somar(numero1, numero2);
    printf("%d\n", soma);

    system("pause");
    return 0;
}