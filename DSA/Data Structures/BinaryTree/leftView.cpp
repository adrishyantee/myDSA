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

void leftView(node* root){
    if(root == NULL){
        return;
    }

    queue<node*> q;
    q.push(root);


    while(!q.empty()){
        int  n=q.size();

        for(int i=0;i<n;i++){

        node* node=q.front();
        q.pop();

        if(i == 0){
            cout<<node->data<<" ";
        }

        if(node->left!=NULL)
        q.push(node->left);

        if(node->right!=NULL)
        q.push(node->right);

        }
    }

}


int main(){//we connect root to its left and left to its left and left to its right and so on...
    node* root =new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->right->left=new node(6);
    root->left->right=new node(5);
    root->right->right=new node(7);
    leftView(root);
    return 0;
}