#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

// Insert at beginning
void insertBeg(int x) {
    Node* temp = new Node();
    temp->data = x;
    temp->next = head;
    head = temp;
}

// Insert at end
void insertEnd(int x) {
    Node* temp = new Node();
    temp->data = x;
    temp->next = NULL;

    if (head == NULL) {
        head = temp;
        return;
    }
    Node* t = head;
    while (t->next != NULL) t = t->next;
    t->next = temp;
}

// Insert before a value
void insertBefore(int value, int newVal) {
    if (head == NULL) return;
    if (head->data == value) {
        insertBeg(newVal);
        return;
    }
    Node* t = head;
    while (t->next != NULL && t->next->data != value)
        t = t->next;

    if (t->next != NULL) {
        Node* temp = new Node();
        temp->data = newVal;
        temp->next = t->next;
        t->next = temp;
    }
}

// Insert after a value
void insertAfter(int value, int newVal) {
    Node* t = head;
    while (t != NULL && t->data != value)
        t = t->next;

    if (t != NULL) {
        Node* temp = new Node();
        temp->data = newVal;
        temp->next = t->next;
        t->next = temp;
    }
}

// Delete from beginning
void deleteBeg() {
    if (head == NULL) return;
    Node* temp = head;
    head = head->next;
    delete temp;
}

// Delete from end
void deleteEnd() {
    if (head == NULL) return;
    if (head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }
    Node* t = head;
    while (t->next->next != NULL)
        t = t->next;

    delete t->next;
    t->next = NULL;
}

// Delete specific node
void deleteNode(int value) {
    if (head == NULL) return;
    if (head->data == value) {
        deleteBeg();
        return;
    }
    Node* t = head;
    while (t->next != NULL && t->next->data != value)
        t = t->next;

    if (t->next != NULL) {
        Node* temp = t->next;
        t->next = temp->next;
        delete temp;
    }
}

// Search node
void search(int value) {
    int pos = 1;
    Node* t = head;
    while (t != NULL) {
        if (t->data == value) {
            cout << "Found at position: " << pos << endl;
            return;
        }
        t = t->next;
        pos++;
    }
    cout << "Not found\n";
}

// Display list
void display() {
    Node* t = head;
    while (t != NULL) {
        cout << t->data << " ";
        t = t->next;
    }
    cout << endl;
}

int main() {
    int choice, val, val2;

    while (true) {
        cout << "\nMENU\n";
        cout << "1. Insert at beginning\n2. Insert at end\n3. Insert before value\n";
        cout << "4. Insert after value\n5. Delete from beginning\n6. Delete from end\n";
        cout << "7. Delete specific node\n8. Search\n9. Display\n10. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: "; cin >> val;
            insertBeg(val);
            break;

        case 2:
            cout << "Enter value: "; cin >> val;
            insertEnd(val);
            break;

        case 3:
            cout << "Insert new value: "; cin >> val2;
            cout << "Before which value? "; cin >> val;
            insertBefore(val, val2);
            break;

        case 4:
            cout << "Insert new value: "; cin >> val2;
            cout << "After which value? "; cin >> val;
            insertAfter(val, val2);
            break;

        case 5:
            deleteBeg(); break;

        case 6:
            deleteEnd(); break;

        case 7:
            cout << "Enter value to delete: "; cin >> val;
            deleteNode(val);
            break;

        case 8:
            cout << "Enter value to search: "; cin >> val;
            search(val);
            break;

        case 9:
            display(); break;

        case 10:
            exit(0);
        }
    }
}
