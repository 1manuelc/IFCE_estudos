#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

int main() {
    Pilha *pilha = pilha_criar();
    char opcao[4], inserir;
    
    do {
        scanf("%s%*c", opcao);
        
        if(strcmp("-s", opcao) == 0)
            pilha_exibir(pilha);
        if(strcmp("-c", opcao) == 0)
            pilha_limpar(pilha);
        if(strcmp("-i", opcao) == 0) {
            scanf("%c", &inserir);
            pilha_push(pilha, inserir);
        } if(strcmp("-r", opcao) == 0)
            pilha_pop(pilha);
    }while(strcmp("-s", opcao) != 0);

    pilha_destruir(pilha);

    return 0;
}