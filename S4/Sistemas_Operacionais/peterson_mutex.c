#include <stdio.h>
#include <pthread.h>
#include <unistd.h> // Adicionado para usar o método sleep

#define TRUE 1
#define FALSE 0
#define NUM_THREADS 2

#define ANSI_VERDE "\e[0;32m"
#define ANSI_VERMELHO "\x1b[31m"
#define ANSI_CINZA "\033[90m"
#define ANSI_RESET "\x1b[0m"

int vez;
int interessados[NUM_THREADS];

void entrarNaRegiao(int processo) {
    int outro = 1 - processo;

    interessados[processo] = TRUE;
    vez = processo;

    while (interessados[outro] == TRUE && vez == processo) {
        printf(ANSI_CINZA "\n\t...Thread %d está na espera ocupada...\n" ANSI_RESET, processo);
        fflush(stdout); // Limpa o buffer de saída para garantir a exibição
        sleep(1); // Atraso de 1 segundo entre as iterações
    }
}

void sairDaRegiao(int processo) {
    interessados[processo] = FALSE;
}

void *iniciarThread(void *arg) {
    int id = *((int *) arg);

    printf(ANSI_VERDE "Thread %d entrou na região crítica\n" ANSI_RESET, id);
    entrarNaRegiao(id);

    for (int i = 0; i < 5; i++) {
        sleep(1);
        printf("\tThread %d está na região crítica (%ds)\n", id, (i + 1));
        fflush(stdout); 
    }

    printf(ANSI_VERMELHO "\nThread %d saiu da região crítica\n\n" ANSI_RESET, id);

    sairDaRegiao(id);

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int idThreads[NUM_THREADS];

    printf("\n");
    
    for (int i = 0; i < NUM_THREADS; i++) {
        idThreads[i] = i;
        pthread_create(&threads[i], NULL, iniciarThread, &idThreads[i]);
    }

    for (int i = 0; i < NUM_THREADS; i++)
        pthread_join(threads[i], NULL);

    return 0;
}
