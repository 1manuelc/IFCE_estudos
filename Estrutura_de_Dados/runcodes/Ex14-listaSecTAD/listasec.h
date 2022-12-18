#ifndef __listase_h
#define __listase_h

#define V 1
#define F 0

typedef struct elem Elem;
typedef struct lista Lista;

Lista* lista_criar();
int lista_inserir_inicio(Lista* lista, float inserir);
int lista_inserir_fim(Lista* lista, float inserir);
int lista_inserir_indice(Lista* lista, float inserir, int indice);
void lista_exibir(Lista* lista);
void lista_exibir_maior(Lista* lista);
void lista_exibir_qtdMaiorQue(Lista* lista, float comparador);
int lista_remover_inicio(Lista* lista);
int lista_remover_ocorrencias(Lista* lista, float remover);
int lista_esvaziar(Lista* lista);
void lista_exibir_fim(Lista* lista);
void lista_exibir_inicio(Lista* lista);
void lista_exibir_qtd(Lista* lista);

#endif