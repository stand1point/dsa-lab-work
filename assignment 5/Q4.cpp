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

void reverse() {
    Node* prev = NULL;
    Node* cur = head;
    Node* next = NULL;

    while (cur != NULL) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    head = prev;
}

void display() {
    Node* t = head;
    while (t != NULL) {
        cout << t->data << "->";
        t = t->next;
    }
    cout << "NULL\n";
}

int main() {
    insert(4);
    insert(3);
    insert(2);
    insert(1);

    reverse();
    display();
}
