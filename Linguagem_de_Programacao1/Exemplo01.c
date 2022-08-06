/*

Escreva um programa em C para a secretaria de saúde do ceará que o auxilie nas
informações sobre a COVID. Esse programa deve receber os dados sobre o número de casos
suspeitos, o número de casos confirmados e o número de mortes, em seguida apresente o
resultado na tela.

*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numeroCasos_suspeitos, numeroCasos_confirmados, numeroObitos;
    printf("Bem vindo(a) ao programa de acesso público dos dados da COVID-19");
    printf("\nFeito pela Secretaria de Saúde do Estado do Ceará - 2022");
    
    printf("\nInsira o número de casos suspeitos: ");
    scanf("%d", &numeroCasos_suspeitos);
    
    printf("Insira o número de casos confirmados: ");
    scanf("%d", &numeroCasos_confirmados);
    
    printf("Insira número de óbitos: ");
    scanf("%d", &numeroObitos);
    
    printf("\nEstatísticas COVID-19 hoje:");
    printf("\nCasos Suspeitos: %d\nCasos Confirmados: %d\nÓbitos: %d", numeroCasos_suspeitos, numeroCasos_confirmados, numeroObitos);
    
    system("pause");
    return 0;
}
