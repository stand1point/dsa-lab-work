#include <iostream>
using namespace std;

#define MAX 100

struct PriorityQueue {
    int arr[MAX];
    int size;

    PriorityQueue() { size = 0; }

    void insert(int x) {
        int i = size;
        arr[size++] = x;

        while (i != 0 && arr[(i-1)/2] < arr[i]) {
            swap(arr[i], arr[(i-1)/2]);
            i = (i-1)/2;
        }
    }

    int extractMax() {
        if (size <= 0) return -1;

        int root = arr[0];
        arr[0] = arr[--size];

        heapify(0);
        return root;
    }

    void heapify(int i) {
        int largest = i;
        int l = 2*i+1, r = 2*i+2;

        if (l < size && arr[l] > arr[largest]) largest = l;
        if (r < size && arr[r] > arr[largest]) largest = r;

        if (largest != i) {
            swap(arr[i], arr[largest]);
            heapify(largest);
        }
    }

    void display() {
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};
