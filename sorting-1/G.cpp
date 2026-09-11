#include <iostream>
#include <vector>
using namespace std;

void CountSort(vector<int>& A) {
    vector<int> count(101, 0);

    for (int x : A) {
        count[x]++;
    }

    int index = 0;
    for (int x = 0; x < 101; x++) {
        while (count[x] > 0) {
            A[index++] = x;
            count[x]--;
        }
    }
}

int main() {
    vector<int> A;
    int x;

    while (cin >> x) {
        A.push_back(x);
    }

    CountSort(A);

    for (int i = 0; i < A.size(); i++) {
        cout << A[i] << ' ';
    }

    return 0;
}