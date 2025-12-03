#include <iostream>
#include <vector>
using namespace std;

struct Triple {
    int r, c, v;
};

class Sparse {
public:
    int rows, cols, nonZero;
    vector<Triple> data;

    // Create the sparse matrix
    void read() {
        cout << "Enter number of rows, columns, non-zero elements: ";
        cin >> rows >> cols >> nonZero;

        data.resize(nonZero + 1); // index 0 stores header
        data[0] = {rows, cols, nonZero};

        cout << "Enter triplets (row col value):\n";
        for (int i = 1; i <= nonZero; i++) {
            cin >> data[i].r >> data[i].c >> data[i].v;
        }
    }

    // Display the sparse matrix
    void display() {
        cout << "\n(r, c, v):\n";
        for (int i = 0; i <= nonZero; i++) {
            cout << data[i].r << "\t" << data[i].c << "\t" << data[i].v << "\n";
        }
    }

    // Simple transpose
    Sparse transpose() {
        Sparse T;
        T.rows = cols;
        T.cols = rows;
        T.nonZero = nonZero;
        T.data.resize(nonZero + 1);

        T.data[0] = {T.rows, T.cols, T.nonZero};

        int k = 1;
        for (int col = 0; col < cols; col++) {
            for (int i = 1; i <= nonZero; i++) {
                if (data[i].c == col) {
                    T.data[k++] = {data[i].c, data[i].r, data[i].v};
                }
            }
        }
        return T;
    }

    // Fast transpose
    Sparse fastTranspose() {
        Sparse T;
        T.rows = cols;
        T.cols = rows;
        T.nonZero = nonZero;
        T.data.resize(nonZero + 1);

        T.data[0] = {T.rows, T.cols, T.nonZero};

        vector<int> count(cols, 0);
        vector<int> index(cols, 0);

        // Count how many in each column
        for (int i = 1; i <= nonZero; i++)
            count[data[i].c]++;

        // Index of first element in each column
        index[0] = 1;
        for (int i = 1; i < cols; i++)
            index[i] = index[i - 1] + count[i - 1];

        // Place elements directly
        for (int i = 1; i <= nonZero; i++) {
            int pos = ind
