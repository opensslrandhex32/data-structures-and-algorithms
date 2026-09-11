#include <iostream>
#include <string>

using namespace std;

int main() {
    string a, b;
    cin >> a >> b;

    if (a.length() != b.length()) {
        cout << "NO";
        return 0;
    }

    int count[36] = {};

    for (char c : a) {
        if (c >= 'a' && c <= 'z') {
            count[c - 'a']++;
        } else {
            count[26 + c - '0']++;
        }
    }

    for (char c : b) {
        if (c >= 'a' && c <= 'z') {
            count[c - 'a']--;
        } else {
            count[26 + c - '0']--;
        }
    }

    for (int i = 0; i < 36; i++) {
        if (count[i] != 0) {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";

    return 0;
}