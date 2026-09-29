#include <iostream>
#include <vector>
using namespace std;

long binarySearch(const vector<long>& A, long target) {
    int l = -1;
    int r = A.size();

    while (r - l > 1) {
        int mid = l + (r - l) / 2;

        if (A[mid] < target) {
            l = mid;
        } else {
            r = mid;
        }
    }

    // все элементы больше target
    if (l == -1) {
        return A[r];
    }

    // все элементы меньше target
    if (r == A.size()) {
        return A[l];
    }

    // если A[l] находится ближе к target или на таком же расстоянии, как A[r], возвращаем A[l]
    if (target - A[l] <= A[r] - target) {
        return A[l];
    }
    return A[r];
}

int main() {
    int N, K;
    cin >> N >> K;

    vector<long> A(N);

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    for (int i = 0; i < K; i++) {
        long input;
        cin >> input;

        cout << binarySearch(A, input) << '\n';
    }

    return 0;
}