Node* deleteNode(Node* root, int key) {
    if (root == NULL) return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);

    else if (key > root->data)
        root->right = deleteNode(root->right, key);

    else {
        // Only one child or no child
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Two children: in-order successor
        Node* temp = root->right;
        while (temp->left != NULL) temp = temp->left;

        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}


int maxDepth(Node* root) {
    if (root == NULL) return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}


int minDepth(Node* root) {
    if (root == NULL) return 0;
    if (root->left == NULL) return 1 + minDepth(root->right);
    if (root->right == NULL) return 1 + minDepth(root->left);
    return 1 + min(minDepth(root->left), minDepth(root->right));
}
