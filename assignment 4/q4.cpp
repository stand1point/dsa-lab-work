#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

void firstNonRepeating(string stream) {
    unordered_map<char, int> freq;
    queue<char> q;

    for (char ch : stream) {
        freq[ch]++;
        q.push(ch);

        while (!q.empty() && freq[q.front()] > 1)
            q.pop();

        if (!q.empty())
            cout << q.front() << " ";
        else
            cout << -1 << " ";
    }
    cout << "\n";
}

int main() {
    string s;
    cout << "Enter characters (no space): ";
    cin >> s;
    firstNonRepeating(s);
}
