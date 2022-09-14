/*

Você foi convidado para desenvolver parte do módulo de autenticação de um sistema, que consiste em verificar se a senha informada pelo usuário é válida. A princípio, a senha válida é 123456. Portanto, faça um programa que solicite do usuário a senha e informe se a senha é válida ou não. A saída deve ser S para senha válida e N para senha inválida.

*/

#include <stdio.h>
#include <stdlib.h>

void main() {
    int senha;
    scanf("%d", &senha);

    if(senha == 123456)
        printf("S");
    else
        printf("N");
    system("pause");
}