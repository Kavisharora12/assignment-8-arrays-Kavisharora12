#include <iostream>
#include <climits>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = NULL;
    }
};

bool isBST(Node* root, int minVal = INT_MIN, int maxVal = INT_MAX) {
    if (root == NULL)
        return true;

    if (root->data < minVal || root->data > maxVal)
        return false;

    return isBST(root->left, minVal, root->data - 1) &&
           isBST(root->right, root->data + 1, maxVal);
}

Node* insert(Node* root, int value) {
    if (root == NULL)
        return new Node(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);

    return root;
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

    if (isBST(root))
        cout << "The tree is a BST." << endl;
    else
        cout << "The tree is NOT a BST." << endl;

    return 0;
}
