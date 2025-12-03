#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void interleave(queue<int>& q) {
    int n = q.size();

    if (n % 2 != 0) {
        cout << "Queue size must be even!\n";
        return;
    }

    int half = n / 2;
    stack<int> s;

    // Step 1: Move first half elements into the stack
    for (int i = 0; i < half; i++) {
        s.push(q.front());
        q.pop();
    }

    // Step 2: Push back stack elements to queue (reversed first half)
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }

    // Step 3: Move first half (which is reversed) into stack again
    for (int i = 0; i < half; i++) {
        s.push(q.front());
        q.pop();
    }

    // Step 4: Interleave values from stack and queue
    while (!s.empty()) {
        q.push(s.top());  // from first half
        s.pop();

        q.push(q.front());  // from second half
        q.pop();
    }
}

int main() {
    queue<int> q;
    int n, value;

    cout << "Enter number of elements (even count): ";
    cin >> n;

    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> value;
        q.push(value);
    }

    interleave(q);

    cout << "Interleaved Queue: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}
