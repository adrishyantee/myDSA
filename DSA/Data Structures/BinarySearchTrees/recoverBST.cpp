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


void calcPointers(node* root, node** first, node** mid, node** last, node** prev){
    if(root==NULL){
        return;
    }

    calcPointers(root->left,first,mid,last,prev);

    if(*prev && root->data < (*prev)->data){
        if(!*first){
            *first = *prev;
            *mid = root;
        }
        else{
            *last = root;
        }
    }
    *prev=root;
    calcPointers(root->right,first,mid,last,prev);
}


void swap(int *a, int *b){
    int temp =*a;
    *a=*b;
    *b=temp;
}

void restoreBST(node* root){
    node* first=NULL;
    node* mid = NULL;
    node* last=NULL;
    node* prev=NULL;

    calcPointers(root, &first, &mid, &last, &prev);

    if(first && last){
        swap(&(first->data), &(last->data));
    }
    else if(first && mid){
        swap(&(first->data), &(mid->data));
    }
}
    void Inorder(node* &root){//traverse in inorder style
        if(root==NULL)
        return;

        Inorder(root->left);
        cout<<root->data<<" ";
        Inorder(root->right);
    }

int main(){

    node* root=new node(6);
    root->left = new node(9);
    root->right=new node(3);
    root->left->left=new node(1);
    root->left->right=new node(4);
    root->right->right=new node(13);

    Inorder(root);
    cout<<endl;
    restoreBST(root);
    Inorder(root);
    cout<<endl;
    return 0;
}