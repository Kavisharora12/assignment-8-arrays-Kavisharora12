//Maximum element of the BST
#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node*left, *right;
    node(int val){
        data = val;
        left = right = NULL;
    }
};
int MinValue(node*root){
    if(!root)
    return -1;
    while(root->left!=NULL){
        root = root->left;
    }
    cout<<root->data<<endl;


}

 void inorder(node *root){
    if(!root)
    return;

    //left side
    inorder(root->left);
    //node
    cout<<root->data<<" ";
    //Right side
    inorder(root->right);

}
   node *insert(node*root, int target){
        if(!root){
            node *temp = new node(target);
            return temp;
        }
        if(target<root->data){
            root->left = insert(root->left,target);
        }
        if(target>root->data){
            root->right = insert(root->right, target);
        }
        return root;
        
    }
int main(){
    int arr[] = {9,4,6,5,2,8};
    node *root =NULL;
    for(int i =0; i<6; i++){
        root = insert(root , arr[i]);
    }
    inorder(root);
    cout<<endl;
    cout<<"The Min element in the BST :"<<endl;
    MinValue(root);
}