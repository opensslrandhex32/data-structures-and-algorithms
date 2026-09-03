#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;


void quickSort(vector<int> &arr, int lo, int hi) {
    if (lo >= hi) return;

    int pivotIndex = lo + (hi - lo) / 2;
    swap(arr[pivotIndex], arr[hi]);
    int pivot = arr[hi];
    int i = lo;
    for (int j = lo; j < hi; j++) {
        if (arr[j] < pivot) {
            swap(arr[j], arr[i++]);
        }
    }
    swap(arr[i], arr[hi]);
    quickSort(arr, lo, i - 1);
    quickSort(arr, i + 1, hi);
}

void quickSort(vector<int> &arr) {
    if (!arr.empty()) {
        quickSort(arr, 0, static_cast<int>(arr.size()) - 1);
    }
}

int main() {
    int N;
    cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    quickSort(arr);

    for (int i = 0; i < N; i++) {
        cout << arr[i] << ' ';
    }

    return 0;
}
