#include <iostream>
#include <queue>
using namespace std;
template<typename T>
ostream& operator<<(ostream& os, priority_queue<T>& queue) {
    auto q = queue; // copy by value
    os << "{";
    for (const char* sep = ""; !q.empty(); q.pop(), sep = ", ")
        os << sep << q.top();
    return os << "}";
}

int main() {
    priority_queue<int> q;

    q.push(3);
    q.push(1);
    q.push(4);
    cout << "[1] " << q << endl;

    q.push(-2);
    q.push(10);
    cout << "[2] " << q << endl;

    while (!q.empty()) q.pop();
    cout << "[3] " << q << endl;
}
