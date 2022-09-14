/*

Escreva um algoritmo que lê o peso (em kg) e a altura (em m) de uma pessoa e que mostre o IMC e a categoria do IMC equivalente. O cálculo do IMC se dá pela seguinte fórmula: IMC= peso/altura^2. De acordo com o valor obtido, a pessoa encontra-se em uma das seguintes categorias:

Faixa de IMC	    Categoria
IMC < 18,5	        Abaixo do Peso
18,5 <= IMC < 25	Peso Normal
25 <= IMC < 30	    Acima do Peso
IMC >= 30	        Obesidade

Entrada
Dois valores fracionários, correspondendo ao peso e a altura.

Saída
O IMC (com duas casas decimais) e a categoria.

*/

#include <stdio.h>
#include <stdlib.h>

void main() {
    float peso, altura, imc;
    scanf("%f%f", &peso, &altura);

    imc = peso / (altura * altura);

    if(imc < 18.5)
        printf("IMC = %.2f Abaixo do Peso", imc);
    else if(imc >= 18.5 && imc < 25)
        printf("IMC = %.2f Peso Normal", imc);
    else if(imc >= 25 && imc < 30)
        printf("IMC = %.2f Acima do Peso", imc);
    else if(imc >= 30)
        printf("IMC = %.2f Obesidade", imc);
    system("pause");
}