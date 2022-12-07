#include <stdio.h>
#include <stdlib.h>

typedef struct fila Fila;
typedef struct elem Elem;

struct elem {
    int dado;
    Elem *prox;
};

struct fila {
    Elem *inicio;
    Elem *fim;
    int qtdElem;
};

Fila *fila_criar() {
    Fila *novaFila = (Fila*)malloc(sizeof(Fila));
    if(novaFila) {
        novaFila->inicio = NULL;
        novaFila->fim = NULL;
        novaFila->qtdElem = 0;

        return novaFila;

    } else {
        printf("Erro ao criar nova fila\n");
        return NULL;
    }
}

int fila_inserir(Fila *fila, int dado) {
    if(fila == NULL)
        return 0;
    
    Elem *aux, *novoElem = (Elem*)malloc(sizeof(Elem));
    if(novoElem) {
        novoElem->dado = dado;
        novoElem->prox = NULL;

        if(fila->qtdElem == 0) {
            fila->inicio = novoElem;
            fila->qtdElem += 1;

        } else {
            aux = fila->inicio;

            while(aux->prox != NULL)
                aux = aux->prox;
            
            aux->prox = novoElem;
            fila->fim = novoElem;
            fila->qtdElem += 1;

            return 1;
        }
    } else {
        printf("Erro ao alocar novo elemento\n");
        return 0;
    }
}

int fila_exibir(Fila *fila) {
    if(fila->inicio == NULL) {
        printf("Fila vazia\n");
        return 0;
    } else {
        Elem *aux = fila->inicio;
        for(int i = 0; i < fila->qtdElem; i++) {
            printf("%d", aux->dado);

            if(aux->prox != NULL)
                printf(" ");

            aux = aux->prox;

        } printf("\n");

        return 1;
    }
}

int fila_remover(Fila *fila) {
    int removido;
    if(fila) {
        if(fila->qtdElem == 0) {
            fila->inicio = NULL;
            fila->fim = NULL;
        } else {
            Elem *remover = fila->inicio;
            removido = remover->dado;

            fila->inicio = remover->prox;
            free(remover);
            fila->qtdElem -= 1;

            return removido;
        }        
    } else
        return 0;
}

int fila_esvaziar(Fila *fila) {
    if(fila) {
        if(fila->qtdElem == 0)
            return 1;
        else {
            while(fila->inicio != NULL)
                fila_remover(fila);
            return 1;
        }
    } else
        return 0;
}

int fila_destruir(Fila *fila) {
    if(fila->inicio = NULL) {
        free(fila);
        return 1;
    } else {
        fila_esvaziar(fila);
        free(fila);
        return 1;
    }
}

int main() {
    Fila *fila = fila_criar();
    fila_inserir(fila, 1);
    fila_inserir(fila, 2);
    fila_inserir(fila, 3);
    fila_inserir(fila, 4);
    fila_inserir(fila, 5);

    fila_exibir(fila);

    fila_remover(fila);
    fila_remover(fila);

    fila_exibir(fila);    

    fila_esvaziar(fila);
    fila_exibir(fila);

    fila_destruir(fila);
    system("pause");
    return 0;
}