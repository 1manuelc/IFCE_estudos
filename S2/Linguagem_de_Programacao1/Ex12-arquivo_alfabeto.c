#include <stdio.h>
#include <stdlib.h>

void main() {
    FILE *arquivo;
    char letraAtual, variavelArquivo;
    char alfabeto[26] = {"abcdefghijklmnopqrstuvwxyz"};
    char alfabetoCap[26] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    int qtdeAlfabeto[26] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

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

    rewind(arquivo);

    while(!feof(arquivo)) {
        letraAtual = fgetc(arquivo);
        for(int i = 0; i < 26; i++) {
            if(letraAtual == alfabeto[i] || letraAtual == alfabetoCap[i])
                qtdeAlfabeto[i]++;
        }
    }

    printf("\n");
    for(int i = 0; i < 26; i++) {
        printf("Quantidade de letras %.1s = %d\n", &alfabetoCap[i], qtdeAlfabeto[i]);
    }
    system("pause");
}