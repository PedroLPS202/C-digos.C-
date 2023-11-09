#include <iostream>
using namespace std;

// Função para ordenar o array usando uma variação do Selection Sort
void modifiedSelectionSort(string arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        int maxIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
            if (arr[j] > arr[maxIndex]) {
                maxIndex = j;
            }
        }
        // Troca o elemento atual com o elemento de menor valor
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
        }
        // Se o máximo for o elemento atual, ajusta maxIndex após a troca
        if (maxIndex == i) {
            maxIndex = minIndex;
        }
        // Troca o elemento atual com o elemento de maior valor
        if (maxIndex != n - 1 - i) {
            swap(arr[n - 1 - i], arr[maxIndex]);
        }
    }
}

int main() {
    string arr[] = {"Pass", "Fail", "Pass", "Pass", "Fail"};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Chama a função modifiedSelectionSort para ordenar o array
    modifiedSelectionSort(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
