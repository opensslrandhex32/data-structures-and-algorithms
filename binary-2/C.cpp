#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double good(double x, double C) {
    return pow(x, 2) + sqrt(x) > C;
}


int main() {
    double C;
    cin >> C;

    double l = 0.0, r = sqrt(C), mid = 0.0;
    for (int i = 0; i < 100; i++) {
        mid = (r + l) / 2;
        if (good(mid, C)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    cout << fixed << setprecision(6) << mid;
}
