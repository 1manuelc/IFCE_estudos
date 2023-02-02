/*
Escreva um programa que leia o salário de um empregado e imprima o desconto do INSS segundo a tabela abaixo.

Faixa salarial	                                    Taxa de contribuição
Menor ou igual a R$ 600,00	                        Isento
Maior que R$ 600 e menor ou igual a R$ 1200	        20%
Maior que R$ 1200 e menor ou igual a R$ 2000	    25%
Maior que R$ 2000	                                30%

Entrada
Um número fracionário correspondendo ao salário do funcionário.

Saída
Um número fracionário correspondendo a taxa do INSS em reais.
*/

#include <stdio.h>
#include <stdlib.h>

void main() {
    float salarioFuncionario, isencaoFuncionario;
    scanf("%f", &salarioFuncionario);

    if(salarioFuncionario <= 600.00)
        isencaoFuncionario = 0;
    else if(salarioFuncionario > 600.00 && salarioFuncionario <= 1200.00)
        isencaoFuncionario = 0.2;
    else if(salarioFuncionario > 1200.00 && salarioFuncionario <= 2000.00)
        isencaoFuncionario = 0.25;
    else if(salarioFuncionario > 2000.00)
        isencaoFuncionario = 0.3;
    
    printf("R$ %.2f", (salarioFuncionario * isencaoFuncionario));
    system("pause");
}