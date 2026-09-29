#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, K;
vector<int> a;

bool good(int x) {
    int count = 0;

    for (int i = 0; i < N; i++) {
        count += a[i] / x;
    }

    return count >= K;
}

int main() {
    cin >> N >> K;

    a.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    int l = 0;
    int r = *max_element(a.begin(), a.end()) + 1;

    while (r - l > 1) {
        int mid = (l + r) / 2;

        if (good(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }

    cout << l;

    return 0;
}