#include <bits/stdc++.h>
using namespace std;


class node{//we have to create node class to create nodes to connect
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

int search(int inorder[],int start,int end,int curr){//this function searches the element of preorder in inorder segment
    for(int i=start;i<=end;i++){
        if(inorder[i]==curr){
            return i;//returning the position
        }
    }
    return -1;//if there is no such element
}

//we are uing recursion for building the tree
node* buildTree(int preorder[], int inorder[],int start,int end){//we get two arrays and the start and end of inorder
    static int index=0;//we set the index of element in preorder
    if(start>end){//base case 
        return NULL;
    }
    int curr = preorder[index];//we get the current element in the index of preorder
    index++;
    node* Node = new node(curr);//we made a node for the current element
    
    if(start==end){//if the end and start meets the we return the node itself because we have no other stuff to do
        return Node;
    }
  
    int pos=search(inorder,start,end,curr);//we search the element in the inorder array
    Node->left=buildTree(preorder,inorder,start,pos-1);//if found in the left part then this happens
    Node->right=buildTree(preorder,inorder,pos+1,end);//if found on the right part then this happens

    return Node;
}

void Inorder(node* root){//we output the inorder pattern to check if we really did build the tree
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