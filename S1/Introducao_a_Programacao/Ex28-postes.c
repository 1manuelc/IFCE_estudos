/*
Seu João é proprietário de uma enorme fazenda, protegida por uma cerca formada por postes de madeira e arame farpado. Cada poste da cerca tem 1 metro de altura. Os postes são colocados separados dois metros um dos outros, ao redor de toda a fazenda, e portanto muitos postes são utilizados. Infelizmente um incêndio destruiu uma grande parte dos postes da cerca. Alguns postes, mesmo um pouco queimados, ainda podem ser utilizados, desde que sejam reforçados. Outros estão devem ser substituídos por postes novos. O engenheiro que trabalha para o Seu João percorreu toda a cerca e fez uma lista dos tamanhos de cada poste depois do incêndio. O engenheiro determinou que, se o poste tem menos do que 50 cm, ele deve ser substituído. Se o poste tem ao menos 50 cm, mas menos do que 85 cm, ele deve ser consertado. Se o poste tem 85 cm ou mais, ele não necessita conserto e pode ser usado normalmente. Dada a lista com os tamanhos de cada poste, escreva um programa para determinar o número de postes que devem ser substituídos e o número de postes que devem ser reforçados para consertar a cerca da fazenda do Seu João.

Entrada
A primeira linha da entrada contém um inteiro N, indicando o número de postes da cerca. A segunda linha contém N números inteiros, indicando os tamanhos dos postes após o incêndio.

Saída
Seu programa deve produzir uma única linha, contendo dois inteiros: o número de postes que devem ser substituídos, seguido do número de postes que devem ser consertados.

Exemplo de entrada	Exemplo de saída
5 85 49 50 84 50	1 3
4 48 49 30 47	    4 0
*/

#include <stdio.h>

int main() {
    int numeroPostes = 0, postes = 0, postesConserto = 0, postesSubstituir = 0;
    scanf("%d", &numeroPostes);
    
    for(int i = 0; i < numeroPostes; i++) {
        scanf("%d", &postes);
        
        if(postes < 50)
            postesSubstituir += 1;
        if(postes >= 50 && postes < 85)
            postesConserto += 1;
    }
    
    printf("%d %d", postesSubstituir, postesConserto);
    
    return 0;
}
