#include <iostream>
#include <algorithm>

using namespace std;

long w, h, n;

bool good(long x) {
    return (x / w) * (x / h) >= n;
}

int main() {
    cin >> w >> h >> n;

    long l = 0;
    long r = max(w, h) * n;

    while (r - l > 1) {
        long mid = (l + r) / 2;

        if (good(mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }

    cout << r;

    return 0;
}
