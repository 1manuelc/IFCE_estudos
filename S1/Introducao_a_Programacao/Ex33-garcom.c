/*

Garçom
Parte do treinamento de um novo garçom é carregar uma grande bandeja com várias latas de bebidas e copos e entregá-las todas numa mesa do restaurante. Durante o treinamento é comum que os garçons deixem cair as bandejas, quebrando todos os copos. A SBC (Sociedade Brasileira de Copos) analisou estatísticas do treinamento de diversos garçons e descobriu que os garçons em treinamento deixam cair apenas bandejas que têm mais latas de bebidas que copos. Por exemplo, se uma bandeja tiver 10 latas e 4 copos, certamente o garçom em treinamento a deixará cair, quebrando os 4 copos. Já se a bandeja tiver 5 latas e 6 copos, ele conseguirá entregá-la sem deixar cair. Escreva um programa que, dado o número de latas e copos em cada bandeja que o garçom tentou entregar, imprime o total de copos que ele quebrou.

Entrada
A primeira linha da entrada contém um inteiro N representando o número de bandejas que o garçom tentou entregar. As N linhas seguintes representam as N bandejas. Cada linha contém dois inteiros L e C, indicando o número de latas e o número de copos naquela bandeja, respectivamente.

Saída
Seu programa deve imprimir uma única linha, contendo um único inteiro, indicando o número total de copos que o garçom quebrou.

Exemplo de entrada	Exemplo de saída
3	                5
10 5
6 8
3 3
4	                7
10 6
8 8
5 1
100 100
3	                0
5 5
4 4
3 3

*/

#include <stdio.h>

int main() {
    int bandejas, qtdeLatas, qtdeCopos, coposQuebrados = 0;
    scanf("%d", &bandejas);
    
    for(int i = 0; i < bandejas; i++) {
        scanf("%d%d", &qtdeLatas, &qtdeCopos);
        
        if(qtdeLatas > qtdeCopos) {
            coposQuebrados += qtdeCopos;
        }
    }
    
    printf("%d", coposQuebrados);
    
    return 0;
}
