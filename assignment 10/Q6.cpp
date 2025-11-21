#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int d) : data(d), left(NULL), right(NULL) {}
};

bool findDuplicate(Node* root, unordered_set<int>& s) {
    if (!root) return false;

    if (s.count(root->data)) return true;
    s.insert(root->data);

    return findDuplicate(root->left, s) || 
           findDuplicate(root->right, s);
}

int main() {
    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(7);
    root->left->left = new Node(3);  // duplicate

    unordered_set<int> s;

    if (findDuplicate(root, s))
        cout << "Duplicates Found";
    else
        cout << "No Duplicates";
}
