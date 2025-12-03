#include <iostream>
#include <queue>
using namespace std;

class StackUsingTwoQueues {
private:
    queue<int> q1, q2;

public:
    void push(int x) {
        q2.push(x);  // Push new element into q2

        // Move all elements from q1 to q2
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        // Swap queues
        swap(q1, q2);
    }

    void pop() {
        if (q1.empty()) {
            cout << "Stack is Empty!\n";
            return;
        }
        cout << q1.front() << " popped\n";
        q1.pop();
    }

    int top() {
        if (q1.empty()) {
            cout << "Stack is Empty!\n";
            return -1;
        }
        return q1.front();
    }

    bool isEmpty() {
        return q1.empty();
    }
};

int main() {
    StackUsingTwoQueues st;
    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Top element = " << st.top() << endl;

    st.pop();
    st.pop();
    
    cout << "Top element = " << st.top() << endl;

    return 0;
}
