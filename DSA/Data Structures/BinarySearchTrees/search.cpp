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

node* searchInBST(node* root, int key){
    if(root == NULL){
        return NULL;
    }
    if(root->data == key){
        return root;
    }
    if(root->data > key){
        return searchInBST(root->left,key);
    }

    return searchInBST(root->right, key);
}

int main(){//we connect root to its left and left to its left and left to its right and so on...
    node* root =NULL;
    root = insertBST(root,5);
    insertBST(root,1);
    insertBST(root,3);
    insertBST(root,4);
    insertBST(root,2);

    node* temp=searchInBST(root,4);
    if(temp!=NULL)
    cout<<"FOUND"<<endl;
    else
    cout<<"NOT FOUND"<<endl;
    return 0;
}