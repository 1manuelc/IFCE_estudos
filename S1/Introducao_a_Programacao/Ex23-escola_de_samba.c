/*
Carnaval é um feriado normalmente comemorado em fevereiro. Em muitas cidades brasileiras, a principal atração são os desfiles das escolas de samba. As várias associações vão ao som dos seus sambas-enredos e são julgadas pela liga das escolas de samba para determinar o campeão do Carnaval. Cada grupo é avaliado em vários aspectos. Em cada aspecto, cada escola recebe cinco notas, variando de 5 a 10. A nota final da escola em um determinado aspecto é a soma das três notas do meio recebidas pela escola, excluindo a maior e a menor das cinco notas. O presidente da liga pediu que você escrevesse um programa que, dadas as notas da escola de samba, calcule sua nota final em um determinado aspecto.

Entrada
Cinco valores inteiros correspondendo as notas das escolas.

Saída
Um número correspondendo a nota da escola.

Exemplo de entrada	Exemplo de saída
10 9 9 9 8	        27
10 10 10 10 10	    30
10 9 8 7 6	        24
10 9 9 8 8	        26
*/

#include <stdio.h>

int main() {
    int nota1, nota2, nota3, nota4, nota5, soma;
    scanf("%i%i%i%i%i", &nota1, &nota2, &nota3, &nota4, &nota5);
        
    //teste de maiores//
    if(nota1 > nota2 && nota1 > nota3 && nota1 > nota4 && nota1 > nota5)
        soma = nota2 + nota3 + nota4 + nota5;
    if(nota2 > nota1 && nota2 > nota3 && nota2 > nota4 && nota2 > nota5)
        soma = nota1 + nota3 + nota4 + nota5;
    if(nota3 > nota1 && nota3 > nota2 && nota3 > nota4 && nota3 > nota5)
        soma = nota1 + nota2 + nota4 + nota5;
    if(nota4 > nota1 && nota4 > nota2 && nota4 > nota3 && nota4 > nota5)
        soma = nota1 + nota2 + nota3 + nota5;
    if(nota5 > nota1 && nota5 > nota2 && nota5 > nota3 && nota5 > nota4)
        soma = nota1 + nota2 + nota3 + nota4;
        
    //teste de menores//
    if(nota1 < nota2 && nota1 < nota3 && nota1 < nota4 && nota1 < nota5)
        soma -= nota1;
        
    if(nota2 < nota1 && nota2 < nota3 && nota2 < nota4 && nota2 < nota5)
        soma -= nota2;
    
    if(nota3 < nota1 && nota3 < nota2 && nota3 < nota4 && nota3 < nota5)
        soma -= nota3;
    
    if(nota4 < nota1 && nota4 < nota2 && nota4 < nota3 && nota4 < nota5)
        soma -= nota4;
    
    if(nota5 < nota1 && nota5 < nota2 && nota5 < nota3 && nota5 < nota4)
        soma -= nota5;
    
    if(nota4 == nota5 && nota5 == 8)
        soma -= 8;
    
    if(nota1 == nota2 && nota2 == nota3 && nota3 == nota4 && nota4 == nota5)
        soma = nota1 + nota2 + nota3;
    
    printf("%i", soma);
    
    return 0;
}
