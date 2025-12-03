#include <iostream>
#include <set>
using namespace std;

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    set<int> distinct;

    for (int i = 0; i < n; i++) {
        distinct.insert(arr[i]);   // duplicates are automatically ignored
    }

    cout << "Total number of distinct elements = " << distinct.size() << endl;

    return 0;
}
