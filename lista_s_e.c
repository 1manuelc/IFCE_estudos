#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define V 1
#define F 0

typedef struct elem Elem;
typedef struct lista Lista;

struct elem {
    int dado;
    Elem* prox;
};

struct lista {
    Elem* inicio;
    Elem* fim;
    int qtdElem;
    int circular;
};

Lista* lista_criar();
int lista_inserir_inicio(Lista* lista, int inserir);
int lista_inserir_fim(Lista* lista, int inserir);
int lista_inserir_indice(Lista* lista, int inserir, int indice);
int lista_exibir(Lista* lista);
int lista_exibir_maior(Lista* lista);
int lista_exibir_qtdMaiorQue(Lista* lista, int comparador);
int lista_remover_inicio(Lista* lista);
int lista_remover_ocorrencias(Lista* lista, int remover);
int lista_esvaziar(Lista* lista);

int main() {
    Lista *lista = lista_criar();
    int dado = 0, indice = 0;
    char opcao[4];
    while(1) {
        scanf("%s%*c", opcao);

        if(strcmp("-s", opcao) == 0) {
            lista_exibir(lista);
            break;
        } else if(strcmp("-a", opcao) == 0) {
            scanf("%d", &dado);
            getchar();
            if((dado == 42) || (dado == 1) || (dado == 45) || (dado == 47)) {
                scanf("%d", &indice);
                lista_inserir_indice(lista, dado, indice);
            } else {
                lista_inserir_inicio(lista, dado);
            }
        } else if(strcmp("-sl", opcao) == 0)
            printf("%d\n", lista->fim->dado);

        else if(strcmp("-sf", opcao) == 0)
            printf("%d\n", lista->inicio->dado);

        else if(strcmp("-ss", opcao) == 0)
            printf("%d\n", lista->qtdElem);

        else if(strcmp("-m", opcao) == 0)
            printf("%d\n", lista_exibir_maior(lista));
        
        else if(strcmp("-sg", opcao) == 0) {
            scanf("%d", &dado);
            getchar();
            printf("%d", lista_exibir_qtdMaiorQue(lista, dado));
        } else if(strcmp("-r", opcao) == 0) {
            scanf("%d", &dado);
            getchar();
            lista_remover_ocorrencias(lista, dado);
        } else if(strcmp("-c", opcao) == 0)
            lista_esvaziar(lista);
    }

    system("pause");
    return 0;
}

Lista* lista_criar() {
    Lista* novaLista = (Lista*)malloc(sizeof(Lista));
    
    if(novaLista == NULL) {
        printf("Erro ao criar a lista\n");
        return NULL;
    }

    novaLista->qtdElem = 0;
    novaLista->circular = F;
    novaLista->inicio = NULL;
    novaLista->fim = NULL;

    return novaLista;
}

int lista_inserir_inicio(Lista* lista, int inserir) {
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
        lista->inicio = novoElem;
    }

    if(lista->circular == V)
        lista->fim->prox = lista->inicio;
    
    lista->qtdElem++;

    return 1;
}

int lista_inserir_fim(Lista* lista, int inserir) {
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

int lista_inserir_indice(Lista* lista, int inserir, int indice) {
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

    if(indice == lista->qtdElem + 1) {
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

int lista_exibir(Lista* lista) {
    if(lista == NULL) {
        printf("Erro, lista nao definida\n");
        return 0;
    }

    if(lista->qtdElem == 0) {
        printf("Lista vazia\n");
        return 1;
    }

    Elem* aux = lista->inicio;

    for(int i = 0; i < lista->qtdElem; i++) {
        printf("%d", aux->dado);
        aux = aux->prox;
        if(i != lista->qtdElem - 1)
            printf(" ");
    } printf("\n");

    return 1;
}

int lista_exibir_maior(Lista* lista) {
    if(lista == NULL) {
        printf("Erro, lista nao definida\n");
        return 0;
    }

    if(lista->qtdElem == 0) {
        printf("Lista vazia\n");
        return 1;
    }

    Elem* aux = lista->inicio;
    int maior;

    for(int i = 0; i < lista->qtdElem; i++) {
        if(aux->dado > maior)
            maior = aux->dado;
        aux = aux->prox;
    }

    return maior;
}

int lista_exibir_qtdMaiorQue(Lista* lista, int comparador) {
    if(lista == NULL) {
        printf("Erro, lista nao definida\n");
        return 0;
    }

    if(lista->qtdElem == 0) {
        printf("Lista vazia\n");
        return 1;
    }

    Elem* aux = lista->inicio;
    int contadorMaior = 0;

    for(int i = 0; i < lista->qtdElem; i++) {
        if(aux->dado > comparador)
            contadorMaior++;
        aux = aux->prox;
    }

    return contadorMaior;
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

int lista_remover_ocorrencias(Lista* lista, int remover) {
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
