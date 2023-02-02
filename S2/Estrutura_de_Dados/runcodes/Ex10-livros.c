/*

Defina um ponteiro para uma struct capaz de armazenar dados sobre um livro.
O registro contém os seguintes dados: nome, ISBN, preco, avaliacao e editora. Usando este registro faça:

1. Uma função que aloque o(s) livro(s) e devolva um ponteiro para o bloco de livro(s). Obs: a função deve receber a quantidade de livros a ser alocada;
2. Uma função que leia do teclado os dados do livro (receba o livro como parâmetro);
3. Uma função que mostre os dados do livro lido.
4. Uma função que desaloque os dados do livro lido.

Inicialmente, a primeira leitura deve informar quantos livros serão inseridos. Em seguida, a leitura de cada livro deve seguir a mesma ordem dos campos acima descritos.

Ao final, apresente os dados do livro seguindo o formato exemplificado abaixo:
    Nome: O Homem que Calculava
    ISBN: 8501061964
    Preço: R$ 34.90
    Avaliação: 4,9
    Editora: Record


*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct {
    char nome[100], editora[21], isbn[10];
    float preco, nota;
}Livro;

Livro *alocar_livros(int qtLivros);
Livro *povoar_livros(Livro *pLivros, int qtLivros);
void exibir_livros(Livro *pLivros, int qtLivros);
void desalocar_livros(Livro *pLivros);

void flush_in() {
    char ch;
    while( (ch = fgetc(stdin)) != EOF && ch != '\n' ){}
}

int main() {
    int qtLivros;
    scanf("%d", &qtLivros);

    if(qtLivros <= 0)
        printf("[Nenhum registro lido]");

    Livro *pLivros; 

    pLivros = alocar_livros(qtLivros);
    
    pLivros = povoar_livros(pLivros, qtLivros);

    exibir_livros(pLivros, qtLivros);
    desalocar_livros(pLivros);

    return 0;
}

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