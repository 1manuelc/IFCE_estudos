/*

Desenvolva um programa para calcular e escrever a área e o perímetro de um quadrado.
Dados de entrada: tamanho do lado (tipo da variável: numérico inteiro, valor em centímetros).
Essa conversão deve ser feita por meio da função printf().

*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int ladoQuadrado;
    printf("Medida do lado do quadrado (em cm): ");
    scanf("%d", &ladoQuadrado);
    
    printf("Perímetro do Quadrado: %d\nÁrea do Quadrado: %d", ladoQuadrado * 4, ladoQuadrado * ladoQuadrado);
    
    system("pause");
    return 0;
}
