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

node* constructBST(int preorder[],int* preorderIdx,int min, int max,int key,int n){
    if(*preorderIdx >=n )
    return NULL;

    node* root=NULL;

    if(key >min && key < max){
        root=new node(key);
        *preorderIdx = *preorderIdx +1;
    
    if(*preorderIdx < n){
        root->left = constructBST(preorder, preorderIdx,min, key,preorder[*preorderIdx],n);
    }
    if(*preorderIdx < n){
        root->right = constructBST(preorder, preorderIdx, key, max,preorder[*preorderIdx],n);

    }
    }
    return root;
}
    void Preorder(node* &root){//traverse in prorder style
        if(root==NULL)
        return;

        cout<<root->data<<" ";
        Preorder(root->left);
        Preorder(root->right);
    }

int main(){//we connect root to its left and left to its left and left to its right and so on...
    node* root =NULL;
    int preorder[]={10,2,1,13,11};
    int n=5;
    int preorderIdx = 0;
    root=constructBST(preorder,&preorderIdx,INT_MIN,INT_MAX,preorder[0],n);
    Preorder(root);
    return 0;
} 