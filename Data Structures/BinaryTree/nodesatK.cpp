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

void subtreenodes(node* root, int k){

    if(root==NULL || k<0)
    return;

    if(k==0){
        cout<<root->data<<" ";
        return;
    }

    subtreenodes(root->left, k-1);
    subtreenodes(root->right, k-1);
}

int nodesatk(node* root, node* target,int k){
    if(root==NULL){
        return -1;
    }

    if(root==target){
        subtreenodes(root,k);
        return 0;
    }

    int dl=nodesatk(root->left,target, k);
    if(dl!=-1){
       if(dl+1==k){
       cout<<root->data<<" ";
       }
       else{
           subtreenodes(root->right, k-dl-2);
       }
       return dl+1;
    }


    int dr=nodesatk(root->right, target, k);
    if(dr!=-1){
       if(dr+1==k){
       cout<<root->data<<" ";
       }
       else{
           subtreenodes(root->left, k-dr-2);
       }
       return dr+1;
    
    }

    return -1;

}


int main(){
    node* root = new node(1);
    root->right = new node(2);
    root->right->left = new node(3);
    root->right->right=new node(4);
    root->right->right->left = new node(5);

    nodesatk(root,root->right->left,2);


    return 0;
}