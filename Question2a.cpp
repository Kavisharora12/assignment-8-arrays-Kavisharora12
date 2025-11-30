#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node*left,*right;
    
    node(int val){
        data = val;
        left = right = NULL;
    }

};
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
     bool search(node*root , int item){
        if(!root)
        return 0;
        
        if(root->data==item)
        return 1;
        
        if(root->data>item){
        return search(root->left, item);
        }
        else if(root->data<item)
        return search(root->right, item);}

int main(){
    int arr[]= {2,3,4,5,6,1,7,8};
    node *root =NULL;
    for(int i =0; i<8; i++){
        root = insert(root , arr[i]);
    }
    inorder(root);
    cout<<endl;
    cout<<search(root,7)<<endl;
    
};