#include <bits/stdc++.h>
using namespace std;


class node{//we create a node class

    public:
    int data;
    node* left;
    node* right;

    node(int val){//we define a constructor so that we can set the default values.
        data=val;
        left=NULL;
        right=NULL;
    }
};

    void Preorder(node* &root){//traverse in prorder style
        if(root==NULL)
        return;

        cout<<root->data<<" ";
        Preorder(root->left);
        Preorder(root->right);
    }

    void Inorder(node* &root){//traverse in inorder style
        if(root==NULL)
        return;

        Inorder(root->left);
        cout<<root->data<<" ";
        Inorder(root->right);
    }

    void Postorder(node* &root){//traverse in post order style
        if(root==NULL)
        return;

        Postorder(root->left);
        Postorder(root->right);
        cout<<root->data<<" ";
    }




int main(){
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);

    Preorder(root);
    Inorder(root);
    Postorder(root);

    return 0;
}