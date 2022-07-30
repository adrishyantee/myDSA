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
    insertBST(root,1);
    insertBST(root,3);
    insertBST(root,4);
    insertBST(root,2);

    Inorder(root);
    return 0;
}