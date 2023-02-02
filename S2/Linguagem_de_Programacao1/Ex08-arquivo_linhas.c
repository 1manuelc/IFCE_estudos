#include <stdio.h>
#include <stdlib.h>

void main() {
    FILE *arquivo;
    char letraAtual;
    int qtdeLinhas = 1;

    arquivo = fopen("arquivo.txt", "w+");

    if(arquivo) {
        printf("Digite um texto e para salvar digite enter: ");
        scanf("%c", &letraAtual);
        while(letraAtual != 48) {
            fputc(letraAtual, arquivo);
            scanf("%c", &letraAtual);
            if(letraAtual == '\n')
                qtdeLinhas++;
        }
    } else
        printf("Erro ao abrir arquivo!");
    
    fclose(arquivo);

    printf("Quantidade de linhas: %d\n", qtdeLinhas);

    system("pause");
}