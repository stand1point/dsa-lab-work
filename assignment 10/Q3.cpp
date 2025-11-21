#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> nums = {2, 3, 2, 4, 3, 2};

    unordered_map<int, int> mp;
    for (int x : nums) mp[x]++;

    for (auto &p : mp) {
        cout << p.first << " → " << p.second << " times\n";
    }
}
