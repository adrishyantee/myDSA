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

//finding the lowest common ancestor
node* LCA(node* root, int n1, int n2){
    if(root == NULL){
        return NULL;
    }
    if(root->data == n1 || root->data == n2){
        return root;
    }
    node* left =LCA(root->left,n1,n2);
    node* right =LCA(root->right,n1,n2);

//the edge cases
    if(left != NULL && right != NULL){
        return root;
    }
    if(left == NULL && right == NULL){
        return root;
    }
    if(left != NULL){
        return LCA(root->left,n1,n2);
    }
    return LCA(root->right,n1,n2);
}
//another way
    node *lca(node *root, int v1,int v2) {
    //Decide if you have to call rekursively
    //Samller than both
    if(root->data < v1 && root->data < v2){
        return lca(root->right,v1,v2);
    }
    //Bigger than both
    if(root->data > v1 && root->data > v2){
        return lca(root->left,v1,v2);
    }
    }


//finding distance between two nodes from the lca and adding
int findDist(node* root, int k, int dist){
    if(root==NULL){
        return -1;
    }
    if(root->data == k){
        return dist;
    }

    int left=findDist(root->left, k, dist+1);
    if(left != -1){
        return left;
    }
    
   return findDist(root->right, k, dist+1);
}


int distBtwNodes(node* root,int n1, int n2){
    node* lca=LCA(root, n1 ,n1);

    int d1 = findDist(lca, n1, 0);
    int d2 = findDist(lca, n2, 0);
    return d1+d2;
}


int main(){//we connect root to its left and left to its left and left to its right and so on...
    node* root =new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->right->left=new node(6);
    root->left->right=new node(5);
    root->right->right=new node(7); 
    cout<<distBtwNodes(root,4,7); 
    return 0;
}