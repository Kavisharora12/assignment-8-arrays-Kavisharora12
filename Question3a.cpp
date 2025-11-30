//Insert an element
//In-order predecessor of a given node the BST
#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node*left,*right;
    node(int val){
        data= val;
        left= right= NULL;
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
int main(){
    int arr[] ={9,5,7,6,8,4,2,3};
    node*root = NULL;
    for(int i =0; i<6; i++){
        root = insert(root , arr[i]);
    }
    inorder(root);
    cout<<endl;
    
}
