/*

Maria acabou de iniciar seu curso de graduação na faculdade de medicina e precisa de sua ajuda para organizar os experimentos de um laboratório o qual ela é responsável. Ela quer saber no final do ano, quantas cobaias foram utilizadas no laboratório e o percentual de cada tipo de cobaia utilizada. Este laboratório em especial utiliza três tipos de cobaias: sapos, ratos e coelhos. Para obter estas informações, ela sabe exatamente o número de experimentos que foram realizados, o tipo de cobaia utilizada e a quantidade de cobaias utilizadas em cada experimento.

Entrada
Três números inteiros que representam a quantidade de cobaias utilizadas coelho, rato e sapo, respectivamente.

Saída
Apresente o total de cobaias utilizadas e o percentual de em relação ao total de coelhos, ratos e sapos, respectivamente. O percentual deve ser apresentado com dois dígitos após o ponto.

Exemplo de Entrada	Exemplo de Saída
29 40 23	        92 31.52 43.48 25.00

*/

#include <stdio.h>

int main()
{
    float qtdCoelhos, qtdRatos, qtdSapos;
    float somaCobaias;
    float percentualCoelhos, percentualRatos, percentualSapos;

    scanf("%f%f%f", &qtdCoelhos, &qtdRatos, &qtdSapos);

    somaCobaias = qtdCoelhos + qtdRatos + qtdSapos;

    percentualCoelhos = qtdCoelhos / somaCobaias * 100;
    percentualRatos = qtdRatos / somaCobaias * 100;
    percentualSapos = qtdSapos / somaCobaias *100;

    printf("%.0f %.2f %.2f %.2f", somaCobaias, percentualCoelhos, percentualRatos, percentualSapos);


    return 0;
}
