/*

Você foi contratado para gerar o cartão de vacinação dos
cachorros registrados em um pet.

No cartão, é necessário registrar qual vacina e dose o
doguinho recebeu.

A clínica trabalha com 10 diferentes vacinas e, para cada
uma, podem ser aplicadas 5 doses.

Resolva o problema da clínica por meio de um algoritmo com
uma estrutura de dados apropriada.

Não esqueça de, ao final, mostrar o cartão do doguinho
informando quais doses de cada vacina ele recebeu :)

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main(){
    char nomeDog[21];
    int cartaoVacinaDog[10][5];
    printf("Digite o nome do cachorro: ");
    scanf("%s", nomeDog);

    srand(time(NULL));

    printf("\nCartao de vacina do(a): %s\n", nomeDog);
    printf("\n\tDoses:\t\t1\t2\t3\t4\t5");
    printf("\n----------------------------------------------------------");
    for(int i = 0; i <= 10; i++) {
        printf("\nVacina[%d]\t", i);
        for(int j = 0; j < 5; j++) {
            cartaoVacinaDog[i][j] = rand() % 2;
            if(cartaoVacinaDog[i][j] == 1)
                printf("\tX");
            else if(cartaoVacinaDog[i][j] == 0)
                printf("\t-");
        }

        if(i == 10) {
            printf("\n");
            printf("----------------------------------------------------------\n\n");
        }
    }
    
    system("pause");
}