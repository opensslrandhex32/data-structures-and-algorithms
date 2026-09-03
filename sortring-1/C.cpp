#include <iostream>
#include <vector>

using namespace std;

vector<int> BubbleSort(vector<int>& A) {
    int n = A.size();
    bool isSorted = false;

    while (!isSorted) {
        isSorted = true;

        for (int i = 0; i < n - 1; i++) {
            if (A[i] < A[i + 1]) {
                swap(A[i], A[i + 1]);
                isSorted = false;
            }
        }
    }

    return A;
}

int main() {
    vector<int> A;
    int value;

    while (cin >> value) {
        A.push_back(value);
    }

    BubbleSort(A);

    for (int i = 0; i < A.size(); i++) {
        cout << A[i];
        if (i + 1 < A.size()) {
            cout << ' ';
        }
    }

    return 0;
}
