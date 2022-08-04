/* Escrever um programa em C que leia o público total de um jogo de futebol e forneça a renda do jogo, sabendo que haviam 4 tipos de ingressos e que eles foram assim distribuídos:

Tipo de ingresso	Percentual do público	Valor do ingresso
Popular	            10%                     R$ 1,00
Geral	            50%	                    R$ 5,00
Arquibancada	    30%	                    R$ 10,00
Cadeiras           10%	                    R$ 20,00

*/

#include<stdio.h>

int main()
{
    float publicoTotal, ingressoPopular, ingressoGeral, ingressoArquibancada, ingressoCadeiras, receitaTotal;
    
    scanf("%f", &publicoTotal);
    ingressoPopular = publicoTotal * 0.1;
    ingressoGeral = publicoTotal * 0.5 * 5;
    ingressoArquibancada = publicoTotal * 0.3 * 10;
    ingressoCadeiras = publicoTotal * 0.1 * 20;
    receitaTotal = ingressoPopular + ingressoCadeiras + ingressoArquibancada + ingressoCadeiras;

    printf("R$ %.2f", receitaTotal);
    
    return 0;
}