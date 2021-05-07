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
 node* balancedBST(int arr[],int start, int end){

     if(start>end){
         return NULL;
     }

     int mid = (start+end)/2;
     node* root = new node(arr[mid]);

     root->left = balancedBST(arr, start,mid-1);
     root->right = balancedBST(arr, mid+1,end);

     return root;
 }

    void Preorder(node* &root){//traverse in prorder style
        if(root==NULL)
        return;

        cout<<root->data<<" ";
        Preorder(root->left);
        Preorder(root->right);
    }


int main(){
    int arr[]={10,20,30,40,50};
    node* root = balancedBST(arr,0,4);

    Preorder(root);

    return 0;
}