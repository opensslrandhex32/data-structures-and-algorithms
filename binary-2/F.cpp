#include <iostream>

using namespace std;

long N, x, y;

bool good(long t) {
    return t / x + t / y >= N - 1;
}

int main() {
    cin >> N >> x >> y;

    long first = min(x, y);

    long l = -1;
    long r = first * N;

    while (r - l > 1) {
        long mid = (l + r) / 2;

        if (good(mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }

    cout << first + r;

    return 0;
}