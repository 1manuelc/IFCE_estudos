#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

PPilha pilha_push(PPilha p, int *pQtd, TDado dado) {
    PPilha novo = (PPilha)malloc(sizeof(TPilha));

    if(novo) {
        novo->prox = p;
        *pQtd++;
        return novo;
    } else {
        printf("Erro ao realizar push!\n");
        return NULL;
    }
}

void pilha_exibe(PPilha p, int *pQtd) {
    PPilha aux = p;
    if(aux) {
        if(*pQtd == 0)
            printf("Pilha vazia\n");
        else {
            while(aux->prox != NULL) {
                printf("%c", aux->dado);
                aux = aux->prox;
            }
        }
    } else {
        printf("Erro ao exibir!\n");
    }
}

PPilha pilha_pop(PPilha *p, int *pQtd) {
    PPilha remove;
    if(p) {
        remove = *p;
        *p = remove->prox;
        pQtd--;
        return remove;
    } else {
        printf("Erro ao remover\n");
        return NULL;
    }
}

void pilha_esvaziar(PPilha p, PPilha remove, int *pQtd) {
    free(p);
    free(remove);
    *pQtd = 0;
}

void flush_in() {
    char ch;
    while( (ch = fgetc(stdin)) != EOF && ch != '\n' ){}
}

int main() {
    PPilha pilha, remove;
    TDado dado;
    char entrada[10];
    int contador = 0, *pQtd = &contador;
    pilha = pilha_cria(pilha);

    if(pilha) {
        if(pilha->prox == NULL) {
            do {
                scanf("%s", entrada);

                if(strcmp(entrada, "-s") == 0)
                    pilha_exibe(pilha, pQtd);
                else if(strcmp(entrada, "-c") == 0)
                    pilha_esvaziar(pilha, remove, pQtd);
                else if(strcmp(entrada, "-i") == 0) {
                    scanf("%c", &dado);
                    flush_in();
                    pilha_push(pilha, pQtd, dado);
                } else if(strcmp(entrada, "-r") == 0)
                    remove = pilha_pop(&pilha, pQtd);
            }while(*pQtd != 100);
        } else
            printf("Erro ao criar pilha\n");
    } else {
        printf("Erro ao alocar pilha\n");
        exit(0);
    }

    system("pause");
    return 0;
}