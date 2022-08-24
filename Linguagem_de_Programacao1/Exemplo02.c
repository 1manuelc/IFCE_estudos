#include <stdio.h>
#include <stdlib.h>

#define IMPRIMIR_OCTAL printf("Numero octal = "); for(int j = i; j >= 0; j--) { printf("%d", numeroOctal[j]); if(j == 0) { printf("\n");}}

int decimalOctal(int numeroDecimal, int *numeroOctal) {
    int i = 0;

    while (1) {
        if(numeroDecimal < 8) {
            numeroOctal[i] = numeroDecimal;
            break;
        }
        numeroOctal[i] = numeroDecimal % 8;
        numeroDecimal /= 8;
        i++;
    }
    
    return(i);
    
}

int decimalHexadecimal (int numeroDecimal, int *numeroHexadecimal) {
    int i = 0;
    while (1) {
        if(numeroDecimal < 16) {
            numeroHexadecimal[i] = numeroDecimal;
            break;
        }
        numeroHexadecimal[i] = numeroDecimal % 16;
        numeroDecimal /= 16;
        i++;
    }
    return(i);
}

int main() {
    int numeroDecimal = 0, numeroOctal[21], i = 0, numeroHexadecimal[21];
    printf("Digite um numero em base decimal: ");
    scanf("%i", &numeroDecimal);

    i = decimalOctal(numeroDecimal, numeroOctal);
    printf("Numero decimal = %d\n", numeroDecimal);
    IMPRIMIR_OCTAL;

    i = decimalHexadecimal(numeroDecimal, numeroHexadecimal);

    printf("Numero hexadecimal = ");
    for(int j = i; j >= 0; j--) {
        if (numeroHexadecimal[j] == 10)
            printf("A");
        else if (numeroHexadecimal[j] == 11)
            printf("B");
        else if (numeroHexadecimal[j] == 12)
            printf("C");
        else if (numeroHexadecimal[j] == 13)
            printf("D");
        else if (numeroHexadecimal[j] == 14)
            printf("E");
        else if (numeroHexadecimal[j] == 15)
            printf("F");
        else
            printf("%d", numeroHexadecimal[j]);
        if(j == 0)
        printf("\n");
    }      

    system("pause");
    return 0;
}