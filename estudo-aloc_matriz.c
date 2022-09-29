#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    /*int *x, i;
    x = (int*)malloc(sizeof(int) * 2);
    x = (int*)calloc(2, sizeof(int));
    x = (int*)realloc(x, 2);
    free(x[i]);  //--->    **x;
    free(x);     //--->    *x;

    *(x + i); //<-> x[i]
    if(x);    //<-> if(x != NULL)
    */

    int **vet, lin, col;
    printf("Linhas: ");
    scanf("%d", &lin);

    printf("Colunas: ");
    scanf("%d", &col);

    vet = malloc(lin * sizeof(int*));
    printf("\nLinhas alocadas!\n");

    for(int i = 0; i < lin; i++) {
        vet[i] = malloc(col * sizeof(int));
        printf("Coluna %d alocada!\n", i);
    }
    
    printf("\n");
    srand(time(NULL));

    for(int i = 0; i < lin; i++)
        for(int j = 0; j < col; j++)
            vet[i][j] = rand() % 100;

    for(int i = 0; i < lin; i++) {
        for(int j = 0; j < col; j++)
            printf("%d\t", vet[i][j]);
        printf("\n");
    }

    for(int i = 0; i < lin; i++)
        free(vet[i]);
    free(vet);
    printf("\nPonteiro de ponteiro liberado!\n\n");

    system("pause");
    return 0;
}