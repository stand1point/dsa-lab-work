#include <iostream>
#include <stack>
using namespace std;

bool isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

bool isBalanced(string expr) {
    stack<char> s;

    for (char ch : expr) {
        // If opening bracket, push it
        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        } 
        // If closing bracket, check matching
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (s.empty()) return false; // no matching opening
            char top = s.top();
            s.pop();

            if (!isMatchingPair(top, ch)) {
                return false;
            }
        }
    }

    // If stack empty → all matched properly
    return s.empty();
}

int main() {
    string expr;
    cout << "Enter an expression: ";
    cin >> expr;

    if (isBalanced(expr))
        cout << "Balanced expression\n";
    else
        cout << "Not balanced\n";

    return 0;
}
