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

int sumAtK(node* root, int K){
    if(root == NULL)
    return -1;

    queue<node*> q;
    q.push(root);
    q.push(NULL);
    int level=0,sum=0;

    while(!q.empty()){
        node* node=q.front();
        q.pop();

        if(node!=NULL){
            if(level==K){
                sum+=node->data;
            }
            if(node->left)
            q.push(node->left);
            if(node->right)
            q.push(node->right);
        }
        else if(!q.empty()){
            q.push(NULL);
            level++;
        }
    }
    return sum;
}



int main(){//we connect root to its left and left to its left and lrft to its right and so on...
    node* root =new node(1);
    root->left=new node(2);
    root->right=new node(3);
    cout<<sumAtK(root,1);
    return 0;
}