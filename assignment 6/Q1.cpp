
// Circular ll

#include <iostream>
using namespace std;

struct CNode {
    int data;
    CNode* next;
};

CNode* chead = NULL;

// Insert at beginning
void cinsertBeg(int x) {
    CNode* temp = new CNode();
    temp->data = x;

    if (chead == NULL) {
        chead = temp;
        temp->next = chead;
        return;
    }

    CNode* t = chead;
    while (t->next != chead) t = t->next;

    temp->next = chead;
    t->next = temp;
    chead = temp;
}

// Insert at end
void cinsertEnd(int x) {
    CNode* temp = new CNode();
    temp->data = x;

    if (chead == NULL) {
        chead = temp;
        temp->next = chead;
        return;
    }

    CNode* t = chead;
    while (t->next != chead) t = t->next;

    t->next = temp;
    temp->next = chead;
}

// Insert before specific value
void cinsertBefore(int val, int newVal) {
    if (chead == NULL) return;

    if (chead->data == val) {
        cinsertBeg(newVal);
        return;
    }

    CNode* t = chead;
    while (t->next != chead && t->next->data != val)
        t = t->next;

    if (t->next != chead) {
        CNode* temp = new CNode();
        temp->data = newVal;
        temp->next = t->next;
        t->next = temp;
    }
}

// Insert after specific value
void cinsertAfter(int val, int newVal) {
    if (chead == NULL) return;

    CNode* t = chead;
    do {
        if (t->data == val) {
            CNode* temp = new CNode();
            temp->data = newVal;
            temp->next = t->next;
            t->next = temp;
            return;
        }
        t = t->next;
    } while (t != chead);
}

// Delete specific value
void cdeleteNode(int val) {
    if (chead == NULL) return;

    // If head to delete
    if (chead->data == val) {
        if (chead->next == chead) {
            delete chead;
            chead = NULL;
            return;
        }

        CNode* t = chead;
        while (t->next != chead)
            t = t->next;

        CNode* temp = chead;
        t->next = chead->next;
        chead = chead->next;
        delete temp;
        return;
    }

    CNode* t = chead;
    while (t->next != chead && t->next->data != val)
        t = t->next;

    if (t->next != chead) {
        CNode* temp = t->next;
        t->next = temp->next;
        delete temp;
    }
}

// Search
void csearch(int val) {
    if (chead == NULL) return;

    int pos = 1;
    CNode* t = chead;

    do {
        if (t->data == val) {
            cout << "Found at position " << pos << endl;
            return;
        }
        t = t->next;
        pos++;
    } while (t != chead);

    cout << "Not found\n";
}

// Display circular list
void cdisplay() {
    if (chead == NULL) return;

    CNode* t = chead;
    do {
        cout << t->data << " ";
        t = t->next;
    } while (t != chead);
    cout << endl;
}


// Doubly linked list

struct DNode {
    int data;
    DNode* next;
    DNode* prev;
};

DNode* dhead = NULL;

// Insert at beginning
void dinsertBeg(int x) {
    DNode* temp = new DNode();
    temp->data = x;
    temp->next = dhead;
    temp->prev = NULL;

    if (dhead != NULL)
        dhead->prev = temp;

    dhead = temp;
}

// Insert at end
void dinsertEnd(int x) {
    DNode* temp = new DNode();
    temp->data = x;
    temp->next = NULL;

    if (dhead == NULL) {
        temp->prev = NULL;
        dhead = temp;
        return;
    }

    DNode* t = dhead;
    while (t->next != NULL) t = t->next;

    t->next = temp;
    temp->prev = t;
}

// Insert before value
void dinsertBefore(int val, int newVal) {
    if (dhead == NULL) return;

    if (dhead->data == val) {
        dinsertBeg(newVal);
        return;
    }

    DNode* t = dhead;
    while (t != NULL && t->data != val)
        t = t->next;

    if (t != NULL) {
        DNode* temp = new DNode();
        temp->data = newVal;
        temp->next = t;
        temp->prev = t->prev;
        t->prev->next = temp;
        t->prev = temp;
    }
}

// Insert after value
void dinsertAfter(int val, int newVal) {
    DNode* t = dhead;
    while (t != NULL && t->data != val)
        t = t->next;

    if (t != NULL) {
        DNode* temp = new DNode();
        temp->data = newVal;
        temp->next = t->next;
        temp->prev = t;

        if (t->next != NULL)
            t->next->prev = temp;

        t->next = temp;
    }
}

// Delete node
void ddeleteNode(int val) {
    if (dhead == NULL) return;

    DNode* t = dhead;

    if (t->data == val) {
        dhead = t->next;
        if (dhead != NULL)
            dhead->prev = NULL;
        delete t;
        return;
    }

    while (t != NULL && t->data != val)
        t = t->next;

    if (t != NULL) {
        if (t->prev != NULL)
            t->prev->next = t->next;

        if (t->next != NULL)
            t->next->prev = t->prev;

        delete t;
    }
}

// Search
void dsearch(int val) {
    DNode* t = dhead;
    int pos = 1;

    while (t != NULL) {
        if (t->data == val) {
            cout << "Found at position " << pos << endl;
            return;
        }
        t = t->next;
        pos++;
    }
    cout << "Not found\n";
}

// Display
void ddisplay() {
    DNode* t = dhead;
    while (t != NULL) {
        cout << t->data << " ";
        t = t->next;
    }
    cout << endl;
}

