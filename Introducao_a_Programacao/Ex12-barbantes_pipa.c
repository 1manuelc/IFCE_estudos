/*

Guilherme adora brincar com pipas, pipas de várias cores, formas e tamanhos. Ele tem percebido que para as pipas possuírem maior estabilidade, e dessa forma voarem mais alto, elas devem possuir um barbante bem esticado ligando todos os pares de pontas não vizinhas. Apesar de ser uma criança bastante criativa e astuta, Guilherme não sabe como determinar a quantidade de barbantes que ele terá que utilizar para tornar uma pipa de n lados, estável. Você pode ajudá-lo?

Entrada
A entrada será composta por uma única linha, que contém um inteiro 3 ≤ n ≤ 10 , representando o número de lados da pipa.

Saída
Imprima um número inteiro, que será a quantidade de barbantes que Guilherme terá que utilizar para tornar a pipa de n lados estável.

Exemplo de Entrada	Exemplo de Saída
4	                2
6	                9
10	                35
11	                44

*/

#include<stdio.h>

int main()
{
    int nLados, nDiagonais;
    scanf("%d", &nLados);
    
    nDiagonais = ((nLados - 3) * nLados) / 2;
    printf("%d", nDiagonais);
    
    return 0;
}