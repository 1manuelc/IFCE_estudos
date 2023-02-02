/*
A turma do primeiro semestre do Curso Técnico em Informática fará uma votação para escolher o líder da sala. Para auxiliar na apuração da votação, faça um algoritmo que receba o nome dos dois estudantes candidatos a líder e a quantidade de votos que cada um recebeu. Após isso, seu algoritmo deverá exibir o nome do estudante vencedor, o percentual de votos que ele recebeu, assim como o nome do estudante que ficou em segundo lugar e o percentual de votos que ele recebeu (nessa ordem).

Entrada
O nome dos dois estudantes candidatos a líder e a quantidade de votos que cada um recebeu.

Saída
O nome do estudante vencedor, o percentual de votos que ele recebeu, assim como o nome do estudante que ficou em segundo lugar e o percentual de votos que ele recebeu (nessa ordem). Exiba a mensagem “Empate”, caso não haja ganhador.

Exemplo de entrada	     Exemplo de saída
Joao Maria 10 10	     Empate
Joao Maria 15 20	     Maria 57.14 Joao 42.86
Joao Maria 20 15	     Joao 57.14 Maria 42.86
*/

#include <stdio.h>

int main() {
     char aluno1[21], aluno2[21];
     float qtdevotos1, qtdevotos2, soma;
     float porcentagem1, porcentagem2;
     
     scanf("%s", aluno1);
     scanf("%s", aluno2);
     
     scanf("%f", &qtdevotos1);
     scanf("%f", &qtdevotos2);
     
     soma = qtdevotos1 + qtdevotos2;
     
     porcentagem1 = qtdevotos1 / soma * 100;
     porcentagem2 = qtdevotos2 / soma * 100;
     
     if(porcentagem1 > porcentagem2) {
          printf("%s %.2f ", aluno1, porcentagem1);
          printf("%s %.2f", aluno2, porcentagem2);
     }
     
     if(porcentagem2 > porcentagem1) {
          printf("%s %.2f ", aluno2, porcentagem2);
          printf("%s %.2f", aluno1, porcentagem1);
     }
     
     if(porcentagem1 == porcentagem2)
          printf("Empate");
     
     return 0;
}
