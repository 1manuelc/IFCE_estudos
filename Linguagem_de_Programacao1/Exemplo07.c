/*

Crie um um arquivo texto de chamado "exercicio.txt", em seguida permita
que o usuário entre com vários caracteres nesse arquivo e só pare quando o
usuário digitar caractere ’0’. Feche o arquivo e abra novamente, e lendo-o
caractere por caractere, escreva na tela todos os caracteres armazenados.

*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    char letra;
    
    file = fopen("exercicio.txt", "w+");

    if(file) {
        printf("Digite um texto e para salvar digite 0: ");
        scanf("%c", &letra);
        while(letra != 48) {
            fputc(letra, file);
            scanf("%c", &letra);
        }
    } else {
        printf("Erro ao abrir arquivo!");
    }

    rewind(file);

    printf("\nTexto lido do arquivo: ");
    while(!feof(file)) {
        letra = fgetc(file);
        printf("%c", letra);
    }

    fclose(file);
    
    system("pause");
    return 0;
}