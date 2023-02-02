#ifndef __fila__h
#define __fila__h

typedef struct fila Fila;
typedef struct elem Elem;

Fila *fila_criar();
int fila_inserir(Fila *fila, int dado); // -i
int fila_exibir(Fila *fila); // -s
int fila_remover(Fila *fila); // -r
int fila_esvaziar(Fila *fila); // -c
int fila_destruir(Fila *fila);

#endif