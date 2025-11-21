#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* next;
    Node* prev;
};

Node* head1 = NULL;

bool isPalindrome() {
    if (head1 == NULL) return true;

    Node* left = head1;
    Node* right = head1;

    while (right->next != NULL)
        right = right->next;

    while (left != right && right->next != left) {
        if (left->data != right->data)
            return false;

        left = left->next;
        right = right->prev;
    }
    return true;
}
