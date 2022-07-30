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

int maxPathSumUtil(node* root,int &ans){
    if(root==NULL){
        return 0;

    }

    int left =maxPathSumUtil(root->left, ans);
    int right = maxPathSumUtil(root->right,ans);

    int nodemax=max(max(root->data, root->data+left+right),
                       max(root->data+left,root->data+right));

    ans=max(ans,nodemax);
    int singlepathsum = max(root->data,max(root->data+left,root->data+right));
    return singlepathsum;
}

int maxpathsum(node* root){
    int ans = INT_MIN;
    maxPathSumUtil(root, ans);
    return ans;

}

int main(){//we connect root to its left and left to its left and left to its right and so on...
    
    node* root =new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->right->left=new node(5);
    root->right->right=new node(6); 
    root->right->left->left= new node(7);

    cout<<maxpathsum(root)<<endl;
    return 0;
}