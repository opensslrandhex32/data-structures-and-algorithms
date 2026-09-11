#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool compare(string& a, string& b) {
    return a + b > b + a;
}

int main() {
    vector<string> parts;
    string s;

    while (cin >> s) {
        parts.push_back(s);
    }

    sort(parts.begin(), parts.end(), compare);

    for (string& part : parts) {
        cout << part;
    }

    return 0;
}