#ifndef __pilha__h
#define __pilha__h

typedef struct Pilha TPilha, *PPilha;
typedef struct Elem TElem, *PElem;
typedef int TDado;

PPilha pilha_criar();
void pilha_push(PPilha p, TDado dado);
TDado pilha_pop(PPilha p);
void pilha_exibir(PPilha p);
void pilha_destruir(PPilha p);

#endif