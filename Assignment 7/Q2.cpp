#include <iostream>
using namespace std;

void improvedSelectionSort(int a[], int n) {
    int left = 0, right = n - 1;

    while (left < right) {
        int minIndex = left;
        int maxIndex = right;

        // If first element is bigger than last, swap indices
        if (a[minIndex] > a[maxIndex])
            swap(a[minIndex], a[maxIndex]);

        // Scan between left and right
        for (int i = left + 1; i < right; i++) {
            if (a[i] < a[minIndex])
                minIndex = i;
            else if (a[i] > a[maxIndex])
                maxIndex = i;
        }

        // Place min at left
        swap(a[left], a[minIndex]);

        // If max element was swapped and now at minIndex position
        if (maxIndex == left)
            maxIndex = minIndex;

        // Place max at right
        swap(a[right], a[maxIndex]);

        left++;
        right--;
    }
}

void printArray(int a[], int n) {
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int a[n];
    cout << "Enter array: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    improvedSelectionSort(a, n);

    cout << "Improved Selection Sort: ";
    printArray(a, n);
}
