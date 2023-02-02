#include <stdio.h>

int main() {
    int bandejas, qtdeLatas, qtdeCopos, coposQuebrados = 0;
    scanf("%d", &bandejas);
    
    for(int i = 0; i < bandejas; i++) {
        scanf("%d%d", &qtdeLatas, &qtdeCopos);
        
        if(qtdeLatas > qtdeCopos) {
            coposQuebrados += qtdeCopos;
        }
    }
    
    printf("%d", coposQuebrados);
    
    return 0;
}
