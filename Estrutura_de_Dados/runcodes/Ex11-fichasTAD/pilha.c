#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

struct Elem {       /*       Pilha        */
    PElem prox;
    TDado dado;
};

struct Pilha {      /*  Descritor de pilha  */
    int qtdElem;
    PElem base;
    PElem topo;
};

PPilha pilha_criar() {
    PPilha p = NULL;
    p = (PPilha)malloc(sizeof(TPilha));

    if(p != NULL) {
        p->base = NULL;
        p->topo = NULL;
        p->qtdElem = 0;
    } return p;
}

void pilha_push(PPilha p, TDado dado) {
    if(p == NULL)
        return;
    else {
        PElem e = NULL;
        e = (PElem)malloc(sizeof(TElem));
        
        if(e == NULL)
            return;
        else {
            e->dado = dado;
            e->prox = NULL;
            
            if(p->qtdElem == 0) {       /*      Pilha vazia, base e topo iguais         */
                p->base = e;
                p->topo = e;
            } else {                    /*      Pilha nao vazia, topo muda              */
                p->topo->prox = e;
                p->topo = e;
            } p->qtdElem++;
        }
    }
}

