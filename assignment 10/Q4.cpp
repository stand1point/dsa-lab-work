#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> nums = {4, 5, 1, 2, 0, 4};

    unordered_map<int,int> freq;
    for (int x : nums) freq[x]++;

    for (int x : nums) {
        if (freq[x] == 1) {
            cout << x;
            return 0;
        }
    }

    cout << "No non-repeating element";
}
