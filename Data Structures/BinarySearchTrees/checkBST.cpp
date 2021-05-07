#include <bits/stdc++.h>
using namespace std;


class node{//make a node class for connecting each node to each other
    public:
    int data;
    node* left;
    node* right;

    node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

node* insertBST(node* root, int val){
    if(root==NULL){
        return new node(val);
    }

    if(val < root->data){
        root->left=insertBST(root->left, val);
    }
    else{
        root->right=insertBST(root->right, val);
    }
    return root;
}


bool isBST(node* root,node* min=NULL,node* max=NULL){

    if(root==NULL){
        return true;
    }

    if(min != NULL && root->data <= min->data){
        return false;
    }

    if(max != NULL && root->data >= max->data){
        return false;
    }

    bool leftvalid = isBST(root->left, min, root);
    bool rightvalid= isBST(root->right,root, max);

    return leftvalid and rightvalid;
}

    void Inorder(node* &root){//traverse in inorder style
        if(root==NULL)
        return;

        Inorder(root->left);
        cout<<root->data<<" ";
        Inorder(root->right);
    }


int main(){//we connect root to its left and left to its left and left to its right and so on...
    node* root =NULL;
    root = insertBST(root,5);
    root=insertBST(root,1);
    root=insertBST(root,3);
    root=insertBST(root,4);
    root=insertBST(root,2);
    if(isBST(root,NULL,NULL)){
        cout<<"valid BST"<<endl;
    }
    else{
        cout<<" invalid BST"<<endl;
    }
    node* root1= new node(1);
    root1->left = new node(2);
    root1->right =new node(3);
    if(isBST(root1,NULL,NULL)){
        cout<<"valid BST"<<endl;
    }
    else{
        cout<<" invalid BST"<<endl;
    }
    
    return 0;
}