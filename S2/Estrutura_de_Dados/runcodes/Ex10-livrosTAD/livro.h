#ifndef __livro_h
#define __livro_h

typedef struct Livro Livro;

Livro *alocar_livros(int qtLivros);
Livro *povoar_livros(Livro *pLivros, int qtLivros);
void exibir_livros(Livro *pLivros, int qtLivros);
void desalocar_livros(Livro *pLivros);
void flush_in();

#endif