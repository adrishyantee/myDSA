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
 void flatten(node* root){
     if(root==NULL || (root->left ==NULL && root->right ==NULL))
     return;


     if(root->left!=NULL){
     flatten(root->left);

     node* temp=root->right;
     root->right=root->left;
     root->left=NULL;

     node* t= root->right;
     while(t->right!=NULL){
         t=t->right;
     }

     t->right=temp;
     }

     flatten(root->right);
 }


    void Inorder(node* &root){//traverse in inorder style
        if(root==NULL)
        return;

        Inorder(root->left);
        cout<<root->data<<" ";
        Inorder(root->right);
    }

int main(){
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);

    flatten(root);
    Inorder(root);

    return 0;
}