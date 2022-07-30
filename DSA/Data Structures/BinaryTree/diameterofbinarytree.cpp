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

int diameter(node* root){
    if(root== NULL){
        return 0;
    }
    int lheight = height(root->left);
    int rheight = height(root->right);
    int currdiameter = lheight + rheight + 1;

    int ldiameter = diameter(root->left);
    int rdiameter = diameter(root->right);

    return max(currdiameter,max(ldiameter,rdiameter));
}


//more optimised way using pointers

int diameter2(node* root, int* height){

    if(root== NULL){
        return 0;
    }
    int lh=0, rh =0;
    int ldiameter = diameter2(root->left, &lh);
    int rdiameter = diameter2(root->right , &rh);
    int currdiameter = lh + rh + 1;

    *height = max(lh,rh)+1;
      
    return max(currdiameter,max(ldiameter,rdiameter));

}

//another approach
int diameter3(node* root, int& diameter){

    if(root== NULL){
        return 0;
    }
    int lh = diameter3(root->left, diameter);
    int rh = diameter3(root->right , diameter);
    diameter=max(diameter, lh+rh);
    return max(lh,rh)+1;
}



int main(){//we connect root to its left and left to its left and lrft to its right and so on...
    node* root =new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->right->left=new node(6);
    root->left->right=new node(5);
    root->right->right=new node(7);
    cout<<diameter(root)<<endl;
    int height = 0;
    cout<<diameter2(root , &height)<<endl;
    return 0;
}