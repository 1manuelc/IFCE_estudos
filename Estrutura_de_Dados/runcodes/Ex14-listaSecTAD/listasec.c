#include <stdio.h>
#include <stdlib.h>
#include "listasec.h"

struct elem {
    float dado;
    Elem* prox;
};

struct lista {
    Elem* inicio;
    Elem* fim;
    int qtdElem;
    int circular;
};

Lista* lista_criar() {
    Lista* novaLista = (Lista*)malloc(sizeof(Lista));
    
    if(novaLista == NULL) {
        printf("Erro ao criar a lista\n");
        return NULL;
    }

    novaLista->qtdElem = 0;
    novaLista->circular = V;
    novaLista->inicio = NULL;
    novaLista->fim = NULL;

    return novaLista;
}

int lista_inserir_inicio(Lista* lista, float inserir) {
    if(lista == NULL) {
        printf("Erro, lista nao definida\n");
        return 0;
    }

    Elem* novoElem = (Elem*)malloc(sizeof(Elem));
    if(novoElem == NULL) {
        printf("Erro ao criar novo elemento\n");
        return 0;
    }

    novoElem->dado = inserir;
    novoElem->prox = NULL;

    if(lista->qtdElem == 0) {
        lista->inicio = novoElem;
        lista->fim = novoElem;
    } else {
        novoElem->prox = lista->inicio;
        lista->fim = lista->inicio;
        lista->inicio = novoElem;
    }

    if(lista->circular == V)
        lista->fim->prox = lista->inicio;
    
    lista->qtdElem++;

    return 1;
}

int lista_inserir_fim(Lista* lista, float inserir) {
    if(lista == NULL) {
        printf("Erro, lista nao definida\n");
        return 0;
    }

    Elem* novoElem = (Elem*)malloc(sizeof(Elem));
    if(novoElem == NULL) {
        printf("Erro ao criar novo elemento\n");
        return 0;
    }

    novoElem->dado = inserir;
    novoElem->prox = NULL;

    if(lista->qtdElem == 0) {
        lista->inicio = novoElem;
        lista->fim = novoElem;
    } else {
        lista->fim->prox = novoElem;
        lista->fim = novoElem;
    }

    if(lista->circular == V) {
        lista->fim->prox = lista->inicio;
    }

    lista->qtdElem++;

    return 1;
}

int lista_inserir_indice(Lista* lista, float inserir, int indice) {
    if(lista == NULL) {
        printf("Erro, lista nao definida\n");
        return 0;
    }

    if((indice < 0) || (indice > lista->qtdElem + 1)) {
        printf("Erro, indice fora do limite\n");
        return 0;
    }

    if(indice == 0) {
        lista_inserir_inicio(lista, inserir);
        return 1;
    }

    if(indice == lista->qtdElem) {
        lista_inserir_fim(lista, inserir);
        return 1;
    }

    Elem* novoElem = (Elem*)malloc(sizeof(Elem));
    if(novoElem == NULL) {
        printf("Erro ao criar novo elemento\n");
        return 0;
    }

    novoElem->dado = inserir;
    novoElem->prox = NULL;

    Elem* aux = lista->inicio;
    for(int i = 1; i < indice - 1; i++)
        aux = aux->prox;

    novoElem->prox = aux->prox;
    aux->prox = novoElem;

    lista->qtdElem++;
}

void lista_exibir(Lista* lista) {
    if(lista->qtdElem == 0) {
        printf("Lista vazia\n");
    } else {
        Elem* aux = lista->inicio;
        int i = 0;

        for(int i = 0; i < lista->qtdElem; i++) {
            printf("%.1f", aux->dado);
            aux = aux->prox;
            if(i != lista->qtdElem - 1)
                printf(" ");
            i++;
        } printf("\n");
    }
}

void lista_exibir_qtd(Lista* lista) {printf("%d\n", lista->qtdElem);}

void lista_exibir_inicio(Lista* lista) {printf("%.1f\n", lista->inicio->dado);}

void lista_exibir_fim(Lista* lista) {
    Elem* aux = lista->inicio;
    while(aux->prox != lista->inicio)
        aux = aux->prox;

        printf("%.1f\n", aux->dado);
}

void lista_exibir_maior(Lista* lista) {
    if(lista->qtdElem == 0) {
        printf("Lista vazia\n");
    } else {
        Elem* aux = lista->inicio;
        float maior = 0.0;

        while(aux->prox != NULL) {
            if(aux->dado > maior)
                maior = aux->dado;
            aux = aux->prox;
        }
        printf("%.1f\n", maior);
    }
}

void lista_exibir_qtdMaiorQue(Lista* lista, float comparador) {
    if(lista->qtdElem == 0) {
        printf("Lista vazia\n");
    } else {

        Elem* aux = lista->inicio;
        int contadorMaior = 0;

        for(int i = 0; i < lista->qtdElem; i++) {
            if(aux->dado > comparador)
                contadorMaior++;
            aux = aux->prox;
        }

        printf("%d\n", contadorMaior);
    }
}

int lista_remover_inicio(Lista* lista) {
    if(lista == NULL) {
        printf("Erro, lista nao definida\n");
        return 0;
    }

    if(lista->qtdElem == 0) {
        return 0;
    }

    Elem* aux = NULL;
    
    if(lista->qtdElem == 1) {
        free(lista->inicio);
        lista->fim = NULL;
    } else {
        aux = lista->inicio;
        lista->inicio = aux->prox;
        
        if(lista->circular == V)
            lista->fim->prox = lista->inicio;
        
        free(aux);
    }

    lista->qtdElem--;

    return 1;
}

int lista_remover_ocorrencias(Lista* lista, float remover) {
    if(lista == NULL) {
        printf("Erro, lista nao definida\n");
        return 0;
    }

    if(lista->qtdElem == 0) {
        return 0;
    }

    Elem* anterior = NULL;
    Elem* atual = NULL;

    for(int i = 0; i < lista->qtdElem; i++) {
        if(remover == lista->inicio->dado) {
            lista_remover_inicio(lista);
            if(lista->qtdElem == 1)
                return 1;

        } else {
            anterior = lista->inicio;
            atual = lista->inicio->prox;

            while ((atual != NULL) && (atual != lista->inicio)){
                if (atual->dado == remover) {
                    anterior->prox = atual->prox;
                    free(atual);

                    lista->qtdElem--;

                    atual = anterior->prox;
                    
                    if ((atual == NULL) || (atual == lista->inicio))
                        lista->fim = anterior;
                } else {
                    anterior = atual;
                    atual = atual->prox;
                }
            }
        }
    }

    return 1;
}

int lista_esvaziar(Lista* lista) {
    if(lista == NULL) {
        printf("Erro, lista nao definida\n");
        return 0;
    }

    while(1) {
        if(lista->qtdElem == 0) {
            return 1;
            break;
        }

        lista_remover_inicio(lista);
    }
}
