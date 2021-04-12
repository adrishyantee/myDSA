#include <bits/stdc++.h>
using namespace std;


class node{
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

int search(int inorder[],int start,int end,int curr){
    for(int i=start;i<=end;i++){
        if(inorder[i]==curr){
            return i;
        }
    }
    return -1;
}

node* buildTree(int preorder[], int inorder[],int start,int end){
    static int index=0;
    if(start>end){
        return NULL;
    }
    int curr = preorder[index];
    index++;
    node* Node = new node(curr);
    
    if(start==end){
        return Node;
    }
  
    int pos=search(inorder,start,end,curr);
    Node->left=buildTree(preorder,inorder,start,pos-1);
    Node->right=buildTree(preorder,inorder,pos+1,end);

    return Node;
}

void Inorder(node* root){
        if(root==NULL)
        return;

        Inorder(root->left);
        cout<<root->data<<" ";
        Inorder(root->right);
    }



int main(){
    int preorder[]={1,2,4,3,5};
    int inorder[]={4,2,1,5,3};

    Inorder(buildTree(preorder,inorder,0,4));

return 0;
}