#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;

    Node(int value) {
        data = value;
        left = right = NULL;
    }
};

Node* insert(Node* root, int value) {
    if (root == NULL)
        return new Node(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);

    return root;
}


int minDepth(Node* root) {
    if (root == NULL)
        return 0;

    
    if (!root->left)
        return 1 + minDepth(root->right);
    if (!root->right)
        return 1 + minDepth(root->left);

    return 1 + min(minDepth(root->left), minDepth(root->right));
}

int main() {
    Node* root = NULL;

    root = insert(root, 9);
    root = insert(root, 5);
    root = insert(root, 7);
    root = insert(root, 6);
    root = insert(root, 8);
    root = insert(root, 4);
    root = insert(root, 2);
    root = insert(root, 3);

    cout << "Minimum depth of tree = " << minDepth(root);

    return 0;
}
