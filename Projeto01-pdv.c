#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>

typedef struct {
    int dia;
    int mes;
    int ano;
}Valid;

typedef struct {
    char nome_produto[40];
    float valor;
    float quantidade;
    int codigo;
    char undMed[10];
    Valid validade;
}produto_cadastro;

void inArquivo() {
    FILE *arquivo;

    produto_cadastro pdv;

    arquivo = fopen("sistema-pdv.txt", "a+");
    char continuar[10];

    if(arquivo == NULL) {
    printf("Erro!");
    } else {
    do {
        setbuf(stdin, NULL);
        printf("\nDigite o nome do produto: ");
        scanf("%s", &pdv.nome_produto);
        fprintf(arquivo, "Nome do produto: %s\t", pdv.nome_produto);

        setbuf(stdin, NULL);
        printf("Digite a unidade de medida do produto: ");
        scanf("%s", &pdv.undMed);

        setbuf(stdin, NULL);
        printf("Digite o valor do produto: ");
        scanf("%f", &pdv.valor);
        fprintf(arquivo, "Valor/%s: R$ %.2f\t", pdv.undMed, pdv.valor);

        setbuf(stdin, NULL);
        printf("Digite a quantidade do produto: ");
        scanf("%f", &pdv.quantidade);
        fprintf(arquivo, "Quantidade: %.0f\t", pdv.quantidade);

        setbuf(stdin, NULL);
        printf("Digite a validade do produto(dd mm aaaa): ");
        scanf("%d %d %d", &pdv.validade.dia, &pdv.validade.mes, &pdv.validade.ano);
        fprintf(arquivo, "Validade: %d/%d/%d\t", pdv.validade.dia, pdv.validade.mes, pdv.validade.ano);

        setbuf(stdin, NULL);
        printf("Digite o codigo do produto: ");
        scanf("%d", &pdv.codigo);
        fprintf(arquivo, "Codigo: %d\t", pdv.codigo);

        fprintf(arquivo, "\n");

        printf("Deseja cadastrar mais um produto? (s/n): ");

        } while(getch() == 's');
        printf("\n");
        
    } fclose(arquivo);
}

void head()
{
    printf("- - - - - - - - - - - - - - - -\n");
    printf("- - - - - SISTEMA PDV - - - - -\n");
    printf("- - - - - - - - - - - - - - - -\n\n");

    printf("(1) - Para cadastrar um produto\n");
    printf("(2) - Para remover um produto\n");
    printf("(3) - Para sair do programa\n");
}

int main(void) {

setlocale(LC_ALL,"Portuguese");

    int digito;

    do {
        head();
        scanf("%d", &digito);
        switch(digito) {
            case 1:
                inArquivo();
                break;
            case 2:
                break;
            case 3:
                printf("Voce saiu do programa");
                break;
            default:
                printf("Opcao invalida\n");
                head();
                scanf("%d", &digito);
                break;
        }
    } while(digito != 3);

    system("pause");
    
    return 0;
}
