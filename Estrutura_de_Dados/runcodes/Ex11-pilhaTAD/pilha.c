#include <stdio.h>
#include <stdlib.h>

typedef struct pilha TPilha, *PPilha;
typedef char TDado;

struct pilha{
    TDado dado;
    PPilha prox;
};

PPilha pilha_cria(PPilha p) {
    p = (PPilha)malloc(sizeof(TPilha));
    p->prox = NULL;
    return p;
}

PPilha pilha_push(PPilha p, TDado dado) {
    PPilha novo = (PPilha)malloc(sizeof(TPilha));
    if(novo) {
        novo->dado = dado;
        novo->prox = p;
        return novo;
    } else {
        printf("Erro ao realizar push!\n");
        return NULL;
    }
}

void pilha_exibe(PPilha p) {
    PPilha aux = p;
    if(aux) {
        while(aux->prox != NULL) {
            printf("%c\n", aux->dado);
            aux = aux->prox;
        }
    } else {
        printf("Erro ao exibir!\n");
    }
}

int main() {
    PPilha pilha;
    if(pilha) {
        pilha = pilha_cria(pilha);
        if(pilha->prox == NULL) {
            pilha = pilha_push(pilha, 'a');
            pilha = pilha_push(pilha, 'b');
            pilha = pilha_push(pilha, 'c');
            pilha_exibe(pilha);
        } else
            printf("Erro ao criar pilha\n");
    } else {
        printf("Erro ao alocar pilha\n");
        exit(0);
    }

    system("pause");
    return 0;
}