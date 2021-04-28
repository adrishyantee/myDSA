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

bool isbalanced(node* root){

    if(root==NULL){
        return true;
    }

    if(isbalanced(root->left)==false){
        return false;
    }
    if(isbalanced(root->right)==false){
    return false;
    }

    int lh = height(root->left);
    int rh = height(root->right);
    if(abs(lh-rh)<=1)
    return true;
    else
    return false;
}

//optimised solution 
bool isbalanced2(node* root, int* height){

    if(root==NULL){
        return true;
    }

    int lh=0, rh =0;
    if(isbalanced2(root->left, &lh)==false){
        return false;
    }
    if(isbalanced2(root->right, &rh)==false){
    return false;
    }

    *height = max(lh,rh)+1;

    if(abs(lh-rh)<=1)
    return true;
    else
    return false;
}



int main(){//we connect root to its left and left to its left and lrft to its right and so on...
    node* root =new node(1);
    root->left=new node(2);
    root->right=new node(3);
    int height=0;

    cout<<(isbalanced(root)?"Balanced":"Unbalanced")<<endl;
    cout<<(isbalanced2(root, &height)?"Balanced":"Unbalanced")<<endl;

    node* root2=new node(1);
    root2->left=new node(2);
    root2->left->left=new node(3);
    root2->left->left->left=new node(4);
    
    cout<<(isbalanced(root2)?"Balanced":"Unbalanced")<<endl;
    cout<<(isbalanced2(root2, &height)?"Balanced":"Unbalanced")<<endl;

    return 0;
}