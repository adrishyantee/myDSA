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



int main(){//we connect root to its left and left to its left and lrft to its right and so on...
    node* root =new node(1);
    root->left=new node(2);
    root->right=new node(3);
    return 0;
}