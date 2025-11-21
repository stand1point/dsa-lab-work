#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

void insert(int x) {
    Node* temp = new Node();
    temp->data = x;
    temp->next = head;
    head = temp;
}

void deleteAll(int key) {
    while (head != NULL && head->data == key) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    Node* t = head;
    while (t != NULL && t->next != NULL) {
        if (t->next->data == key) {
            Node* temp = t->next;
            t->next = temp->next;
            delete temp;
        } else {
            t = t->next;
        }
    }
}

int countKey(int key) {
    int count = 0;
    Node* t = head;
    while (t != NULL) {
        if (t->data == key)
            count++;
        t = t->next;
    }
    return count;
}

void display() {
    Node* t = head;
    while (t != NULL) {
        cout << t->data << " ";
        t = t->next;
    }
    cout << endl;
}

int main() {
    int arr[] = {1,2,1,2,1,3,1};
    for (int x : arr) insert(x);

    int key = 1;
    int c = countKey(key);
    deleteAll(key);

    cout << "Count: " << c << endl;
    cout << "Updated Linked List: ";
    display();
}
