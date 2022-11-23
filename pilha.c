#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pilha TPilha, *PPilha;
typedef char TDado;

struct pilha {
    TDado dado;
    struct pilha *prox;
};

PPilha pilha_empilha(PPilha p, TDado inserir);
void pilha_exibe(PPilha p);
void pilha_esvazia(PPilha p);
void flush_in();

int main() {
    PPilha pilha = (PPilha)malloc(sizeof(TPilha));
    pilha = NULL;
    TDado inserir, removido;
    char entrada[10];

    if(pilha == NULL) {
        printf("Digite:\n");
        printf("-s para exibir a pilha\n");
        printf("-c para esvaziar a pilha\n");
        printf("-i char para empilhar um char\n");
        printf("-r para desempilhar o ultimo char\n");

        do{
            scanf("%[^\n]", entrada);
            flush_in();
        
            if(strcmp(entrada, "-s") == 0)
                pilha_exibe(pilha);
            //else if(strcmp(entrada, "-c") == 0)
            else if(strcmp(entrada, "-i") == 0) {
                scanf("%c", inserir);
                flush_in();

                pilha_empilha(pilha, inserir);
            } else if(strcmp(entrada, "-r") == 0)
                pilha_esvazia(pilha);
        }while((strcmp(entrada, "-s") != 0));
    } else {
        printf("Erro ao criar a pilha\n");
    }


    system("pause");
    return 0;
}

PPilha pilha_empilha(PPilha p, TDado inserir) {
    PPilha novo = (PPilha)malloc(sizeof(TPilha));
    if(novo) {
        printf("Entrou\n");
        novo->dado = inserir;
        novo->prox = p;
        return novo;
    } else {
        printf("Erro ao empilhar novo elemento\n");
        return NULL;
    }
}

void pilha_exibe(PPilha p) {
    PPilha exibe = (PPilha)malloc(sizeof(TPilha));
    exibe = p;

    if(exibe == NULL)
        printf("Pilha vazia\n");
    else {
        while(exibe->prox != NULL) {
            printf("%c", exibe->dado);
        exibe = exibe->prox;
        }
    }
}

void pilha_esvazia(PPilha p) {
    p = NULL;
}

void flush_in() {
    char ch;
    while((ch = fgetc(stdin)) != EOF && ch != '\n'){}
}