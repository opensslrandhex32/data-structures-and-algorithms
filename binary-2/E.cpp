#include <iostream>
#include <vector>

using namespace std;

int N, K;
vector<int> a;

bool good(int d) {
    int last = 0, count = 1;
    for (int i = 0; i < N; i++) {
        if (a[i] - a[last] >= d) {
            last = i;
            count++;
        }
    }
    return count >= K;
}

int main() {
    cin >> N >> K;
    a.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    int l = -1, r = a[N - 1] - a[0] + 1;
    while (r - l > 1) {
        int mid = (r + l) / 2;
        if (good(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    cout << l;
    return 0;
}
