#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;
    node(int val) {
        data = val;
        left = right = NULL;
    }
};

void inorder(node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

node* insert(node* root, int target) {
    if (!root) return new node(target);
    if (target < root->data)
        root->left = insert(root->left, target);
    else if (target > root->data)
        root->right = insert(root->right, target);
    return root;
}

node* inorderSuccessor(node* root, int key) {
    node* successor = NULL;

    while (root) {
        if (key >= root->data)
            root = root->right;
        else {
            successor = root;
            root = root->left;
        }
    }
    return successor;
}

int main() {
    int arr[] = {9,5,7,6,8,4,2,3};
    node* root = NULL;

    for (int i = 0; i < 8; i++)
        root = insert(root, arr[i]);

    inorder(root);
    cout << endl;

    int key;
    cout << "Enter key to find inorder successor: ";
    cin >> key;

    node* ans = inorderSuccessor(root, key);

    if (ans)
        cout << "In-order successor of " << key << " is: " << ans->data;
    else
        cout << "No In-order successor exists";

    return 0;
}

