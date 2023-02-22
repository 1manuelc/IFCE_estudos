/*

Crescimento Populacional

Mariazinha quer resolver um problema interessante. Dadas as informações de população e a taxa de crescimento de duas cidades quaisquer (A e B), ela gostaria de saber quantos anos levará para que a cidade menor (sempre é a cidade A) ultrapasse a cidade B em população. Claro que ela quer saber apenas para as cidades cuja taxa de crescimento da cidade A é maior do que a taxa de crescimento da cidade B, portanto, previamente já separou para você apenas os casos de teste que tem a taxa de crescimento maior para a cidade A. Sua tarefa é construir um programa que apresente o tempo em anos para cada caso de teste.

Porém, em alguns casos o tempo pode ser muito grande, e Mariazinha não se interessa em saber exatamente o tempo para estes casos. Basta que você informe, nesta situação, a mensagem "Mais de 1 seculo.".

Entrada
Quatro números: dois inteiros PA e PB indicando, respectivamente, a população de A e B, e dois valores G1 e G2, indicando, respectivamente, o crescimento populacional de A e B (em percentual).

Saída
Quantos anos levará para que a cidade A ultrapasse a cidade B em número de habitantes. Obs.: se o tempo for mais do que 100 anos o programa deve apresentar a mensagem: Mais de 1 seculo. Neste caso, interrompa o programa imediatamente após passar de 100 anos, caso contrário você poderá receber como resposta da submissão deste problema "Time Limit Exceeded".

*/

#include <stdio.h>

int main() {
    int pA, pB, contadorAnos = 0;
    float g1, g2;
    scanf("%d%d%f%f", &pA, &pB, &g1, &g2);
    g1 /= 100;
    g2 /= 100;
    
    do {
        pA += (g1 * pA);
        pB += (g2 * pB);
        contadorAnos += 1;
    }
    while(pB >= pA);
    
    if(contadorAnos > 100) {
        printf("Mais de 1 seculos");
    } else {
        printf("%d anos", contadorAnos);
    }
    
    return 0;
}
