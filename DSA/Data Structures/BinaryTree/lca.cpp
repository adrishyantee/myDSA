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

//finding the lowest common ancestor
node* LCA(node* root, int n1, int n2){
    if(root == NULL){
        return NULL;
    }
    if(root->data == n1 || root->data == n2){
        return root;
    }
    node* left =LCA(root->left,n1,n2);
    node* right =LCA(root->right,n1,n2);

//the edge cases
    if(left != NULL && right != NULL){
        return root;
    }
    
    if(left != NULL){
        return left;
    }
    return right;
}


int main(){//we connect root to its left and left to its left and left to its right and so on...
    
    node* root =new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->right->left=new node(5);
    root->right->right=new node(6); 
    root->right->left->left= new node(7);
    node* temp=LCA(root, 6,7);
    cout<<temp->data<<endl;  
    return 0;
}