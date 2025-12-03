#include <iostream>
#include <stack>
#include <cctype>
using namespace std;

// Function to define precedence of operators
int precedence(char op) {
    if (op == '^')
        return 3;
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return 0;
}

// Check if operator is right associative (only ^)
bool isRightAssociative(char op) {
    return op == '^';
}

// Check if character is operator
bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

// Convert infix to postfix
string infixToPostfix(string infix) {
    stack<char> s;
    string postfix = "";

    for (char ch : infix) {

        // If operand, add to result
        if (isalnum(ch)) {
            postfix += ch;
        }

        // If opening parenthesis, push to stack
        else if (ch == '(') {
            s.push(ch);
        }

        // If closing parenthesis, pop until '('
        else if (ch == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            s.pop(); // remove '('
        }

        // If operator
        else if (isOperator(ch)) {
            while (!s.empty() && isOperator(s.top())) {

                // Precedence logic
                if ((precedence(ch) < precedence(s.top())) || 
                   (precedence(ch) == precedence(s.top()) && !isRightAssociative(ch))) 
                {
                    postfix += s.top();
                    s.pop();
                } else {
                    break;
                }
            }
            s.push(ch);
        }
    }

    // Pop remaining operators
    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }

    return postfix;
}

int main() {
    string infix;
    cout << "Enter an infix expression: ";
    cin >> infix;

    string postfix = infixToPostfix(infix);
    cout << "Postfix expression: " << postfix << endl;

    return 0;
}
