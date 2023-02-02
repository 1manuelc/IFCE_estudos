#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"

int main() {
    Fila *fila = fila_criar();
    char opcao[4];
    int inserir;
    
    do {
        scanf("%s%*c", opcao);
        
        if(strcmp("-s", opcao) == 0)
            fila_exibir(fila);
        if(strcmp("-c", opcao) == 0)
            fila_esvaziar(fila);
        if(strcmp("-i", opcao) == 0) {
            scanf("%d", &inserir);
            fila_inserir(fila, inserir);
        } if(strcmp("-r", opcao) == 0)
            fila_remover(fila);
    }while(strcmp("-s", opcao) != 0);

    fila_destruir(fila);

    return 0;
}