#include <stdio.h>
#include <stdlib.h>
#include "livro.h"
#include <locale.h>

typedef struct Livro{
    char nome[100], editora[21], isbn[10];
    float preco, nota;
}Livro;

Livro *alocar_livros(int qtLivros) {    
    Livro *pLivros;
    if(qtLivros > 0) {
        pLivros = (Livro*)malloc(qtLivros * sizeof(Livro));
        return pLivros;
    }
    return NULL;
}

Livro *povoar_livros(Livro *pLivros, int qtLivros) {
    for(int i = 0; i < qtLivros; i++) {
        flush_in();
        scanf("%[^\n]", pLivros[i].nome);
        flush_in();
        scanf("%[^\n]", pLivros[i].isbn);
        flush_in();
        scanf("%f", &pLivros[i].preco);
        scanf("%f", &pLivros[i].nota);
		flush_in();
        scanf("%[^\n]", pLivros[i].editora);
    } return pLivros;
}

void exibir_livros(Livro *pLivros, int qtLivros) {
    setlocale(LC_ALL, "Portuguese");
    for(int i = 0; i < qtLivros; i++) {
        printf("[Registro %d]\n", i + 1);
        printf("Nome: %s\n", pLivros[i].nome);
        printf("ISBN: %.10s\n", pLivros[i].isbn);
        printf("Preço: R$ %.2f\n", pLivros[i].preco);
        printf("Avaliação: %.1f\n", pLivros[i].nota);
        printf("Editora: %s\n", pLivros[i].editora);
    }
}

void desalocar_livros(Livro *pLivro) {
    free(pLivro);
}

void flush_in() {
    char ch;
    while( (ch = fgetc(stdin)) != EOF && ch != '\n' ){}
}