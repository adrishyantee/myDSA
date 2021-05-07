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


vector<node*> constructTrees(int start, int end){
    vector<node*> trees;
    if(start>end){
        trees.push_back(NULL);
        return trees;
    }
    for(int i=start;i<=end;i++){
        vector<node*> leftsubtrees = constructTrees(start, i-1);
        vector<node*> rightsubtrees = constructTrees(i+1, end);

        for(int j=0;j<leftsubtrees.size();j++){
            node* left = leftsubtrees[j];
        for(int k=0;k<rightsubtrees.size();k++){
            node* right = rightsubtrees[k];
            node* temp = new node(i);
            temp->left = left;
            temp->right= right;
            trees.push_back(temp);
        }
        }
    }
    return trees;
}

    void Preorder(node* &root){//traverse in prorder style
        if(root==NULL)
        return;

        cout<<root->data<<" ";
        Preorder(root->left);
        Preorder(root->right);
    }


int main(){

    vector<node*> roots=constructTrees(1,3);
    for(int i=0;i<roots.size();i++){
    cout<<(i+1)<<":";
    Preorder(roots[i]);
    cout<<endl;
    }
    return 0;
}