Node* recursiveSearch(Node* root, int key) {
    if (!root || root->data == key) return root;
    if (key < root->data) return recursiveSearch(root->left, key);
    return recursiveSearch(root->right, key);
}

Node* iterativeSearch(Node* root, int key) {
    while (root) {
        if (key == root->data) return root;
        else if (key < root->data) root = root->left;
        else root = root->right;
    }
    return nullptr;
}


int maxElement(Node* root) {
    if (!root) return -1;
    while (root->right) root = root->right;
    return root->data;
}
int minElement(Node* root) {
    if (!root) return -1;
    while (root->left) root = root->left;
    return root->data;
}
Node* inorderSuccessor(Node* root, Node* target) {
    Node* succ = nullptr;

    while (root) {
        if (target->data < root->data) {
            succ = root;
            root = root->left;
        } 
        else {
            root = root->right;
        }
    }
    return succ;
}
Node* inorderPredecessor(Node* root, Node* target) {
    Node* pred = nullptr;

    while (root) {
        if (target->data > root->data) {
            pred = root;
            root = root->right;
        } 
        else {
            root = root->left;
        }
    }
    return pred;
}
