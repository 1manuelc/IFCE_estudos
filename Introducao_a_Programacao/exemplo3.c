/* 03 - Faça um programa para ler dois valores inteiros A e B e imprima a área de um retângulo que tenha lados A e B. */

#include<stdio.h>

int main()
{
    int ladoA, ladoB, area;
    scanf("%d", &ladoA);
    scanf("%d", &ladoB);

    area = ladoA * ladoB;
    printf("%d", area);
    
    return 0;
}