struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* insert(Node* root, int x) {
    if (root == NULL) {
        root = new Node();
        root->data = x;
        root->left = root->right = NULL;
        return root;
    }
    if (x < root->data) root->left = insert(root->left, x);
    else if (x > root->data) root->right = insert(root->right, x);
    return root;
}


Node* searchRec(Node* root, int key) {
    if (root == NULL || root->data == key) return root;

    if (key < root->data)
        return searchRec(root->left, key);
    else
        return searchRec(root->right, key);
}


Node* searchNonRec(Node* root, int key) {
    while (root != NULL) {
        if (root->data == key) return root;
        else if (key < root->data) root = root->left;
        else root = root->right;
    }
    return NULL;
}


int findMax(Node* root) {
    while (root->right != NULL)
        root = root->right;
    return root->data;
}


int findMin(Node* root) {
    while (root->left != NULL)
        root = root->left;
    return root->data;
}


Node* inorderSuccessor(Node* root, Node* node) {
    if (node->right != NULL) {
        node = node->right;
        while (node->left != NULL)
            node = node->left;
        return node;
    }

    Node* succ = NULL;
    while (root != NULL) {
        if (node->data < root->data) {
            succ = root;
            root = root->left;
        } else if (node->data > root->data) {
            root = root->right;
        } else break;
    }
    return succ;
}


Node* inorderPredecessor(Node* root, Node* node) {
    if (node->left != NULL) {
        node = node->left;
        while (node->right != NULL)
            node = node->right;
        return node;
    }

    Node* pred = NULL;
    while (root != NULL) {
        if (node->data > root->data) {
            pred = root;
            root = root->right;
        } else if (node->data < root->data) {
            root = root->left;
        } else break;
    }
    return pred;
}


