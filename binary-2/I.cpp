#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int firstGreaterEqual(const vector<long>& a, long target) {
    int l = -1;
    int r = a.size();

    while (r - l > 1) {
        int mid = (l + r) / 2;

        if (a[mid] >= target) {
            r = mid;
        } else {
            l = mid;
        }
    }

    return r;
}

int firstGreater(const vector<long>& a, long target) {
    int l = -1;
    int r = a.size();

    while (r - l > 1) {
        int mid = (l + r) / 2;

        if (a[mid] > target) {
            r = mid;
        } else {
            l = mid;
        }
    }

    return r;
}

int main() {
    int N;
    cin >> N;
    vector<long> A(N);

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    int M;
    cin >> M;

    for (int i = 0; i < M; i++) {
        long x;
        cin >> x;

        int left = firstGreaterEqual(A, x);
        int right = firstGreater(A, x);

        cout << right - left << ' ';
    }
    return 0;
}