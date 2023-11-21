#include <iostream>
#include <vector>

using namespace std;

void selectionSort(vector<int>& arr) {
    int n = arr.size();
    
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
        }
        
        // Print array after each iteration
        cout << "Iteration " << i + 1 << ": ";
        for (int num : arr) {
            cout << num << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<int> arr = {120, 90, 150, 80, 110};
    
    cout << "Original array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
    
    selectionSort(arr);
    
    cout << "Sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}
/*A principal parte do algoritmo é a função selectionSort, que executa a ordenação por Selection Sort. 
Durante o processo, o estado do vetor é impresso após cada iteração para ilustrar o progresso da ordenação. 
Isso ajuda a visualizar como os elementos vão sendo colocados em ordem durante as iterações do algoritmo.*/