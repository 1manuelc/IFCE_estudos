/*

O professor Miguel desafiou os estudantes do 1º semestre de Computação com uma brincadeira. No pátio, os alunos formam um quadrado com n fileiras e n colunas. Cada um dos n2 alunos segura uma bandeira. O professor faz um sorteio de uma fileira e uma coluna e entrega uma bolinha para o aluno da fileira e coluna sorteados. O professor sorteia uma nova fileira e coluna. A bolinha deve ser passada até chegar no aluno da fileira e coluna sorteados. Quando a bolinha é posicionada em cada aluno, é necessário seguir o mesmo comportamento: • Recebe a bolinha, levanta sua bandeira e entrega ao professor Miguel. • Vira-se para seu colega e entrega a bolinha (a bolinha deve seguir o menor caminho possível). Escreva um programa em C que, dados: fileira inicial, coluna inicial, fileira final e coluna final, informe quantas bandeiras o professor Miguel receberá.

*/

#include <stdio.h>

int main()
{
    int colunaInicial, linhaInicial, colunaFinal, linhaFinal, diferencaLC;

    scanf("%d", &colunaInicial);
    scanf("%d", &linhaInicial);
    scanf("%d", &colunaFinal);
    scanf("%d", &linhaFinal);

    diferencaLC = colunaFinal - colunaInicial + linhaFinal - linhaInicial + 1;

    printf("%d", diferencaLC);
    return 0;
}