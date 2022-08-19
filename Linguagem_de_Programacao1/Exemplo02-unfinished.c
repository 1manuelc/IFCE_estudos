#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numeroDecimal, numeroOctal;
    printf("Digite um numero em base decimal: ");
    scanf("%i", &numeroDecimal);

    do
    { numeroOctal += numeroDecimal % 8;
    } while (numeroDecimal % 8 != 1);
    
    printf("%d", numeroOctal);

    system("pause");
    return 0;
}