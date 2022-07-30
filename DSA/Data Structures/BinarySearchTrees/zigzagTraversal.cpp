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
void zigzag(node* root){

    if(root==NULL){
        return;
    }
    stack<node*> curr, next;

    bool leftToRight=true;
    curr.push(root);

    while(!curr.empty()){
        node* temp=curr.top();
        curr.pop();

        if(temp!=NULL){
            cout<<temp->data<<" ";
        

        if(leftToRight){
            if(temp->left){
                next.push(temp->left);
            }
            if(temp->right){
                next.push(temp->right);
            }
        }
        else{
            if(temp->right){
                next.push(temp->right);
            }
            if(temp->left){
                next.push(temp->left);
            }
        }
        }
        if(curr.empty()){
            leftToRight=!leftToRight;
            swap(curr,next);
        }
    }
}


int main(){
    node* root= new node(12);
    root->left = new node(9);
    root->right= new node(15);
    root->left->left=new node(5);
    root->left->right=new node(10);
    zigzag(root);
    return 0;

}