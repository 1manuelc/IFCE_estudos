#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int dado;
    struct no *proximo;
}No;

// funcao para a operacao push
No *push(No *topo) {
    No *novo = malloc(sizeof(No));
    if(novo) {
        printf("Push: ");
        scanf("%d", &novo->dado);
        novo->proximo = topo;
        return novo;
    } else
        printf("\nErro ao alocar memoria\n");
    return NULL;
}

// funcao para a operacao pop
No *pop(No **topo) {
    if(*topo != NULL) {
        No *remover = *topo;
        *topo = remover->proximo;
        return remover;
    } else
        printf("\nPilha vazia!\n");
    return NULL;
}

void print(No *topo) {
    printf("\n---------------  PILHA  ---------------");
    if(topo == NULL)
        printf("\n\nPilha vazia!\n");
    else {
        while(topo) {
            printf("\n%d\n", topo->dado);
            topo = topo->proximo;
        }
    }
    printf("\n-------------  FIM PILHA  -------------\n\n");
}

int main() {
    No *remover, *topo = NULL;
    int opcao;

    do {
        printf("\n0 - Sair\n1 - Push\n2 - Pop\n3 - Print\n4 - Free\n");
        scanf("%d", &opcao);
        getchar();

        switch(opcao) {
            case 1:
                topo = push(topo);
                system("cls");
                break;
            case 2:
                remover = pop(&topo);
                system("cls");
                if(remover) {
                    printf("\nElemento removido com sucesso: %d\n", remover->dado);
                } else
                    printf("\nSem no para remover\n");
                break;
            case 3:
                print(topo);
                system("pause");
                system("cls");
                break;
            case 4:
                topo = NULL;
                remover = NULL;
                system("cls");
                break;
            default:
                if(opcao != 0)
                    printf("\nOpcao Invalida!\n");
                else
                    printf("\nFim do programa\n");
        }
    }while(opcao != 0);

    system("pause");
    return 0;
}