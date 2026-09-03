#include <vector>
#include <iostream>
using namespace std;


int BubbleSort(vector<int> &arr) {
    int с = 0;
    bool isSorted = false;
    while (!isSorted) {
        isSorted = true;
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] < arr[i - 1]) {
                isSorted = false;
                swap(arr[i], arr[i - 1]);
                с++;
            }
        }
    }
    return с;
}


int main() {
    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    cout << BubbleSort(A) << '\n';

    return 0;
}
