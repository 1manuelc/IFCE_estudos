#include <stdio.h>
#include <stdlib.h>

void main() {
    FILE *arquivo;
    char letra;
    int vogais = 0, consoantes = 0;

    arquivo = fopen("arquivo.txt", "w+");

    if(arquivo) {
        printf("Digite um texto e para salvar digite enter: ");
        scanf("%c", &letra);
        while(letra != '\n') {
            fputc(letra, arquivo);
            scanf("%c", &letra);
        }

    } else
        printf("Erro ao abrir arquivo");

    rewind(arquivo);

    while(!feof(arquivo)) {
        letra = fgetc(arquivo);
        if(letra == 'a' || letra == 'e' || letra == 'i' || letra == 'o' || letra == 'u' || letra == 'A' || letra == 'E' || letra == 'I' || letra == 'O' || letra == 'U')
            vogais++;
        else if(letra == 32 || letra == '\n')
            continue;
        else
            consoantes++;
    }

    printf("Quantidade de vogais: %d\n", vogais);
    printf("Quantidade de consoantes: %d\n", consoantes - 1);

    system("pause");
}