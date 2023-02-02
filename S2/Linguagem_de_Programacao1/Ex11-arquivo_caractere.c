#include <stdio.h>
#include <stdlib.h>

void main() {
    FILE *arquivo;
    char letraAtual, caract;
    int qtdeCaract = 0;

    arquivo = fopen("arquivo.txt", "w+");

    if(arquivo) {
        printf("Digite um texto e para salvar digite enter: ");
        scanf("%c", &letraAtual);
        while(letraAtual != '\n') {
            fputc(letraAtual, arquivo);
            scanf("%c", &letraAtual);
        }

    } else
        printf("Erro ao abrir arquivo");

    printf("Digite o caractere: ");
    scanf("%c", &caract);

    rewind(arquivo);

    while(!feof(arquivo)) {
        letraAtual = fgetc(arquivo);
        if(letraAtual == caract)
            qtdeCaract++;
        else
            continue;
    }

    printf("Quantidade de vogais: %d\n", qtdeCaract);

    system("pause");
}