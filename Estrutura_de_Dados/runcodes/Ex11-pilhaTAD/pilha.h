#ifndef __pilha__h
#define __pilha__h

typedef struct elemento Elem;
typedef struct pilha Pilha;

Pilha *pilha_criar();
char pilha_pop(Pilha *pilha);
int pilha_limpar(Pilha *pilha);
int pilha_destruir(Pilha *pilha);
int pilha_push(Pilha *pilha, char inserir);
void pilha_exibir(Pilha *pilha);

#endif