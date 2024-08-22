#include <iostream>

/* Selection Sort
    Consiste em achar o menor valor possível para cada índice do array
    de forma gradativa, de forma a puxar o menor valor para o índice da vez.

    Usa uma variável auxiliar min para sobrescrever o índice do menor valor ao
    comparar itens do array, depois substitui o valor na posição mais á esquerda.
*/

using namespace std;

void printArray(int[], int);
void selectionSort(int[], int);

void selectionSort(int arr[], int length) {
    int aux, minIndex;

    for(int i = 0; i < length - 1; i++) {
        minIndex = i;

        for(int j = i + 1; j < length; j++) {
            if(arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        if(minIndex != i) {
            aux = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = aux;
        }
    }
}

void printArray(int arr[], int length) {
    cout << '[';
    
    for(int i = 0; i < length; i++) {    
        if(i != length - 1) {
            cout << arr[i] << ",\t";
        } else {
            cout << arr[i] << "]\n";
        }
    }
}

int main(int argc, char const *argv[]) {
    int array[] = {2, 5, 8, 10, 1, 20, 15, 0, 21, 2};
    
    printArray(array, 10);
    selectionSort(array, 10);
    printArray(array, 10);
    
    return 0;
}
