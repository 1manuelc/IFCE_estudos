#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct elemento Elem;
typedef struct pilha Pilha;

struct elemento {
    char dado;
    struct elemento *prox;
};

struct pilha {
    int qtdElem;
    Elem *base;
    Elem *topo;
};

Pilha *pilha_criar() {
    Pilha *novaPilha = (Pilha*)malloc(sizeof(Pilha));
    if(novaPilha == NULL) {
        printf("Erro ao alocar\n");
        return NULL;
    }

    novaPilha->qtdElem = 0;
    novaPilha->base = NULL;
    novaPilha->topo = NULL;
    return novaPilha;
}

char pilha_pop(Pilha *pilha) {
    if(pilha == NULL)
        return 0;
    
    Elem *novoElem = pilha->topo;
    
    char removido = pilha->topo->dado;

    if(pilha->qtdElem == 0) {
        pilha->base = NULL;
        pilha->topo = NULL;
    } else {
        pilha->topo = pilha->topo->prox;
        free(novoElem);
        pilha->qtdElem--;
    }
    return removido;
}

int pilha_limpar(Pilha *pilha) {
    if(pilha == NULL)
        return 0;
    
    while(pilha->qtdElem != 0) {
        pilha_pop(pilha);
    } return 1;
}

int pilha_destruir(Pilha *pilha) {
    if(pilha == NULL) {
        printf("Erro, pilha nao definida\n");
        return 0;
    }

    if(pilha->qtdElem == 0) {
        free(pilha);
        return 1;
    } else {
        pilha_limpar(pilha);
        free(pilha);
        return 1;
    }
}

int pilha_push(Pilha *pilha, char inserir) {
    if(pilha == NULL) {
        return 0;
    }

    Elem *novoElem = (Elem*)malloc(sizeof(Elem));
    if(novoElem == NULL)
        return 0;
    
    novoElem->dado = inserir;
    novoElem->prox = pilha->topo;
    pilha->topo = novoElem;
    pilha->qtdElem++;

    return 1;
}

void pilha_exibir(Pilha *pilha) {
    Elem *aux = pilha->topo;
    
    if(pilha->qtdElem == 0) {
        printf("Pilha vazia\n");
    } else {
        while(aux != NULL) {
            printf("%c", aux->dado);
            aux = aux->prox;
        }
    }
}

void flush_in() {
    char ch;
    while((ch = fgetc(stdin)) != EOF && ch != '\n'){}
}

int main() {
    Pilha *pilha = pilha_criar();
    char opcao[4], inserir;
    
    do {
        scanf("%s", opcao);
        flush_in();

        if(strcmp("-s", opcao) == 0)
            pilha_exibir(pilha);
        if(strcmp("-c", opcao) == 0)
            pilha_limpar(pilha);
        if(strcmp("-i", opcao) == 0) {
            scanf("%c", &inserir);
            printf("%c", inserir);
            pilha_push(pilha, inserir);
        } if(strcmp("-r", opcao) == 0)
            pilha_pop(pilha);
    }while(strcmp("-s", opcao) != 0);

    pilha_destruir(pilha);

    system("pause");
    return 0;
}