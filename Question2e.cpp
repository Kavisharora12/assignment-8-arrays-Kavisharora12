#include<iostream>
using namespace std;

class node{
public:
    int data;
    node *left, *right;
    node(int val){
        data = val;
        left = right = NULL;
    }
};

node* insert(node* root, int val){
    if(!root) return new node(val);

    if(val < root->data)
        root->left = insert(root->left, val);
    else if(val > root->data)
        root->right = insert(root->right, val);

    return root;
}

void inorder(node* root){
    if(!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

node* inorderPredecessor(node* root, int key){
    node* predecessor = NULL;

    while(root){
        if(key <= root->data){
            root = root->left;
        }
        else{
            predecessor = root; 
            root = root->right;
        }
    }
    return predecessor;
}

int main(){
    int arr[] = {9,5,7,6,8,4,2,3};
    node* root = NULL;

    for(int i = 0; i < 8; i++){
        root = insert(root, arr[i]);
    }

    cout << "In-order Traversal: ";
    inorder(root);
    cout << endl;

    int key;
    cout << "Enter key to find In-order Predecessor: ";
    cin >> key;

    node* pred = inorderPredecessor(root, key);

    if(pred)
        cout << "In-order Predecessor of " << key << " is: " << pred->data << endl;
    else
        cout << "No predecessor exists!" << endl;

    return 0;
}
