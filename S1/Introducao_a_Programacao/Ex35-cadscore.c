/*

CadScore
No jogo CadScore o jogador terá que passar por diversas fases, após cada fase ele pode ganhar ou perder pontos, mas nunca sua pontuação pode ser menor do que zero ou maior do que 100, não importa quantos pontos ele ganhe ou perca. João está jogando a um tempo e agora ele acabou de ter uma ideia para simular quantos pontos ele terá caso consiga uma determinada quantidade de pontos nas próximas N fases do jogo. Como João não consegue parar de jogar você terá que ajudá-lo fazendo o programa. João irá lhe informar quantos pontos ele já acumulou até agora e quantas fases ele pretende passar, ele irá então informar quantos pontos ele pretende conseguir em cada fase, com essas informações calcule a pontuação final de João.

Entrada
A entrada consiste de duas linhas, a primeira linha contém dois inteiros P e N, representando a pontuação atual e a quantidade de fases que João pretende passar. A segunda linha possui N inteiros distintos representando a quantidade de pontos que João pretende conseguir em cada fase.

Saída
A saída do seu programa deve conter apenas uma linha, informando a pontuação final de João.

Exemplo de entrada	Exemplo de saída
50 4
11 20 -15 -13	    53
50 5
30 30 30 40 -78	    100
25 4
20 -20 -30 3	    0

*/

#include <stdio.h>

int main() {
    int pontosAtuais, fasesPretendidas, pontosTotais = 0;
    scanf("%d%d", &pontosAtuais, &fasesPretendidas);
    pontosTotais = pontosAtuais;
    
    for(int i = 0; i < fasesPretendidas; i++) {
        scanf("%d", &pontosAtuais);
        pontosTotais += pontosAtuais;
    }
    
    if(pontosTotais > 100)
        pontosTotais = 100;
    else {
        if(pontosTotais < 0)
            pontosTotais = 0;
    }
    
    printf("%d", pontosTotais);
    
    return 0;
}