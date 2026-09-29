#include <iostream>
#include <vector>
using namespace std;


bool binarySearch(vector<long>& A, long target) {
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

    return r < A.size() && A[r] == target;
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

        if (binarySearch(A, input)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}