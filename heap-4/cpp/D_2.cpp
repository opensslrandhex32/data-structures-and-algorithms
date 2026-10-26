#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main()
{
    string сmd;
    priority_queue<int> heap;
    int num;
    while (cin >> сmd)
    {
        if (сmd == "CLEAR") {
            heap = priority_queue<int>();
        } else if (сmd == "ADD") {
            cin >> num;
            heap.push(num);
        } else if (сmd == "EXTRACT") {
            if (heap.empty()) {
                cout << "CANNOT\n";
            } else {
                cout << heap.top() << "\n";
                heap.pop();
            }
        }
    }
}