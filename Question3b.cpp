//Delete an existing element,
#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};
Node* insert(Node *root, int key){
    if(root==NULL){
        return new Node(key);
    }
    if(key < root->data){
        root->left = insert(root->left, key);
    }
    else{   
        root->right = insert(root->right, key);
    }
    return root;
}
/*bool search(Node *root, int key){
    if(root==NULL)
    return false;
    if(root->data == key)
    return true;
    if(key < root->data)
    return search(root->left, key);
    else
    return search(root->right, key);
}*/

void inOrder(Node *root){
    if(root==NULL)
    return;
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}
Node* deLete(Node *root , int key )
{
    if(!root)
    return NULL;
    if (root->data>key)
    {
        root->left = deLete(root->left,key);
        return root;
    }
    else if(root->data<key)
    {
        root->right = deLete(root->right,key);
        return root;
        
    }
    else{
        //leaf node  
        if (!root->left&&!root->right){
            delete root;
            return NULL;

        }
        else if(!root->right){
            Node *temp = root->left;
            delete root;
            return temp;

        }
        else if(!root->left){
            Node*temp= root->right;

            delete root;
            return temp;   
        }
        else{
            Node* child = root->left;
            Node* parent = root;
            // right most node
            while(child->right==NULL){
                parent = child;
                child= child->right;
            }
            if(root!=parent){
                parent->right= child->left;
                child->left= root->left;
                child->right= root->right;
                delete root;
                return child;

            }
            else{
                child->right= root->right;
                delete root;
                return child;

            }
        }
    }
    
}
int main(){
    int arr[] = {3,7,4,1,6,8};
    Node *root = NULL;
    for(int i=0; i<6; i++)
    root = insert(root, arr[i]);
    cout<<endl;
    cout<<"Inorder Traversal: ";
    inOrder(root);
    cout<<endl;
    root = deLete(root ,4);
    cout<<"Inorder Traversal: ";
    inOrder(root);
    return 0;
};       