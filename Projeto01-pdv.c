#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>

#define ANSI_VERMELHO   "\x1b[31m"
#define ANSI_CIANO  "\x1b[36m"
#define ANSI_VERDE  "\e[0;32m"
#define ANSI_RESET  "\x1b[0m"

typedef struct {
    int dia;
    int mes;
    int ano;
}Valid;

typedef struct {
    char nome_produto[12];
    float valor;
    float quantidade;
    int codigo;
    char undMed[10];
    Valid validade;
}Produto;

void pdv_cabecalho();
void pdv_cadastrar(FILE *arquivo, int *pContador, Produto *pProdutos);
void pdv_remover();
void pdv_alterar();
void pdv_exibir_produtos(Produto *pProdutos, int *pContador);
void pdv_buscar();
Produto *pdv_atualizar(FILE *arquivo, int *pContador, Produto *pProdutos);
void pdv_sair(Produto *pProdutos, int *pContador);
void pdv_erro();

int main() {
    setlocale(LC_ALL,"Portuguese");
    FILE *arquivo;
    Produto *pProdutos;
    int *pContador, contador = 0;
    pContador = &contador;

    int digito = 0;
    do {
        printf("     %d produtos armazenados\n", *pContador);
        pdv_cabecalho();
        scanf("%d", &digito);
        switch(digito) {
            case 1: /* cadastrar */ {
                pdv_cadastrar(arquivo, pContador, pProdutos);
                break;
            }
            case 2: /* remover */ {
                break;
            }
            case 3: /* modificar */ {
                break;
            }
            case 4: /* exibir */ {
                pdv_exibir_produtos(pProdutos, pContador);
                system("pause");
                system("cls");
                break;
            }
            case 5: /* buscar */ {
                break;
            }
            case 6: /* atualizar */ {
                pProdutos = pdv_atualizar(arquivo, pContador, pProdutos);
                break;
            }
            case 7: /*sair*/ {
                pdv_sair(pProdutos, pContador);
                break;
            }
            default: /* erro */ {
                pdv_erro();
                break;
            }
        }
    } while(digito != 7);
    
    return 0;
}

void pdv_cabecalho() {
    printf("- - - - - - - - - - - - - - - -\n");
    printf("- - - - - SISTEMA PDV - - - - -\n");
    printf("- - - - - - - - - - - - - - - -\n\n");
    
    printf("Digite:\n");
    printf("(1) - Para cadastrar um produto\n");
    printf("(2) - Para remover um produto\n");
    printf("(3) - Para alterar um produto\n");
    printf("(4) - Para exibir os produtos cadastrados\n");
    printf("(5) - Para buscar um produto\n");
    printf("(6) - Para atualizar a base de dados\n");
    printf("(7) - Para sair do programa\n\n");
}

void pdv_cadastrar(FILE *arquivo, int *pContador, Produto *pProdutos) {
    system("cls");
    printf(ANSI_CIANO " [ CADASTRO DE PRODUTO ] \n" ANSI_RESET);
    
    Produto pdv;
    arquivo = fopen("log-pdv.txt", "a+");

    if(arquivo == NULL) {
    printf("Erro ao ler arquivo!");
    } else {
    do {
        setbuf(stdin, NULL);
        printf("\nDigite o nome do produto: ");
        scanf("%12[^\n]", pdv.nome_produto);
        fprintf(arquivo, "Nome: %s\t", &pdv.nome_produto);

        setbuf(stdin, NULL);
        printf("Digite a quantidade do produto: ");
        scanf("%f", &pdv.quantidade);
        fprintf(arquivo, "Qtd: %.0f\t", pdv.quantidade);

        setbuf(stdin, NULL);
        printf("Digite a unidade de medida do produto: ");
        scanf("%[^\n]", &pdv.undMed);

        setbuf(stdin, NULL);
        printf("Digite o preco do produto: ");
        scanf("%f", &pdv.valor);
        fprintf(arquivo, "Valor/%s R$ %.2f\t", pdv.undMed, pdv.valor);

        setbuf(stdin, NULL);
        printf("Digite a validade do produto(dd mm aaaa): ");
        scanf("%d %d %d", &pdv.validade.dia, &pdv.validade.mes, &pdv.validade.ano);
        fprintf(arquivo, "%d/%d/%d\t", pdv.validade.dia, pdv.validade.mes, pdv.validade.ano);

        setbuf(stdin, NULL);
        printf("Digite o codigo do produto: ");
        scanf("%d", &pdv.codigo);
        fprintf(arquivo, "%d", pdv.codigo);
        
        fprintf(arquivo, "\n");        

        printf(ANSI_VERDE "\n\nProduto cadastrado com sucesso\nDeseja cadastrar outro produto? (s/n): " ANSI_RESET);

        } while(getch() == 's');
        system("cls");        
    } fclose(arquivo);
}

void pdv_exibir_produtos(Produto *pProdutos, int *pContador) {
    Produto pdv;
    FILE *arquivo;
    arquivo = fopen("log-pdv.txt", "r");
    fclose(arquivo);
}

Produto *pdv_atualizar(FILE *arquivo, int *pContador, Produto *pProdutos) {
    system("cls");
    arquivo = fopen("log-pdv.txt", "r");
        char ch;
        int contador = 0;
        if(arquivo) {
            while(!feof(arquivo)) {
                ch = fgetc(arquivo);
                if(ch == '\n')
                    contador++;
            }
        } 
        *pContador = contador;
    fclose(arquivo);
    printf(ANSI_VERDE "  [ BASE DE DADOS ATUALIZADA ] \n" ANSI_RESET);
    return pProdutos;
}

void pdv_sair(Produto *pProdutos, int *pContador) {
    free(pProdutos);
    free(pContador);
    system("cls");
    printf(ANSI_CIANO "\nObrigado por usar nosso programa\nAte a proxima!\n\n" ANSI_RESET);
    system("pause");
}

void pdv_erro() {
    system("cls");
    printf(ANSI_VERMELHO "       [ OPCAO INVALIDA ]       \n" ANSI_RESET);
}