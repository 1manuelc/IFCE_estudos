/*

Faça um programa que solicite do usuário a quantidade de alunos e a nota de cada aluno. Em seguida, exiba o identificador dos alunos que possuem essa maior nota.

*/

#include <stdio.h>

int main() {
    int qtdeAlunos, maiorNota = 0;
    scanf("%d", &qtdeAlunos);
    
    int notas[qtdeAlunos];

    for(int i = 0; i < qtdeAlunos; i++) {
        scanf("%d", &notas[i]);
        
        if(notas[i] > notas[i - 1])
            maiorNota = notas[i];
    }
    
    for(int i = 0; i < qtdeAlunos; i++) {
        if(notas[i] == maiorNota) {
            printf("%d\n", i);
            continue;
        } else {
            if(i == qtdeAlunos - 1)
                printf("0");
        }
    }
    
    return 0;
}