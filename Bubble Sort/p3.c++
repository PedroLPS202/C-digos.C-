#include <iostream>
using namespace std;

// Função para ordenar o array usando o Bubble Sort otimizado
void optimizedBubbleSort(string arr[], int n) {
    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        // Se nenhuma troca ocorreu nesta iteração, o array está ordenado
        if (!swapped) {
            break;
        }
    }
}

int main() {
    string arr[] = {"2023-09-10", "2023-08-15", "2023-08-25", "2023-09-30", "2023-08-05"};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Chama a função optimizedBubbleSort para ordenar o array
    optimizedBubbleSort(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
