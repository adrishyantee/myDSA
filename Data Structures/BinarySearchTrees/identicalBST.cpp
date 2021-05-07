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

bool isIdentical(node* root1, node* root2){
    if(root1==NULL && root2==NULL)
    return true;

    else if( root1== NULL|| root2==NULL)
    return false;

    else{
        bool cond1=root1->data ==root2->data;
        bool cond2= isIdentical(root1->left,root2->left);
        bool cond3= isIdentical(root1->right,root2->right);

        return (cond1&& cond2 && cond3);
    }
}

    int main(){//we connect root to its left and left to its left and lrft to its right and so on...
    node* root1 =new node(2);
    root1->left=new node(1);
    root1->right=new node(3);

    node* root2 =new node(2);
    root2->left=new node(1);
    root2->right=new node(3);

    node* root3 =new node(2);
    root3->left=new node(0);
    root3->right=new node(3);

    if(isIdentical(root1,root2))
    cout<<"BST are Identical"<<endl;
    else
    cout<<"BST are not Identical"<<endl;

    if(isIdentical(root1,root3))
    cout<<"BST are Identical"<<endl;
    else
    cout<<"BST are not Identical"<<endl;
    return 0;
}