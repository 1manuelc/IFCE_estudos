#include <stdio.h>
#include <stdlib.h>

int main() {
    float *vetor;
    int opcao = 0, i = 0;

    scanf("%d", &opcao);
    while(opcao != 0) {
        if(opcao == 1) {
            // inserir uma posicao no ponteiro vetor
            if(i == 0)
                vetor = (float*)malloc((i + 1) * sizeof(float));
            else
                vetor = realloc(vetor, i + 1);
            
            scanf("%f", &vetor[i]);
            i++;
        } else if(opcao == 2) {
            vetor = (float*)realloc(vetor, i - 1);
            i--;
        }
        scanf("%d", &opcao);
    }

    printf("{");
    for(int j = 0; j < i; j++) {
        if(j == i - 1)
            printf("%.1f", vetor[j]);
        else
            printf("%.1f, ", vetor[j]);
    }
    printf("}\n");

    return 0;
}