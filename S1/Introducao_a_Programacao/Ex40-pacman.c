/*

Pacman é um jogo onde o personagem tenta comer a maior quantidade possível de bolinhas, tendo ao mesmo tempo que fugir de fantasmas. O encontro com um fantasma faz com que todas as bolinhas coletadas sejam perdidas. Considere que: (i) Os fantasmas não se movem; (ii) O Pacman coleta as bolinhas percorrendo cada linha da esquerda para a direita; (iii) Ao encontrar um fantasma, o Pacman perde todas as bolinhas coletadas; (iv) O jogo termina quando o Pacman chega ao final da última linha. Escreva um programa que determine a quantidade de bolinhas que o Pacman terá ao final. (4 pts)

Entrada
A primeira linha contém um inteiro N que corresponde a quantidade de itens. A linha seguinte contém N números inteiros (0 significa bolinha, 1 significa espaço vazio e 2 significa fantasma).

Saída
A quantidade de bolinhas que o Pacman levará para casa.

*/

#include <stdio.h>

int main()
{
    int caminho, bolinhasContador = 0, caminhoAtual = 0;
    scanf("%d", &caminho);

    for(int i = 0; i < caminho; i++) {
        scanf("%d", &caminhoAtual);

        if(caminhoAtual == 0)
            bolinhasContador += 1;
        else {
            if(caminhoAtual == 1)
                continue;
            else {
                if(caminhoAtual == 2)
                    bolinhasContador = 0;
            }
        }
    }

    printf("%d", bolinhasContador);

    return 0;
}