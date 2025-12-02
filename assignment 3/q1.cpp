#include <iostream>
using namespace std;

#define MAX 100   // Maximum size of stack

class Stack {
private:
    int arr[MAX];
    int top;

public:
    Stack() {
        top = -1;   // Empty stack
    }

    // Check if stack is empty
    bool isEmpty() {
        return top == -1;
    }

    // Check if stack is full
    bool isFull() {
        return top == MAX - 1;
    }

    // Push operation
    void push(int value) {
        if (isFull()) {
            cout << "Stack Overflow! Cannot push element.\n";
        }
        else {
            arr[++top] = value;
            cout << value << " pushed into the stack.\n";
        }
    }

    // Pop operation
    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! Cannot pop element.\n";
        }
        else {
            cout << arr[top] << " popped from the stack.\n";
            top--;
        }
    }

    // Peek (top element)
    void peek() {
        if (isEmpty()) {
            cout << "Stack is Empty!\n";
        }
        else {
            cout << "Top el
