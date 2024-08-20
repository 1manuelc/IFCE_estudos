#include <iostream>

/* Insertion Sort
    Primeiro for vai de 1 até n - 1,
    actual é o valor do vetor no índice atual do for.

    j vai ser o índice dos valores anteriores ao índice
    do primeiro for, que vai ser decrementado para 
    comparar cada valor a esquerda no número atual,
    se o número da esquerda for maior, virá para a
    direita do índice j.

    após o fim das comparações e trocas, o número
    atual de comparação vai para a posição atual do for.

*/

void insertionSort(int arr[], int length) {
    int actual, j;
    
    for(int i = 1; i < length; i++) {
        actual = arr[i];
        j = i - 1;

        while(j >= 0 && arr[j] > actual) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = actual;
    }
}

void printArray(int arr[], int length) {
    std::cout << '[';
    
    for(int i = 0; i < length; i++) {    
        if(i != length - 1) {
            std::cout << arr[i] << ", ";
        } else {
            std::cout << arr[i] << "]\n";
        }
    }
}

int main(int argc, char const *argv[]) {
    int array[] = {2, 5, 8, 10, 1, 20, 15, 0, 21, 2};
    
    printArray(array, 10);
    insertionSort(array, 10);
    printArray(array, 10);
    
    return 0;
}
