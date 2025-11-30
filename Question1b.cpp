//Inorder Traversal of a Binary Tree
#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node*left, *right;
    Node(int value){
        left = right = NULL;
        data = value;
    }
};
void inOrder(Node *root){
    if(root==NULL)
    return;
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
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
    cout<<"Inorder Traversal: ";
    inOrder(root);
    return 0;
}