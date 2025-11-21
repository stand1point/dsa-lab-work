#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

void insert(int x) {
    Node* t = new Node();
    t->data = x;
    t->next = head;
    head = t;
}

int findMiddle() {
    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->data;
}

int main() {
    for (int i = 5; i >= 1; i--)
        insert(i);

    cout << "Middle: " << findMiddle();
}
