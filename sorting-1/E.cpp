#include <vector>
#include <iostream>
using namespace std;

void merge(vector<int>& full, vector<int>& left, vector<int>& right) {
    int i = 0, j = 0, k = 0, leftSize = left.size(), rightSize = right.size();

    while (i < leftSize && j < rightSize) {
        if (left[i] <= right[j])
            full[k++] = left[i++];
        else
            full[k++] = right[j++];
    }

    while (i < leftSize) {
        full[k++] = left[i++];
    }
    while (j < rightSize) {
        full[k++] = right[j++];
    }
}

void mergeSort(vector<int>& arr) {
    int arrSize = arr.size();
    if (arr.size() < 2) return;

    int midIndex = arrSize / 2;
    vector<int> left(midIndex);
    vector<int> right(arrSize - midIndex);

    for (int i = 0; i < midIndex; i++) {
        left[i] = arr[i];
    }
    for (int i = midIndex; i < arrSize; i++) {
        right[i - midIndex] = arr[i];
    }

    mergeSort(left);
    mergeSort(right);
    merge(arr, left, right);
}

int main() {
    int N;
    cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    mergeSort(arr);

    for (int i = 0; i < N; i++) {
        cout << arr[i] << ' ';
    }

    return 0;
}
