#include <iostream>
using namespace std;

// Função para ordenar o array usando o Selection Sort
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Troca o elemento atual com o elemento de menor valor
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
        }
    }
}

int main() {
    int arr[] = {120, 90, 150, 80, 110};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Chama a função selectionSort para ordenar o array
    selectionSort(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

/*A Selection Sort é um algoritmo simples, mas sua complexidade média e pior caso são O(n^2), o que também pode torná-la ineficiente para conjuntos de dados grandes.
 A principal vantagem da Selection Sort é que ele realiza um número constante de trocas, o que pode ser vantajoso em situações onde o custo de troca é alto (por exemplo, em trocas de registros em um banco de dados).
Agora, se você estiver lidando com conjuntos de dados maiores, é recomendável considerar algoritmos mais eficientes, como Quick Sort, Merge Sort ou mesmo algoritmos híbridos, como o Tim Sort.*/
