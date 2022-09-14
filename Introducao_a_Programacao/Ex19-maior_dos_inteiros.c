/*
Bino recebeu de Cino três inteiros de presente e gostaria de saber qual dos três inteiros é o maior.

Entrada
A entrada consiste de três linhas. Cada linha contém um inteiro que Bino recebeu de presente.

Saída
A saída consiste de uma linha contendo o maior inteiro que Bino recebeu de presente.
*/

#include <stdio.h>
#include <stdlib.h>

void main() {
    int num, maiorNum, anteriorNum = 0;

    for(int i = 0; i < 3; i++) {
        scanf("%d", &num);
        if(num >= anteriorNum)
            maiorNum = num;
        anteriorNum = num;
    }

    printf("%d", maiorNum);
    system("pause");
}