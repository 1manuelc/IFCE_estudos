/*

Crie um programa que manipule a quantidade de chuva nos últimos 100 dias. Com ele, faça:

- Povoe o vetor com quantidades aleatórias de chuvas (em mm)
- Encontre e mostre o dia que mais choveu
- Calcule e mostre a quantidade média da chuva englobando todos os dias

Qual a complexidade de cada item no pior caso?

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main(){

    int qtdeChuvas[100], diaMaisChoveu = 0, posMaisChoveu = 0, acumuladorChuvas = 0, mediaChuvas;
    srand(time(NULL));

    for(int i = 0; i < 100; i++) {
        qtdeChuvas[i] = rand() % 1000;
        acumuladorChuvas += qtdeChuvas[i];

        if(qtdeChuvas[i] >= diaMaisChoveu) {
            diaMaisChoveu = qtdeChuvas[i];
            posMaisChoveu = i;
        }
    }
    
    mediaChuvas = acumuladorChuvas / 1000;
    printf("Maior chuva: %d\nDia em que mais choveu: %d\n", diaMaisChoveu, posMaisChoveu);
    printf("Quantidade media de chuva dos 100 dias: %dmm\n\n", mediaChuvas);

    system("pause");
}

// A complexidade de todos os itens no pior caso é O(n) = 100;

