#include <vector>
#include <iostream>

using namespace std;

void InsertionSort(vector<int>& arr) {
    for (int i = 1; i < arr.size(); i++) {
        int cur = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] >= cur) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = cur;
    }

}

int main() {
    vector<int> A;
    int value;

    while (cin >> value) {
        A.push_back(value);
    }

    InsertionSort(A);

    for (int i = 0; i < A.size(); i++) {
        cout << A[i];
        if (i + 1 < A.size()) {
            cout << ' ';
        }
    }
    cout << '\n';

    return 0;
}
