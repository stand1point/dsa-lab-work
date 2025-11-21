#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

void displayCircular() {
    if (head == NULL) return;

    Node* t = head;
    do {
        cout << t->data << " ";
        t = t->next;
    } while (t != head);

    cout << head->data;  // repeating value of head
}
