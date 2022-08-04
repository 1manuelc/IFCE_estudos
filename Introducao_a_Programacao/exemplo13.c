/*

Carol entrará de férias e, nesse período, resolveu viajar para os Estados Unidos. Como a moeda dos Estados Unidos é o dólar, Carol precisará trocar seu dinheiro de real para dólar. Ela pediu sua ajuda para escrever um algoritmo que receba a quantidade de reais que ela deseja trocar e a cotação de dólar para real, e exiba qual o valor correspondente em dólar.

*/

#include <stdio.h>

int main()
{
    float qtdReais, cotacaoDolar, qtdDolar;

    scanf("%f", &qtdReais);
    scanf("%f", &cotacaoDolar);

    qtdDolar = qtdReais / cotacaoDolar;

    printf("%.2f", qtdDolar);

    return 0;
}