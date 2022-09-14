/*
Um jogo de cartas que faz muito sucesso no reino da Nlogônia é chamado zip. Nesse jogo, apenas os valores das cartas são utilizados (ás a rei), os naipes das cartas são ignorados. Para simplificar, vamos considerar os valores das cartas como inteiros de 1 a 13. Em cada partida do jogo cada jogador recebe duas cartas. As regras para determinar quem ganha a partida são baseadas nos valores das cartas de cada jogador:

    -   se as duas cartas têm o mesmo valor, o jogador recebe como pontuação na partida duas vezes a soma dos valores das cartas.
    -   se os valores das duas cartas são números consecutivos (por exemplo, 2 e 3, ou 13 e 12), o jogador recebe como pontuação na partida três vezes a soma dos valores das cartas. 
    -   caso contrário, o jogador recebe como pontuação na partida a soma dos valores das cartas.
    -   Ganha a partida o jogador que tiver recebido a maior pontuação. Lia e Carolina estão jogando zip, e querem que você escreva um programa para conferir quem ganhou cada partida.

Entrada
A entrada é composta por quatro valores inteiros. Os dois primeiros valores indicam as cartas de Lia e os dois últimos valores indicam as cartas de Carolina.

Saída
Seu programa deve produzir uma única linha, contendo o nome da jogadora que venceu a partida. Se houve empate, a linha deve conter a palavra empate.

Exemplo de Entrada	Exemplo de Saída
3 3 7 4	            Lia
2 3 11 4	        Empate
5 5 4 3	            Carolina
*/

#include <stdio.h>

int main() {
    int valor1, valor2, valor3, valor4, soma1, soma2;
    scanf("%i%i%i%i", &valor1, &valor2, &valor3, &valor4);

    soma1 = valor1 + valor2;
    soma2 = valor3 + valor4;

// verificação Lia
    // se os valores forem iguais
    if(valor1 == valor2)
        soma1 *= 2;
    
    // se valor2 for decrescente de valor1
    // se valor1 for decrescente de valor2
    if(valor1 - 1 == valor2 || valor2 - 1 == valor1)
        soma1 *= 3;
    
    // se valor1 e valor2 forem diferentes
    // se valor2 NÃO for decrescente de valor1
    // se valor1 NÃO for decrescente de valor2
    if(valor1 != valor2 && valor1 - 1 != valor2 && valor2 - 1 != valor1)
        soma1 = soma1;

// verificação Carolina   
    // se valor3 e valor4 forem iguais
    if(valor3 == valor4)
        soma2 *= 2;

    // se valor4 for decrescente de valor3
    // se valor3 for decrescente de valor4
    if(valor3 - 1 == valor4 || valor4 - 1 == valor3)
        soma2 *= 3;
    
    // se valor3 for diferente de valor4
    // se valor4 NÃO for decrescente de valor3
    // se valor3 NÃO for decrescente de valor4
    if(valor3 != valor4 && valor3 - 1 != valor4 && valor4 - 1 != valor3)
        soma2 = soma2;

// Rankeamento
    // se soma1 for maior que soma2, Lia ganhou
    if(soma1 > soma2)
        printf("Lia");
    
    // se soma2 for maior que soma1, Carolina ganhou
    if(soma2 > soma1)
        printf("Carolina");
    
    // se soma1 for igual soma2, há um Empate
    if(soma1 == soma2)
        printf("Empate");

    return 0;
}
