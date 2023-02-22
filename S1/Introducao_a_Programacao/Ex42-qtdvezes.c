/*

Quantidade de vezes
Faça um programa para ler 10 números inteiros, armazená-los em um vetor e depois ler um número inteiro X. Imprima a(s) posição(ões) e a quantidade de vezes que X aparece no vetor.

Entrada
A primeira linha contém 10 números inteiros. A segunda linha contém um número inteiro X a ser buscado no vetor.

Saída
A primeira linha contém N números inteiros, correspondendo a(s) posição(ões) em que X aparece no vetor. A segunda linha contém um número inteiro correspondendo a quantidade de vezes que X aparece no vetor.

Exemplo de entrada	        Exemplo de saída
1 2 10 4 5 6 7 8 9 10	    2 9
10	                        2
2 2 1 1 2 2 1 1 2 2	        0 1 4 5 8 9
2	                        6
1 2 10 4 5 6 7 8 9 10	
13	                        0

*/

#include <stdio.h>

int main() {
    int num[10], numX;
    int posicoes[10], contador = 0;
    
    for(int i = 0; i < 10; i++)
        scanf("%d", &num[i]);
    
    scanf("%d", &numX);
    
    for(int i = 0; i < 10; i++) {
        if(numX == num[i]) {
            posicoes[0 + i] = i;
            printf("%d ", posicoes[0 + i]);
            contador++;
        } else
            continue;  
    }
    
    printf("\n%d", contador);
    
    return 0;
}