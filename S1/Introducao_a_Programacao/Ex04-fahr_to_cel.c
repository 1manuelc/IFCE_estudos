/* Escreva um algoritmo para dada uma temperatura em graus Fahrenheit, calcular e escrever o valor em graus Celsius (baseado na fórmula abaixo): C/5=(F-32)/9 
*/

#include<stdio.h>

int main()
{
    float tempFah, tempCel;
    scanf("%f", &tempFah);
    
    tempCel = (tempFah - 32) / 9 * 5;
    printf("%.2f", tempCel);
    
    return 0;
}