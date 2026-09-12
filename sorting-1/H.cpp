#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
    int x;
    int y;
};


bool comparePoints(Point& a, Point& b) {
    return a.x * a.x + a.y * a.y < b.x * b.x + b.y * b.y;
}

int main() {
    int n;
    cin >> n;

    vector<Point> points(n);

    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }

    sort(points.begin(), points.end(), comparePoints);

    for (Point& point : points) {
        cout << point.x << ' ' << point.y << '\n';
    }

    return 0;
}