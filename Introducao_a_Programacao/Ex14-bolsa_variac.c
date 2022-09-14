/*

Pedrinho é um menino visionário e inteligente, que quer ficar rico. Aos 12 anos de idade, está interessado em investimentos de ações na bolsa de valores. Uma ação é como se fosse um pedaço de uma empresa que qualquer pessoa pode comprar. Cada ação tem diferentes valores, e esses valores mudam o tempo todo. Por exemplo, Pedrinho compra uma ação de uma empresa de petróleo, que custa R$ 100. Suponha que no dia seguinte essa empresa descubra um poço de petróleo, o que vai dar muitos lucros. Essa empresa, então, passa a ser mais valorizada e o preço das ações sobem. Suponha que as ações subiram 20% nesse dia. Então, Pedrinho, que tinha uma ação de R$ 100, hoje tem a mesma ação, mas que vale R$ 120. Se no dia seguinte a ação tem uma queda de 10%, a ação de Pedrinho passa a ser R$ 108,00, ou seja, diminuiu R$ 12. Pedrinho pediu a sua ajuda para descobrir o valor da ação após 4 dias. Para isso, ele informa o valor inicial do investimento e a variação do preço das ações em 4 dias.

Exemplo de entrada	Exemplo de saída
100 10 -5 1 3	    108.71

*/

#include <stdio.h>

int main()
{
    float investimento, dia1, dia2, dia3, dia4;

    scanf("%f", &investimento);
    scanf("%f", &dia1);
    scanf("%f", &dia2);
    scanf("%f", &dia3);
    scanf("%f", &dia4);

    dia1 = investimento * dia1 / 100 + investimento;
    dia2 = dia1 * dia2 / 100 + dia1;
    dia3 = dia2 * dia3 / 100 + dia2;
    dia4 = dia3 * dia4 / 100 + dia3;

    printf("%.2f", dia4);

    return 0;
}