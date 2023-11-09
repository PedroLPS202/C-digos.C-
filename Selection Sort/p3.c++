#include <iostream>
using namespace std;

// Função para ordenar a matriz usando o Selection Sort por linha
void selectionSort2D(double arr[][3], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int minIndex = j;
            for (int k = j + 1; k < cols; k++) {
                if (arr[i][k] < arr[i][minIndex]) {
                    minIndex = k;
                }
            }
            // Troca o elemento atual com o elemento de menor valor
            if (minIndex != j) {
                swap(arr[i][j], arr[i][minIndex]);
            }
        }
    }
}

int main() {
    double arr[][3] = {
        {0.02, 0.08, 0.04},
        {0.05, 0.12, 0.09},
        {0.03, 0.06, 0.07}
    };
    int rows = sizeof(arr) / sizeof(arr[0]);
    int cols = sizeof(arr[0]) / sizeof(arr[0][0]);

    cout << "Original matrix:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    // Chama a função selectionSort2D para ordenar a matriz
    selectionSort2D(arr, rows, cols);

    cout << "Sorted matrix:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
