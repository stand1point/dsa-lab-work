#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int A[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> A[i];

    int inversionCount = 0;

    // Count inversions
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (A[i] > A[j]) {
                inversionCount++;
            }
        }
    }

    cout << "Number of inversions: " << inversionCount << endl;

    return 0;
}
