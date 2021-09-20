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

int height(node* root){
    if(root==NULL){
        return 0;
    }
    int lheight = height(root->left);
    int rheight = height(root->right);
    return max(lheight,rheight)+1;
}
    bool isBalanced(node* root) {
        if(root==NULL)
            return true;
        
        if(!isBalanced(root->left))
            return false;
        if(!isBalanced(root->right))
            return false;
        
        int lh=height(root->left);
        int rh=height(root->right);
        
        return (abs(lh-rh) <= 1);

    }

//timecomplexity of this is O(N2)



int main(){//we connect root to its left and left to its left and lrft to its right and so on...
    node* root =new node(1);
    root->left=new node(2);
    root->right=new node(3);
    cout<<height(root)-1;
    return 0;
}