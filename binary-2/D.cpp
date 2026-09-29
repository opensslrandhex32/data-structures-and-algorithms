#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;

double a, b, c, d;

double good(double x) {
    return  a * pow(x, 3) + b * pow(x, 2) + c * x + d > 0;
}

int main() {
    cin >> a >> b >> c >> d;

    // переворачиваем график относительно оси OX чтобы не писать две версии бин.поиска
    if (a < 0) {
        a = -a;
        b = -b;
        c = -c;
        d = -d;
    }

    double l = -1001;
    double r = 1001;
    double mid;

    for (int i = 0; i < 100; i++) {
        mid = (l + r) / 2;

        if (good(mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }

    cout << fixed << setprecision(4) << mid;

    return 0;
}