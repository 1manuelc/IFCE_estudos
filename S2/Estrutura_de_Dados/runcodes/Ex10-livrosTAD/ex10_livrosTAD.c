#include <stdio.h>
#include <stdlib.h>
#include "livro.h"

int main() {
    Livro *pLivros; 
    int qtLivros;
    scanf("%d", &qtLivros);

    if(qtLivros <= 0)
        printf("[Nenhum registro lido]");
    else {
        pLivros = alocar_livros(qtLivros);
        pLivros = povoar_livros(pLivros, qtLivros);
        exibir_livros(pLivros, qtLivros);
        desalocar_livros(pLivros);
    }
    
    return 0;
}