#include <iostream>
#include <vector>
using namespace std;

int getMaxIndex(vector<int>& arr, int start) {
    int maxIndex = start;
    for (int i = start + 1; i < arr.size(); i++) {
        if (arr[i] > arr[maxIndex]) {
            maxIndex = i;
        }
    }
    return maxIndex;
}

void swap(vector<int>& arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void SelectionSort(vector<int>& A) {
    for (int i = 0; i < A.size(); i++) {
        int maxIndex = getMaxIndex(A, i);
        swap(A, i, maxIndex);
    }
}

int main() {
    vector<int> A;
    int value;

    while (cin >> value) {
        A.push_back(value);
    }

    SelectionSort(A);

    for (int i = 0; i < A.size(); i++) {
        cout << A[i];
        if (i + 1 < A.size()) {
            cout << ' ';
        }
    }
    cout << '\n';

    return 0;
}
