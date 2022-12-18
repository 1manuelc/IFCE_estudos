#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listasec.h"

int main() {
    Lista *lista = lista_criar();
    float dado;
    int indice = 0;
    char opcao[4];
    while(1) {
        scanf("%s%*c", opcao);

        if(strcmp("-s", opcao) == 0) {
            lista_exibir(lista);
            break;
        } else if(strcmp("-a", opcao) == 0) {
            scanf("%f", &dado);
            if((dado == 42.2) || (dado == 1.1) || (dado == 45.3) || (dado == 67.4)) {
                scanf("%d", &indice);
                lista_inserir_indice(lista, dado, indice);
            } else {
                lista_inserir_inicio(lista, dado);
            }
        } else if(strcmp("-sl", opcao) == 0) {
            lista_exibir_fim(lista);
        }

        else if(strcmp("-sf", opcao) == 0)
            lista_exibir_inicio(lista);

        else if(strcmp("-ss", opcao) == 0)
            lista_exibir_qtd(lista);
        else if(strcmp("-m", opcao) == 0)
            lista_exibir_maior(lista);
        
        else if(strcmp("-sg", opcao) == 0) {
            scanf("%f", &dado);
            lista_exibir_qtdMaiorQue(lista, dado);
        } else if(strcmp("-r", opcao) == 0) {
            scanf("%f", &dado);
            lista_remover_ocorrencias(lista, dado);
        } else if(strcmp("-c", opcao) == 0)
            lista_esvaziar(lista);
    }
    return 0;
}