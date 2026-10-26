#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class MinHeap {
private:
    vector<long> data;

    void siftUp() {
        int i = data.size() - 1;
        while (i > 0 && data[i] < data[(i-1) / 2]) {
            swap(data[i], data[(i-1) / 2]);
            i = (i-1) / 2;
        }
    }

    void siftDown() {
        int i = 0;
        int sz = data.size();
        while (2 * i + 1 < sz) {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            int smallestChild = left;
            if (
                right < sz
                && data[right] < data[smallestChild]
            ) {
                smallestChild = right;
            }

            if (data[i] <= data[smallestChild])
                break;

            swap(data[i], data[smallestChild]);
            i = smallestChild;
        }
    }

public:
    void clear() {
        data.clear();
    }

    bool isEmpty() {
        return data.empty();
    }

    void add(long val) {
        data.push_back(val);
        siftUp();
    }

    long extractMin() {
        long min = data[0];
        swap(data[0], data[data.size() - 1]);
        data.pop_back();

        if (!isEmpty()) {
            siftDown();
        }

        return min;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    MinHeap heap;
    string cmd;

    while (cin >> cmd) {
        if (cmd == "ADD") {
            long n;
            cin >> n;
            heap.add(n);
        } else if (cmd == "CLEAR") {
            heap.clear();
        } else if (cmd == "EXTRACT") {
            if (heap.isEmpty()) {
                cout << "CANNOT\n";
            } else {
                cout << heap.extractMin() << "\n";
            }
        }
    }

    return 0;
}
