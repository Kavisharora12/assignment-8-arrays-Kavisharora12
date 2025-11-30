//Traversal in Binary Tree (Preorder) Time Complexity: O(n)
#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *left, *right;
    Node(int value){
        left = right = NULL;
        data = value;
    }
};
void preOrder(Node *root){
    if(root==NULL)
    return;
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}
Node *binaryTree(){
    int x;
    cin>>x;
    if(x==-1)
    return NULL;

    Node *temp = new Node(x);
    //left side create
    cout<<"Enter the Left cild of "<<x<<" :";
    temp->left = binaryTree();
    //Right side create
    cout<<"Enter the right child "<<x<<" :";
    temp->right = binaryTree();
    return temp;
}
int main(){
    cout<<"Enter the root node: ";
    Node *root;
    root = binaryTree();
    cout<<"Preorder Traversal: ";
    preOrder(root);
    return 0;
}
