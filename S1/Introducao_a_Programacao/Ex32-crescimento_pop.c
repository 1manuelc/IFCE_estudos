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
