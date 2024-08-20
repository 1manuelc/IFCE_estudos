#include <iostream>

/* Bubble Sort
    Primeiro for percorre o vetor de trás para frente.
    Segundo for vai de 0 até o índice do primeiro for,
    trocando os valores maiores á esquerda.
*/

void bubbleSort(int arr[], int length) {
    int aux;
    
    for(int i = length - 1; i > 0; i--) {
        for(int j = 0; j < i; j++) {
            if(arr[j] > arr[j + 1]) {
                aux = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = aux;
            }
        }
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
    bubbleSort(array, 10);
    printArray(array, 10);
    
    return 0;
}
