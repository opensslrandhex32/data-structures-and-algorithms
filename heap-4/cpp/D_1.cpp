#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class MaxHeap {
private:
    vector<long> data;

    void siftUp() {
        int i = data.size() - 1;
        while (i > 0 && data[i] > data[(i-1) / 2]) {
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
            int largestChild = left;
            if (
                right < sz
                && data[right] > data[largestChild]
            ) {
                largestChild = right;
            }

            if (data[i] >= data[largestChild])
                break;

            swap(data[i], data[largestChild]);
            i = largestChild;
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

    long extractMax() {
        long max = data[0];
        swap(data[0], data[data.size() - 1]);
        data.pop_back();

        if (!isEmpty()) {
            siftDown();
        }

        return max;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    MaxHeap heap;
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
                cout << heap.extractMax() << "\n";
            }
        }
    }

    return 0;
}
