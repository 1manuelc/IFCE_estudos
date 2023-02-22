/*

Uma empresa tem vários funcionários e todo mês tem dificuldade em contabilizar a folha de pagamento dos funcionários. Por isso, a empresa pediu sua ajuda para construir um algoritmo para, dada a quantidade de funcionários e o salário de cada funcionário, calcule o valor total pago e a média de salário paga aos funcionários. (3pts)

Entrada
A primeira linha contém um número inteiro N, indicando o número de funcionários. A segunda linha contém N números fracionários indicando o salário pago a cada funcionário.

Saída
Dois números fracionários correspondendo ao valor total pago e a média de salário paga.

*/

#include <stdio.h>

int main() {
    int qtdeFuncionarios;
    scanf("%d", &qtdeFuncionarios);

    float folhaPgto[qtdeFuncionarios], somaTotal = 0, mediaSalarial;
    for(int i = 0; i < qtdeFuncionarios; i++) {
        scanf("%f", &folhaPgto[i]);
        somaTotal += folhaPgto[i];
    }

    mediaSalarial = somaTotal / qtdeFuncionarios;

    printf("%.2f\n", somaTotal);
    printf("%.2f", mediaSalarial);

    return 0;
}