/* Faça um programa em C que leia o nome do estudante, o número de matrícula, a nota das etapas N1 e N2, a média e o percentual de frequência. Antes da leitura de cada valor informe, respectivamente, Nome: Matricula: N1: N2: Media: Frequencia:

Exiba a seguinte mensagem:

Nome: Joaquim

Matricula: 123

N1: 10.0

N2: 9.0

Media: 9.5

Frequencia: 95.0

Neste exercício, considere que Joaquim, 123 e 10.0, 9.0, 9.5 e 95.0 são os valores informados pelo usuário. Na exibição dos textos, não utilize acentuação. Exiba os números fracionários com uma casa decimal. */


#include <stdio.h>

int main()
{
    
    char nome[21];
    int matricula;
    float n1, n2, med, freq;
    
    printf("Nome:");
    scanf("%s", nome);
    
    printf("Matricula:");
    scanf("%d", &matricula);
    
    printf("N1:");
    scanf("%f", &n1);
    
    printf("N2:");
    scanf("%f", &n2);
    
    printf("Media:");
    scanf("%f", &med);
    
    printf("Frequencia:");
    scanf("%f", &freq);
    
    printf("Nome: %s\n", nome);
    printf("Matricula: %d\n", matricula);
    printf("N1: %.1f\n", n1);
    printf("N2: %.1f\n", n2);
    printf("Media: %.1f\n", med);
    printf("Frequencia: %.1f\n", freq);
    
    return 0;
}