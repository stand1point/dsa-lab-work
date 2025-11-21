int sizeDoubly() {
    int count = 0;
    DNode* t = dhead;
    while (t != NULL) {
        count++;
        t = t->next;
    }
    return count;
}


int sizeCircular() {
    if (chead == NULL) return 0;

    int count = 0;
    CNode* t = chead;

    do {
        count++;
        t = t->next;
    } while (t != chead);

    return count;
}
