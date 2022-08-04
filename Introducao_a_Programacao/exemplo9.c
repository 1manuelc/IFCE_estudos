/*

O custo de um carro novo ao consumidor é a soma do custo de fábrica com a porcentagem do distribuidor e dos impostos (aplicados ao custo de fábrica). Supondo que o percentual do distribuidor seja de 28% e os impostos de 45%, escrever um algoritmo para ler o curso de fábrica de um carro, calcular e escrever o custo final ao consumidor (com duas casas decimais).

*/

#include <stdio.h>

int main()
{
    float custoFabrica, custoFinal;

    scanf("%f", &custoFabrica);

    custoFinal = custoFabrica * 73/100 + custoFabrica;

    printf("%.2f", custoFinal);


}
